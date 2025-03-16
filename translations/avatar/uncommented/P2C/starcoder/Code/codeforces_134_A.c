#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, i, x, *w, *d;
    scanf ( "%d", &n );
    w = ( int * ) malloc ( n * sizeof ( int ) );
    d = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0 ; i < n ; i++ )
        scanf ( "%d", &w [ i ] );
    x = 0;
    for ( i = 0 ; i < n ; i++ )
        x += w [ i ];
    for ( i = 0 ; i < n ; i++ )
        if ( ( x - w [ i ] ) / ( n - 1 ) == w [ i ] )
            d [ i ] = 1;
    for ( i = 0 ; i < n ; i++ )
        if ( d [ i ] )
            printf ( "%d ", i + 1 );
    printf ( "\n" );
    return 0;
}
