#ifndef define_h_
#define define_h_

/* This header file will define the helper macros and data types for the engine */

/* Enumerations for the chess squares */

enum {
  A8, B8, C8, D8, E8, F8, G8, H8,
  A7, B7, C7, D7, E7, F7, G7, H7,
  A6, B6, C6, D6, E6, F6, G6, H6,
  A5, B5, C5, D5, E5, F5, G5, H5,
  A4, B4, C4, D4, E4, F4, G4, H4,
  A3, B3, C3, D3, E3, F3, G3, H3,
  A2, B2, C2, D2, E2, F2, G2, H2,
  A1, B1, C1, D1, E1, F1, G1, H1
};

// library header file

#include <stdio.h>

// define the bitboard data type

#define U64 unsigned long long

// print bitboard

#define SET_SQUARE(bitboard, square)            \
    (bitboard |= (1ULL << square))

#define RESET_SQUARE(bitboard, square)          \
    (bitboard &= ~(1ULL << square))

#define PRINT_BIT(board, bit)                   \
    (board) & (1ULL << bit) ? '1' : '0'

#define PRINT_BINARY_REP(board)             \
    for(int i = 0; i < 64; i++){            \
        printf("%c", PRINT_BIT(board, i));  \
    }                                       \
    printf("\n");                           \


void print_bitboard(U64 board){
    for(int rank = 1; rank <= 8; rank++){
        printf("%d   ", 8 - rank + 1);
        for(int file = 1; file <= 8; file++){
            int bit = file + (rank - 1)*8 - 1;
            printf("%c ", PRINT_BIT(board, bit));
        }
        printf("\n");
    }
    printf("\n    A B C D E F G H\n\n");
}

#endif
