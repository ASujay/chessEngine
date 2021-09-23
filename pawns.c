#include "pawns.h"

/* Pawn attacks */
#include "define.h"
#include <stdbool.h>

/* [side][square] */
U64 pawn_attacks[2][64];


/* these bitboards have the files reset to zero whlile the other squares set to 1 */

/*
 *
 * Not A file mask
 *
 * 8   0 1 1 1 1 1 1 1
 * 7   0 1 1 1 1 1 1 1
 * 6   0 1 1 1 1 1 1 1
 * 5   0 1 1 1 1 1 1 1
 * 4   0 1 1 1 1 1 1 1
 * 3   0 1 1 1 1 1 1 1
 * 2   0 1 1 1 1 1 1 1
 * 1   0 1 1 1 1 1 1 1

       A B C D E F G H

      Bitboard: 18374403900871474942
*/

const U64 not_a_file = 18374403900871474942ULL;
/*
 *
 * Not AB file mask
 *
 * 8   0 0 1 1 1 1 1 1
 * 7   0 0 1 1 1 1 1 1
 * 6   0 0 1 1 1 1 1 1
 * 5   0 0 1 1 1 1 1 1
 * 4   0 0 1 1 1 1 1 1
 * 3   0 0 1 1 1 1 1 1
 * 2   0 0 1 1 1 1 1 1
 * 1   0 0 1 1 1 1 1 1

       A B C D E F G H

       Bitboard: 18229723555195321596
*/
const U64 not_ab_file = 18229723555195321596ULL;

/*
 *
 * Not H file mask
 * 8   1 1 1 1 1 1 1 0
 * 7   1 1 1 1 1 1 1 0
 * 6   1 1 1 1 1 1 1 0
 * 5   1 1 1 1 1 1 1 0
 * 4   1 1 1 1 1 1 1 0
 * 3   1 1 1 1 1 1 1 0
 * 2   1 1 1 1 1 1 1 0
 * 1   1 1 1 1 1 1 1 0

       A B C D E F G H

       Bitboard: 9187201950435737471
 *
*/

const U64 not_h_file = 9187201950435737471ULL;


/*
 *
 * Not GH file mask
 * 8   1 1 1 1 1 1 0 0
 * 7   1 1 1 1 1 1 0 0
 * 6   1 1 1 1 1 1 0 0
 * 5   1 1 1 1 1 1 0 0
 * 4   1 1 1 1 1 1 0 0
 * 3   1 1 1 1 1 1 0 0
 * 2   1 1 1 1 1 1 0 0
 * 1   1 1 1 1 1 1 0 0

       A B C D E F G H

       Bitboard: 4557430888798830399
 *
*/

const U64 not_gh_file = 4557430888798830399ULL;

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
