#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main ( ) {
    int n, d, count = 0 ;
    scanf ( "%d %d", &n, &d ) ;
    int *points = ( int * ) malloc ( n * d * sizeof ( int ) ) ;
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < d ; j++ )
            scanf ( "%d", &points [ i * d + j ] ) ;
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = i + 1 ; j < n ; j++ )
            if ( ( int ) sqrt ( pow ( points [ i * d ] - points [ j * d ], 2 ) + pow ( points [ i * d + 1 ] - points [ j * d + 1 ], 2 ) ) == 0 )
                count++ ;
    printf ( "%d", count ) ;
    return 0 ;
}
