#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n;
    scanf ( "%d" , &n );
    int *w = ( int * ) malloc ( n * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &w [ i ] );
    }
    int c = 0;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( w [ i ] == 0 ) {
            c += w [ i ] * ( w [ i ] - 1 );
        } else {
            if ( - w [ i ] < n && w [ - w [ i ] ] ) {
                c += w [ i ] * w [ - w [ i ] ];
            }
        }
    }
    printf ( "%d\n" , c / 2 );
    free ( w );
    return 0;
}

