
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int t, k, n, m, i;
    scanf ( "%d", &t );
    for ( i = 0; i < t; i++ ) {
        scanf ( "%d %d %d", &k, &n, &m );
        if ( k * m >= n ) {
            printf ( "Yes\n" );
        } else {
            printf ( "No\n" );
        }
    }
    return 0;
}

