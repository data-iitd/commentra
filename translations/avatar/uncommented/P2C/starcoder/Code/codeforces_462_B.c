#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n, k, i, j, count [ 26 ] = { 0 };
    char s [ 1000001 ];
    scanf ( "%d %d", &n, &k );
    scanf ( "%s", s );
    for ( i = 0 ; i < n ; i++ )
        count [ s [ i ] - 'A' ]++;
    for ( i = 0 ; i < 26 ; i++ )
        if ( count [ i ] >= k ) {
            printf ( "%d\n", k * k );
            return 0;
        }
    for ( i = 0 ; i < 26 ; i++ )
        for ( j = 0 ; j < count [ i ] ; j++ )
            printf ( "%c", i + 'A' );
    printf ( "\n" );
    return 0;
}
