#include "define.h"

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

    printf("Bitboard: %llu\n\n", board);
}
