#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, k, m, j, p, l;
    scanf ( "%d %d" , &n , &k );
    int *M = ( int * ) malloc ( n * sizeof ( int ) );
    for ( j = 0 ; j < n ; j++ ) {
        scanf ( "%d" , &M [ j ] );
    }
    m = 0;
    for ( j = 0 ; j < n ; j++ ) {
        for ( p = 0 ; p < n ; p++ ) {
            if ( M [ p ] == 0 ) {
                printf ( "%d " , p + 1 );
                break;
            }
        }
        for ( l = p + 1 - k ; l < p + 1 ; l++ ) {
            M [ l ] -= 1;
        }
        M [ p ] -= 1;
    }
    free ( M );
    return 0;
}

