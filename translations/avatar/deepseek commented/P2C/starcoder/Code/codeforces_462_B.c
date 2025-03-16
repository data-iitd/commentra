
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, k;
    scanf ( "%d %d", &n, &k );
    char s [ n + 1 ];
    scanf ( "%s", s );
    int count [ 26 ] = { 0 };
    for ( int i = 0 ; i < n ; i++ ) {
        count [ s [ i ] - 'A' ]++;
    }
    for ( int i = 0 ; i < 26 ; i++ ) {
        if ( count [ i ] >= k ) {
            printf ( "%d\n", k * k );
            return 0;
        }
        k -= count [ i ];
    }
    printf ( "%d\n", k * k );
    return 0;
}

