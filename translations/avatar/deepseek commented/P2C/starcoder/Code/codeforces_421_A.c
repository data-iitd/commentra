
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, a, b, k ;
    scanf ( "%d %d %d", &n, &a, &b ) ;
    int * lista = ( int * ) malloc ( n * sizeof ( int ) ) ;
    int * listb = ( int * ) malloc ( n * sizeof ( int ) ) ;
    for ( k = 0 ; k < n ; k ++ ) {
        scanf ( "%d", &lista [ k ] ) ;
    }
    for ( k = 0 ; k < n ; k ++ ) {
        scanf ( "%d", &listb [ k ] ) ;
    }
    for ( k = 0 ; k < n ; k ++ ) {
        if ( k + 1 == lista [ k ] ) {
            printf ( "1 " ) ;
        } else {
            printf ( "2 " ) ;
        }
    }
    printf ( "