
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, i, j, s, q, tem, a [ 1000 ], b [ 1000 ] ;
    while ( scanf ( "%d", &n ) != EOF ) {
        for ( i = 0 ; i < n ; i ++ ) {
            scanf ( "%d", &a [ i ] ) ;
            b [ i ] = 0 ;
        }
        s = - 1 ;
        q = 0 ;
        tem = 1 ;
        while ( q != n ) {
            s ++ ;
            if ( tem == 1 ) {
                for ( i = 0 ; i < n ; i ++ ) {
                    if ( a [ i ] <= q && b [ i ] == 0 ) {
                        b [ i ] = 1 ;
                        q ++ ;
                    }
                }
                tem = 0 ;
            } else {
                for ( i = n - 1 ; i >= 0 ; i -- ) {
                    if ( a [ i ] <= q && b [ i ] == 0 ) {
                        b [ i ] = 1 ;
                        q ++ ;
                    }
                }
                tem = 1 ;
            }
        }
        printf ( "%d\n", s ) ;
    }
    return 0 ;
}

