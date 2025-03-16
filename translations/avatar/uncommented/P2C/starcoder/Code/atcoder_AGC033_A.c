#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ( ) {
    int h, w;
    scanf ( "%d %d", &h, &w );
    int graph [ h ][ w ];
    for ( int i = 0 ; i < h ; i ++ ) {
        for ( int j = 0 ; j < w ; j ++ ) {
            scanf ( "%c", &graph [ i ][ j ] );
            if ( graph [ i ][ j ] == '#' ) graph [ i ][ j ] = 0;
            else graph [ i ][ j ] = 1;
        }
    }
    for ( int i = 0 ; i < w - 1 ; i ++ ) {
        for ( int j = 0 ; j < h ; j ++ ) {
            graph [ j ][ i ] = ( graph [ j ][ i ] + graph [ j ][ i + 1 ] ) / 2;
        }
    }
    for ( int i = 0 ; i < w ; i ++ ) {
        for ( int j = 0 ; j < h - 1 ; j ++ ) {
            graph [ j ][ i ] = ( graph [ j ][ i ] + graph [ j + 1 ][ i ] ) / 2;
        }
    }
    int max = 0;
    for ( int i = 0 ; i < h ; i ++ ) {
        for ( int j = 0 ; j < w ; j ++ ) {
            if ( graph [ i ][ j ] > max ) max = graph [ i ][ j ];
        }
    }
    printf ( "%d", max );
    return 0;
}
