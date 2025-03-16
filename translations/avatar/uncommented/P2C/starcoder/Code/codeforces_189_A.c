#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ( ) {
    int length, arr [ 4 ], ans = 0, k = 0;
    scanf ( "%d", &length );
    for ( int i = 0 ; i < 4 ; i++ )
        scanf ( "%d", &arr [ i ] );
    qsort ( arr, 4, sizeof ( int ), cmpfunc );
    if ( length % arr [ 0 ] == 0 ) {
        printf ( "%d", int ( length / arr [ 0 ] ) );
        return 0;
    }
    if ( arr [ 0 ] == arr [ 1 ] ) {
        for ( int i = 0 ; i <= int ( length / arr [ 2 ] ) ; i++ ) {
            int check = length - i * arr [ 2 ];
            if ( check >= 0 && check % arr [ 0 ] == 0 ) {
                k = int ( check / arr [ 0 ] );
                ans = max ( ans, k + i );
            }
        }
    } else {
        for ( int i = 0 ; i <= int ( length / arr [ 2 ] ) ; i++ ) {
            for ( int j = 0 ; j <= int ( length / arr [ 1 ] ) ; j++ ) {
                int check = length - i * arr [ 2 ] - j * arr [ 1 ];
                if ( check >= 0 && check % arr [ 0 ] == 0 ) {
                    k = int ( check / arr [ 0 ] );
                    ans = max ( ans, k + i + j );
                }
            }
        }
    }
    printf ( "%d", ans );
    return 0;
}

int cmpfunc ( const void * a, const void * b ) {
    return ( *( int * ) a - *( int * ) b );
}

