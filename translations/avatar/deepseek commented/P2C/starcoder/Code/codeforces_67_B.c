#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, k, m, j, p, l;
    scanf ( "%d %d", &n, &k );
    int M [ n ];
    for ( j = 0 ; j < n ; j++ ) {
        scanf ( "%d", &M [ j ] );
    }
    m = 0;
    for ( j = 0 ; j < n ; j++ ) {
        for ( p = 0 ; p < n ; p++ ) {
            if ( 0 == M [ p ] ) {
                printf ( "%d ", p + 1 );
                break;
            }
        }
        for ( l = p + 1 - k ; l < p ; l++ ) {
            M [ l ]--;
        }
        M [ p ]--;
    }
    return 0;
}
