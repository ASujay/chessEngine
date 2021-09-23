#ifndef PAWNS_H_
#define PAWNS_H_

/* This header defines the functions and macros for the movement of the pawns */

#include "define.h"
/* Pawns attack table */

/* pawn_attacks[side][sqaure] */
extern U64 pawn_attacks[2][64];

/* generate pawn attacks */
U64 mask_pawn_attacks(int sqaure, int side);

#endif // PAWNS_H_
