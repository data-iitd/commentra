
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, a [ 100000 ], k, i, j ;
    scanf ( "%d", &n ) ;
    for ( i = 0 ; i < n ; i ++ )
        scanf ( "%d", &a [ i ] ) ;
    k = ( int ) ( ( double ) ( sum ( a ) ) / ( n * ( n + 1 ) / 2 ) ) ;
    a [ n ] = a [ 0 ] ;
    for ( i = 1 ; i < n ; i ++ )
        a [ i ] += a [ i - 1 ] ;
    for ( i = 0 ; i < n ; i ++ )
        if ( ( k - a [ i ] + a [ i + 1 ] ) % n )
            break ;
    if ( i == n - 1 )
        printf ( "YES\n" ) ;
    else
        printf ( "NO\n" ) ;
    return 0 ;
}

