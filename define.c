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


/* these bitboards have the files reset to zero whlile the other squares set to 1 */

/*
 *
 * Not A file mask
 *
 * 8   0 1 1 1 1 1 1 1
 * 7   0 1 1 1 1 1 1 1
 * 6   0 1 1 1 1 1 1 1
 * 5   0 1 1 1 1 1 1 1
 * 4   0 1 1 1 1 1 1 1
 * 3   0 1 1 1 1 1 1 1
 * 2   0 1 1 1 1 1 1 1
 * 1   0 1 1 1 1 1 1 1

       A B C D E F G H

      Bitboard: 18374403900871474942
*/

const U64 not_a_file = 18374403900871474942ULL;
/*
 *
 * Not AB file mask
 *
 * 8   0 0 1 1 1 1 1 1
 * 7   0 0 1 1 1 1 1 1
 * 6   0 0 1 1 1 1 1 1
 * 5   0 0 1 1 1 1 1 1
 * 4   0 0 1 1 1 1 1 1
 * 3   0 0 1 1 1 1 1 1
 * 2   0 0 1 1 1 1 1 1
 * 1   0 0 1 1 1 1 1 1

       A B C D E F G H

       Bitboard: 18229723555195321596
*/
const U64 not_ab_file = 18229723555195321596ULL;

/*
 *
 * Not H file mask
 * 8   1 1 1 1 1 1 1 0
 * 7   1 1 1 1 1 1 1 0
 * 6   1 1 1 1 1 1 1 0
 * 5   1 1 1 1 1 1 1 0
 * 4   1 1 1 1 1 1 1 0
 * 3   1 1 1 1 1 1 1 0
 * 2   1 1 1 1 1 1 1 0
 * 1   1 1 1 1 1 1 1 0

       A B C D E F G H

       Bitboard: 9187201950435737471
 *
*/

const U64 not_h_file = 9187201950435737471ULL;


/*
 *
 * Not GH file mask
 * 8   1 1 1 1 1 1 0 0
 * 7   1 1 1 1 1 1 0 0
 * 6   1 1 1 1 1 1 0 0
 * 5   1 1 1 1 1 1 0 0
 * 4   1 1 1 1 1 1 0 0
 * 3   1 1 1 1 1 1 0 0
 * 2   1 1 1 1 1 1 0 0
 * 1   1 1 1 1 1 1 0 0

       A B C D E F G H

       Bitboard: 4557430888798830399
 *
*/

const U64 not_gh_file = 4557430888798830399ULL;



/*
 * NOT 1st rank mask
 * 8   1 1 1 1 1 1 1 1
 * 7   1 1 1 1 1 1 1 1
 * 6   1 1 1 1 1 1 1 1
 * 5   1 1 1 1 1 1 1 1
 * 4   1 1 1 1 1 1 1 1
 * 3   1 1 1 1 1 1 1 1
 * 2   1 1 1 1 1 1 1 1
 * 1   0 0 0 0 0 0 0 0

       A B C D E F G H

       Bitboard: 72057594037927935
 *
 */

const U64 not_1st_rank = 72057594037927935ULL;


/*
 * Not 8th rank mask
 * 8   0 0 0 0 0 0 0 0
 * 7   1 1 1 1 1 1 1 1
 * 6   1 1 1 1 1 1 1 1
 * 5   1 1 1 1 1 1 1 1
 * 4   1 1 1 1 1 1 1 1
 * 3   1 1 1 1 1 1 1 1
 * 2   1 1 1 1 1 1 1 1
 * 1   1 1 1 1 1 1 1 1

       A B C D E F G H

       Bitboard: 18446744073709551360
*/

const U64 not_8th_rank = 18446744073709551360ULL;
