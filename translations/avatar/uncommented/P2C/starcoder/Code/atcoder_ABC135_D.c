#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mod 1000000007
int main ( ) {
    int n;
    scanf ( "%d", &n );
    char S [ 1000010 ];
    scanf ( "%s", S );
    int dp [ 1000010 ][ 13 ];
    memset ( dp, 0, sizeof ( dp ) );
    dp [ 0 ][ 5 ] = 1;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( i == 1 ) {
            if ( S [ i - 1 ]!= '?' ) {
                dp [ i ][ ( int ) ( S [ i - 1 ] ) ] = 1;
            } else {
                for ( int j = 0 ; j < 10 ; j ++ ) {
                    dp [ i ][ j ] = 1;
                }
            }
        } else {
            if ( S [ i - 1 ]!= '?' ) {
                for ( int k = 0 ; k < 13 ; k ++ ) {
                    for ( int j = 0 ; j < 10 ; j ++ ) {
                        dp [ i ][ ( k * 10 + j ) % 13 ] += dp [ i - 1 ][ k ];
                    }
                }
            } else {
                for ( int j = 0 ; j < 10 ; j ++ ) {
                    for ( int k = 0 ; k < 13 ; k ++ ) {
                        dp [ i ][ ( k * 10 + j ) % 13 ] += dp [ i - 1 ][ k ];
                    }
                }
            }
            for ( int k = 0 ; k < 13 ; k ++ ) {
                dp [ i ][ k ] %= mod;
            }
        }
    }
    printf ( "%d\n", dp [ n - 1 ][ 5 ] );
    return 0;
}
