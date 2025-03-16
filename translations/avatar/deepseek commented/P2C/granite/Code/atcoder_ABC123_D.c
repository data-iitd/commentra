

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int x, y, z, k ;
    scanf ( "%d %d %d %d", & x, & y, & z, & k ) ;
    // Taking four integer inputs: x, y, z, and k

    int * a = ( int * ) malloc ( x * sizeof ( int ) ) ;
    // Allocating memory for array a of size x

    int * b = ( int * ) malloc ( y * sizeof ( int ) ) ;
    // Allocating memory for array b of size y

    int * c = ( int * ) malloc ( z * sizeof ( int ) ) ;
    // Allocating memory for array c of size z

    int * ab = ( int * ) malloc ( x * y * sizeof ( int ) ) ;
    // Allocating memory for array ab of size x * y

    for ( int i = 0 ; i < x ; i ++ ) {
        for ( int j = 0 ; j < y ; j ++ ) {
            scanf ( "%d", & a [ i * y + j ] ) ;
            // Reading list a of integers
        }
    }

    for ( int i = 0 ; i < x ; i ++ ) {
        for ( int j = 0 ; j < y ; j ++ ) {
            scanf ( "%d", & b [ i * y + j ] ) ;
            // Reading list b of integers
        }
    }

    for ( int i = 0 ; i < x ; i ++ ) {
        for ( int j = 0 ; j < y ; j ++ ) {
            scanf ( "%d", & c [ i * y + j ] ) ;
            // Reading list c of integers
        }
    }

    int * ab = ( int * ) malloc ( x * y * sizeof ( int ) ) ;
    // Allocating memory for array ab of size x * y

    for ( int i = 0 ; i < x ; i ++ ) {
        for ( int j = 0 ; j < y ; j ++ ) {
            ab [ i * y + j ] = a [ i * y + j ] + b [ i * y + j ] ;
            // Populating list ab with sums of elements from a and b
        }
    }

    qsort ( ab, x * y, sizeof ( int ), cmpfunc ) ;
    // Sorting list ab in descending order

    int * abc = ( int * ) malloc ( k * sizeof ( int ) ) ;
    // Allocating memory for array abc of size k

    for ( int i = 0 ; i < min ( k, x * y ) ; i ++ ) {
        for ( int j = 0 ; j < z ; j ++ ) {
            abc [ i * z + j ] = ab [ i ] + c [ j ] ;
            // Populating list abc with sums of elements from ab and c, limited by k
        }
    }

    qsort ( abc, k, sizeof ( int ), cmpfunc ) ;
    // Sorting list abc in descending order

    for ( int i = 0 ; i < k ; i ++ ) {
        printf ( "%d\n", abc [ i ] ) ;
        // Printing the first k elements of abc in descending order
    }

    free ( a ) ;
    // Freeing memory allocated for array a

    free ( b ) ;
    // Freeing memory allocated for array b

    free ( c ) ;
    // Freeing memory allocated for array c

    free ( ab ) ;
    // Freeing memory allocated for array ab

    free ( abc ) ;
    // Freeing memory allocated for array abc

    return 0 ;
}
// End of C code
