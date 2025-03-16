#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ( ) {
    int N;
    scanf ( "%d", & N ) ;
    int m [ N ], f [ N ] ;
    for ( int i = 0 ; i < N ; i ++ ) {
        m [ i ] = 0 ;
        f [ i ] = 0 ;
    }
    for ( int i = 0 ; i < N ; i ++ ) {
        char x [ 10 ], a [ 10 ], b [ 10 ] ;
        scanf ( "%s %s %s", x, a, b ) ;
        int ai = atoi ( a ) ;
        int bi = atoi ( b ) ;
        if ( x [ 0 ] == 'M' ) {
            m [ ai ] += 2 ;
            m [ bi ] -= 2 ;
        }
        else {
            f [ ai ] += 2 ;
            f [ bi ] -= 2 ;
        }
    }
    int a = 0, b = 0, c = 0 ;
    for ( int i = 0 ; i < N ; i ++ ) {
        a += m [ i ] ;
        b += f [ i ] ;
        if ( a < b ) {
            c = a ;
        }
        else {
            c = b ;
        }
    }
    printf ( "%d", c ) ;
    return 0 ;
}
