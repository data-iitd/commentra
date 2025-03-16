
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int *L = ( int * ) malloc ( sizeof ( int ) * 100000 ) ;
    int i, j, k, r ;
    for ( i = 0 ; i < 100000 ; i ++ ) L [ i ] = 0 ;
    scanf ( "%d", & k ) ;
    for ( i = 0 ; i < k ; i ++ ) {
        scanf ( "%d", & j ) ;
        for ( r = 1 ; r <= j ; r ++ ) L [ i * j + r - 1 ] = r ;
    }
    scanf ( "%d", & k ) ;
    for ( i = 0 ; i < k ; i ++ ) {
        scanf ( "%d", & j ) ;
        printf ( "%d\n", L [ j - 1 ] ) ;
    }
    free ( L ) ;
    return 0 ;
}
