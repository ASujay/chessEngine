#include "pawns.h"

/* Pawn attacks */
#include "define.h"
#include <stdbool.h>

/* [side][square] */
U64 pawn_attacks[2][64];



U64 mask_pawn_attacks(int square, int side){
  U64 bitboard = 0ULL;


  /* Set the sqaure on which the pawn the pawn is currently */
  SET_SQUARE(bitboard, square);
  /* Attack bitboard */

  U64 attack_bitboard = 0ULL;

  /* Generate the possible attacks by the pawns */

  switch(side){
      /*
       * If we are on the A-file and we do the left diagonl attack then we have to
       * check for the h file.
       * If we are on the H-file and we do the right diagonal then we have to check for
       * a-file.
       *
        */
    case WHITE:
      if((bitboard >> 7) & not_a_file) attack_bitboard |= (bitboard >> 7);
      if((bitboard >> 9) & not_h_file) attack_bitboard |= (bitboard >> 9);
      break;
    case BLACK:
      if((bitboard << 7) & not_h_file) attack_bitboard |= (bitboard << 7);
      if((bitboard << 9) & not_a_file) attack_bitboard |= (bitboard << 9);
      break;
  }
  return attack_bitboard;
}

void init_pawn_attacks(void){
  for(int i = 0; i <= 63; i++){
    pawn_attacks[WHITE][i] = mask_pawn_attacks(i, WHITE);
    pawn_attacks[BLACK][i] = mask_pawn_attacks(i, BLACK);
  }
}

void print_pawn_attack_table(int side){
  for(int i = 0; i < 64; i++){
    print_bitboard(pawn_attacks[side][i]);
  }
}
