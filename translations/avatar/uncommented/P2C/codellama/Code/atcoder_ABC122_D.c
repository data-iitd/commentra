#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define mod 1000000007
int ok ( char *last4 ) {
    for ( int i = 0 ; i < 4 ; i ++ ) {
        char t [ 5 ] = { 0 };
        strcpy ( t , last4 );
        if ( i >= 1 ) {
            t [ i ] , t [ i - 1 ] = t [ i - 1 ] , t [ i ];
        }
        if ( strstr ( t , "AGC" ) != NULL ) {
            return 0;
        }
    }
    return 1;
}
int dfs ( int cur , char *last3 ) {
    if ( memo [ cur ] [ last3 ] != -1 ) {
        return memo [ cur ] [ last3 ];
    }
    if ( cur == n ) {
        return 1;
    }
    int ret = 0;
    for ( int i = 0 ; i < 4 ; i ++ ) {
        char c = "ACGT" [ i ];
        if ( ok ( last3 + c ) ) {
            ret = ( ret + dfs ( cur + 1 , last3 + 1 + c ) ) % mod;
        }
    }
    memo [ cur ] [ last3 ] = ret;
    return ret;
}
int main ( ) {
    int n;
    scanf ( "%d" , &n );
    char memo [ 100001 ] [ 4 ] = { 0 };
    memset ( memo , -1 , sizeof ( memo ) );
    printf ( "%d" , dfs ( 0 , "TTT" ) );
    return 0;
}
