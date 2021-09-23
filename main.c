#include "define.h"
#include "pawns.h"
#include <stdint.h>

int main(void){
 
    init_pawn_attacks();

    for(int i = 0; i < 64; i++){
        print_bitboard(pawn_attacks[WHITE][i]);
    }



    return 0;
}
