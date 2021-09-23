#include "define.h"
#include "pawns.h"
#include "knights.h"
#include "king.h"
#include <stdint.h>

int main(void){
 
    init_pawn_attacks();
    init_knight_attacks();
    init_king_attacks();

    print_king_attack_tables();


    return 0;
}
