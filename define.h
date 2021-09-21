#ifndef define_h_
#define define_h_

/* This header file will define the helper macros and data types for the engine */

// library header file

#include <stdio.h>

// define the bitboard data type

#define U64 unsigned long long

// print bitboard

#define PRINT_BIT(board, bit)\
    (board) & (1ULL << bit) ? '1' : '0'

#define PRINT_BINARY_REP(board)             \
    for(int i = 0; i < 64; i++){            \
        printf("%c", PRINT_BIT(board, i));  \
    }                                       \
    printf("\n");                           \


void print_bitboard(U64 board){
    for(int rank = 1; rank <= 8; rank++){
        for(int file = 1; file <= 8; file++){
            int bit = file + (rank - 1)*8 - 1;
            printf("%c", PRINT_BIT(board, bit));
        }
        printf("\n");
    }
}

#endif