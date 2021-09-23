#ifndef KING_H_
#define KING_H_

#include "define.h"

extern U64 king_attacks[64];

/* Generate king attacks */

U64 mask_king_attacks(int sqaure);
void print_king_attack_tables(void);
void init_king_attacks(void);
#endif // KING_H_
