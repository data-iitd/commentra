
#include <stdio.h>

int main ( ) {
    int n, a [ 100000 ] ;
    scanf ( "%d", & n ) ;
    for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d", & a [ i ] ) ;
    if ( sum ( a ) % ( n * ( n + 1 ) / 2 ) ) {
        printf ( "NO\n" ) ;
    } else {
        int k = sum ( a ) / ( n * ( n + 1 ) / 2 ) ;
        a [ n ] = a [ 0 ] ;
        if ( sum ( [ ( k - i + j ) % n for i, j in zip ( a [ 1 : ], a ) ] ) or sum ( [ ( k - i + j ) / n >= 0 for i, j in zip ( a [ 1 : ], a ) ] )!= n ) {
            printf ( "NO\n" ) ;
        } else {
            printf ( "YES\n" ) ;
        }
    }
    return 0 ;
}
