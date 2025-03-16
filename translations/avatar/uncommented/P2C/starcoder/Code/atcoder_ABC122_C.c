#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
int main ( ) {
    int n, q, l, r, cumsum [ MAX ] ;
    char s [ MAX ] ;
    scanf ( "%d%d", &n, &q ) ;
    scanf ( "%s", s ) ;
    cumsum [ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cumsum [ i ] = cumsum [ i - 1 ] + ( s [ i - 1 ] == 'A' && s [ i ] == 'C' ) ;
    }
    for ( int i = 0 ; i < q ; i ++ ) {
        scanf ( "%d%d", &l, &r ) ;
        printf ( "%d\n", cumsum [ r - 1 ] - cumsum [ l - 1 ] ) ;
    }
    return 0 ;
}
