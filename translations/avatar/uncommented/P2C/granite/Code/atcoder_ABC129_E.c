
#include <stdio.h>
#define MOD 100000007

int main ( ) {
    char l [ 100001 ];
    scanf ( "%s", l );
    int n = strlen ( l );
    long long dp [ 100001 ] [ 2 ] = { { 0 } };
    dp [ 0 ] [ 0 ] = 1;
    for ( int i = 0; i < n; i ++ ) {
        if ( l [ i ] == '0' ) {
            dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ];
            dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3;
        } else {
            dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ] * 2;
            dp [ i + 1 ] [ 1 ] += dp [ i ] [ 0 ];
            dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3;
        }
        dp [ i + 1 ] [ 0 ] %= MOD;
        dp [ i + 1 ] [ 1 ] %= MOD;
    }
    printf ( "%lld\n", ( dp [ n ] [ 0 ] + dp [ n ] [ 1 ] ) % MOD );
    return 0;
}
