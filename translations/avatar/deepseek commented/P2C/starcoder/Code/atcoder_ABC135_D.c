#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mod 1000000007
int main ( ) {
    int n, i, j, k, dp [ 13 ][ 13 ];
    char S [ 100001 ];
    scanf ( "%s", S );
    n = strlen ( S );
    if ( n == 1 ) {
        if ( S [ 0 ] == '5' || S [ 0 ] == '?' ) {
            printf ( "1\n" );
        } else {
            printf ( "0\n" );
        }
        return 0;
    }
    for ( i = 0 ; i < 13 ; i ++ ) {
        dp [ 0 ] [ i ] = 1;
    }
    for ( i = 1 ; i < n ; i ++ ) {
        for ( j = 0 ; j < 13 ; j ++ ) {
            dp [ i ] [ j ] = 0;
        }
        if ( S [ i ]!= '?' ) {
            for ( k = 0 ; k < 13 ; k ++ ) {
                dp [ i ] [ ( k * 10 + S [ i ] - '0' ) % 13 ] += dp [ i - 1 ] [ k ];
            }
        } else {
            for ( j = 0 ; j < 10 ; j ++ ) {
                for ( k = 0 ; k < 13 ; k ++ ) {
                    dp [ i ] [ ( k * 10 + j ) % 13 ] += dp [ i - 1 ] [ k ];
                }
            }
        }
        for ( k = 0 ; k < 13 ; k ++ ) {
            dp [ i ] [ k ] %= mod;
        }
    }
    printf ( "%d\n", dp [ n - 1 ] [ 5 ] );
    return 0;
}
