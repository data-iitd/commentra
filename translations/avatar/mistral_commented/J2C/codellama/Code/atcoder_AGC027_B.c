
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 2147483647

int main ( ) {
    int N ;
    long X ;
    long *x ;
    long *xsum ;
    long ans ;
    int i , j , k ;

    scanf ( "%d %ld" , &N , &X ) ;
    x = ( long * ) malloc ( N * sizeof ( long ) ) ;
    xsum = ( long * ) malloc ( N + 1 * sizeof ( long ) ) ;

    for ( i = 0 ; i < N ; i ++ ) {
        scanf ( "%ld" , &x [ i ] ) ;
        xsum [ i + 1 ] = xsum [ i ] + x [ i ] ;
    }

    ans = X * N + 5 * xsum [ N ] ;

    for ( i = 1 ; i < N ; i ++ ) {
        long cost = X * i + 5 * ( xsum [ N ] - xsum [ N - i ] ) ;
        for ( j = 5 , k = N - i ; k >= 0 ; j += 2 , k -= i ) {
            if ( cost > ans ) {
                break ;
            }
            cost += j * ( xsum [ k ] - xsum [ k - i < 0 ? 0 : k - i ] ) ;
        }
        ans = ans < cost ? ans : cost ;
    }

    printf ( "%ld\n" , ans + N * X ) ;

    free ( x ) ;
    free ( xsum ) ;

    return 0 ;
}

