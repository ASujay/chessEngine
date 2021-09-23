#ifndef PAWNS_H_
#define PAWNS_H_

/* This header defines the functions and macros for the movement of the pawns */

#include "define.h"
/* Pawns attack table */

/* pawn_attacks[side][sqaure] */
extern U64 pawn_attacks[][64];

/* generate pawn attacks */
U64 mask_pawn_attacks(int sqaure, int side);
void init_pawn_attacks(void);
void print_pawn_attack_table(int side);

#endif // PAWNS_H_
