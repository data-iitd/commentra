#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int arr [ n ];
    for ( int i = 0 ; i < n ; i++ ) scanf ( "%d", &arr [ i ] );
    if ( arr [ 0 ] > 15 ) printf ( "%d", 15 );
    else {
        for ( int i = 1 ; i < n ; i++ ) {
            if ( arr [ i ] - arr [ i - 1 ] > 15 ) {
                printf ( "%d", arr [ i - 1 ] + 15 );
                break;
            }
        }
        else {
            if ( arr [ - 1 ] == 90 || arr [ - 1 ] + 15 >= 90 ) printf ( "%d", 90 );
            else printf ( "%d", arr [ - 1 ] + 15 );
        }
    }
    printf ( "