#ifndef KNIGHTS_H_
#define KNIGHTS_H_

#include "define.h"

extern U64 knight_attacks[64];

/* Generate knight attacks */

U64 mask_knight_attacks(int sqaure);
void print_knight_attack_tables(void);
void init_knight_attacks(void);
#endif // KNIGHTS_H_
