
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, r = 1, i, j;
    int *L;

    scanf ( "%d", &n );
    L = ( int * ) malloc ( n * sizeof ( int ) );

    for ( i = 0; i < n; i++ ) {
        scanf ( "%d", &n );
        for ( j = 0; j < n; j++ ) {
            L [ i ] = r;
            r++;
        }
    }

    scanf ( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf ( "%d", &j );
        printf ( "%d\n", L [ j - 1 ] );
    }

    return 0;
}

