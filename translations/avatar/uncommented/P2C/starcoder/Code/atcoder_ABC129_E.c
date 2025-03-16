#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int mod = 1000000007;
    char l [ 1000001 ];
    scanf ( "%s", l );
    int n = strlen ( l );
    int dp [ 2 ][ 2 ] = { 0 };
    dp [ 0 ] [ 0 ] = 1;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( l [ i ] == '0' ) {
            dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ];
            dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3;
        }
        else {
            dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ] * 2;
            dp [ i + 1 ] [ 1 ] += dp [ i ] [ 0 ];
            dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3;
        }
        dp [ i + 1 ] [ 0 ] %= mod;
        dp [ i + 1 ] [ 1 ] %= mod;
    }
    printf ( "%d\n", dp [ n ] [ 0 ] + dp [ n ] [ 1 ] );
    return 0;
}
