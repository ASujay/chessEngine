#include "king.h"



U64 king_attacks[64];


U64 mask_king_attacks(int square){
  U64 bitboard = 0ULL;
  SET_SQUARE(bitboard, square);
  U64 king_attack = 0ULL;

  if((bitboard >> 9) & not_h_file)king_attack |= bitboard >> 9;
  if((bitboard >> 7) & not_a_file)king_attack |= bitboard >> 7;
  king_attack |= bitboard >> 8;
  if((bitboard >> 1) & not_h_file)king_attack |= bitboard >> 1;

  if((bitboard << 9) & not_a_file)king_attack |= bitboard << 9;
  if((bitboard << 7) & not_h_file)king_attack |= bitboard << 7;
  king_attack |= bitboard << 8;
  if((bitboard << 1) & not_a_file)king_attack |= bitboard << 1;

  return king_attack;
}

void init_king_attacks(void){
  for(int i = 0; i < 64; i++){
    king_attacks[i] = mask_king_attacks(i);
  }
}

void print_king_attack_tables(void){
  for(int i = 0; i < 64; i++){
    printf("     Square %d\n", i);
    print_bitboard(king_attacks[i]);
  }
}
