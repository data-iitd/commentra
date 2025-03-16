

#include <stdio.h>
#include <limits.h>

int main ( ) {
    int N, i, j, k ;
    long X, ans, cost, x [ 100000 ], xsum [ 100001 ] ;
    scanf ( "%d %ld", &N, &X ) ;
    for ( i = 0 ; i < N ; i ++ ) {
        scanf ( "%ld", &x [ i ] ) ;
        xsum [ i + 1 ] = xsum [ i ] + x [ i ] ;
    }
    ans = X * N + 5 * xsum [ N ] ;
    for ( i = 1 ; i < N ; i ++ ) {
        cost = X * i + 5 * ( xsum [ N ] - xsum [ N - i ] ) ;
        for ( j = 5, k = N - i ; k >= 0 ; j += 2, k -= i ) {
            if ( cost > ans ) {
                break ;
            }
            cost += j * ( xsum [ k ] - xsum [ MAX ( k - i, 0 ) ] ) ;
        }
        ans = MIN ( ans, cost ) ;
    }
    printf ( "%ld\n", ans + N * X ) ;
    return 0 ;
}

