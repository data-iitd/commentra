#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mod 1000000007
int main ( ) {
    char S [ 1000000 ];
    int n, i, j, k, dp [ 1000000 ] [ 13 ];
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
    for ( i = 0; i < n; i ++ ) {
        if ( i == 0 ) {
            if ( S [ i ] != '?' ) {
                dp [ i ] [ S [ i ] - '0' ] ++;
            } else {
                for ( j = 0; j < 10; j ++ ) {
                    dp [ i ] [ j ] ++;
                }
            }
        } else {
            if ( S [ i ] != '?' ) {
                for ( k = 0; k < 13; k ++ ) {
                    dp [ i ] [ ( k * 10 + S [ i ] - '0' ) % 13 ] += dp [ i - 1 ] [ k ];
                }
            } else {
                for ( j = 0; j < 10; j ++ ) {
                    for ( k = 0; k < 13; k ++ ) {
                        dp [ i ] [ ( k * 10 + j ) % 13 ] += dp [ i - 1 ] [ k ];
                    }
                }
            }
            for ( k = 0; k < 13; k ++ ) {
                dp [ i ] [ k ] %= mod;
            }
        }
    }
    printf ( "%d\n", dp [ n - 1 ] [ 5 ] );
    return 0;
}
