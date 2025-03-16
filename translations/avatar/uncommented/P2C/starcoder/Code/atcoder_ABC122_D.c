#include <stdio.h>
#include <string.h>
#define mod 1000000007
int ok ( char last4 [ 4 ] ) {
    for ( int i = 0 ; i < 4 ; i++ ) {
        char t [ 4 ] = { 0 };
        for ( int j = 0 ; j < 4 ; j++ )
            t [ j ] = last4 [ j ];
        if ( i >= 1 )
            t [ i ], t [ i - 1 ] = t [ i - 1 ], t [ i ];
        if ( strstr ( t, "AGC" ) )
            return 0;
    }
    return 1;
}
int dfs ( int cur, char last3 [ 3 ] ) {
    if ( last3 [ 0 ] == 'T' && last3 [ 1 ] == 'T' && last3 [ 2 ] == 'T' )
        return 1;
    if ( memo [ cur ] [ last3 [ 0 ] ] )
        return memo [ cur ] [ last3 [ 0 ] ];
    int ret = 0;
    for ( int i = 0 ; i < 4 ; i++ ) {
        char c = 'A' + i;
        if ( ok ( last3 + c ) )
            ret = ( ret + dfs ( cur + 1, last3 [ 1 ] + c ) ) % mod;
    }
    memo [ cur ] [ last3 [ 0 ] ] = ret;
    return ret;
}
int main ( ) {
    int n;
    scanf ( "%d", &n );
    int memo [ 100001 ][ 3 ] = { 0 };
    printf ( "%d\n", dfs ( 0, "TTT" ) );
    return 0;
}
