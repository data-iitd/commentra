#include <stdio.h>
int main ( ) {
    int n, i, x, w [ 1000000 ] , d [ 1000000 ] , j = 0;
    scanf ( "%d" , &n );
    for ( i = 0 ; i < n ; i++ ) {
        scanf ( "%d" , &w [ i ] );
        x += w [ i ];
    }
    for ( i = 0 ; i < n ; i++ ) {
        if ( ( x - w [ i ] ) / ( n - 1 ) == w [ i ] ) {
            d [ j ] = i + 1;
            j++;
        }
    }
    printf ( "%d\n" , j );
    for ( i = 0 ; i < j ; i++ ) {
        printf ( "%d " , d [ i ] );
    }
    printf ( "\n" );
    return 0;
}
