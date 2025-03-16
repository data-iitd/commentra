#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, a [ 100000 ], k, i, j ;
    scanf ( "%d", &n ) ;
    for ( i = 0 ; i < n ; i ++ )
        scanf ( "%d", &a [ i ] ) ;
    k = ( int ) ( ( double ) ( sum ( a, n ) ) / ( n * ( n + 1 ) / 2 ) ) ;
    a [ n ] = a [ 0 ] ;
    for ( i = 1 ; i < n ; i ++ )
        a [ i ] = ( k - a [ i ] + a [ i - 1 ] ) % n ;
    for ( i = 1 ; i < n ; i ++ )
        if ( a [ i ]!= a [ i - 1 ] )
            break ;
    if ( i == n )
        printf ( "YES\n" ) ;
    else
        printf ( "NO\n" ) ;
    return 0 ;
}
