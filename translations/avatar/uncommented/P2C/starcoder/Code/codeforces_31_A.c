#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int y, i, j, k, n;
    scanf ( "%d", & y );
    int * arr = ( int * ) malloc ( y * sizeof ( int ) );
    for ( i = 0 ; i < y ; i ++ ) {
        scanf ( "%d", & arr [ i ] );
    }
    for ( i = 0 ; i < y ; i ++ ) {
        for ( j = 0 ; j < y ; j ++ ) {
            if ( i == j ) {
                continue;
            }
            for ( k = 0 ; k < y ; k ++ ) {
                if ( arr [ k ]!= arr [ j ] && arr [ k ]!= arr [ i ] && arr [ k ] == arr [ i ] + arr [ j ] ) {
                    printf ( "%d %d %d\n", k + 1, j + 1, i + 1 );
                    exit ( );
                }
            }
        }
    }
    printf ( "-1\n" );
    return 0;
}
