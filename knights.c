#include "knights.h"
#include "define.h"
/* Knight Attack tables */

U64 knight_attacks[64];

U64 mask_knight_attacks(int sqaure){
  U64 bitboard = 0ULL;
  SET_SQUARE(bitboard, sqaure);

  /* The attacks bitboard */
  U64 knight_attack = 0ULL;

  /* These are the offsets for knight moves: 17 10 15 6 */

  if((bitboard >> 17) & not_h_file)knight_attack |= bitboard >> 17;
  if((bitboard >> 15) & not_a_file)knight_attack |= bitboard >> 15;
  if((bitboard >> 10) & not_gh_file)knight_attack |= bitboard >> 10;
  if((bitboard >> 6) & not_ab_file)knight_attack |= bitboard >> 6;
  if((bitboard << 17) & not_a_file)knight_attack |= bitboard << 17;
  if((bitboard << 15) & not_h_file)knight_attack |= bitboard << 15;
  if((bitboard << 10) & not_ab_file)knight_attack |= bitboard << 10;
  if((bitboard << 6) & not_gh_file)knight_attack |= bitboard << 6;
return knight_attack;

}

void init_knight_attacks(void){
  for(int i = 0; i < 64; i++){
    knight_attacks[i] = mask_knight_attacks(i);
  }
}

void print_knight_attack_tables(void){
  for(int i = 0; i < 64; i++){
    print_bitboard(knight_attacks[i]);
  }
}
