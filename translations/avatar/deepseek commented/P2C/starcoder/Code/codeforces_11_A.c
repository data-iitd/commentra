
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, d, m, q, i;
    scanf ( "%d %d", &n, &d );
    int *x = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0 ; i < n ; i++ )
        scanf ( "%d", &x [ i ] );
    for ( i = 0 ; i < n - 1 ; i++ ) {
        if ( x [ i ] >= x [ i + 1 ] ) {
            q = ( x [ i ] - x [ i + 1 ] ) / d + 1;
            m = m + q;
            x [ i + 1 ] = x [ i + 1 ] + q * d;
        }
    }
    printf ( "%d", m );
    return 0;
}

