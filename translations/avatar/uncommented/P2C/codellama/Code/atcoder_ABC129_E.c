#include <stdio.h>
#include <string.h>
#define mod 1000000007
int main ( ) {
    char l [ 1000000 ];
    int n, i, c, dp [ 1000000 ] [ 2 ];
    scanf ( "%s", l );
    n = strlen ( l );
    dp [ 0 ] [ 0 ] = 1;
    for ( i = 0; i < n; i++ ) {
        c = l [ i ] - '0';
        if ( c == 0 ) {
            dp [ i + 1 ] [ 0 ] = ( dp [ i ] [ 0 ] + dp [ i ] [ 1 ] * 3 ) % mod;
            dp [ i + 1 ] [ 1 ] = ( dp [ i ] [ 1 ] * 2 ) % mod;
        } else {
            dp [ i + 1 ] [ 0 ] = ( dp [ i ] [ 0 ] * 2 + dp [ i ] [ 1 ] * 3 ) % mod;
            dp [ i + 1 ] [ 1 ] = ( dp [ i ] [ 0 ] + dp [ i ] [ 1 ] * 3 ) % mod;
        }
    }
    printf ( "%d\n", ( dp [ n ] [ 0 ] + dp [ n ] [ 1 ] ) % mod );
    return 0;
}
