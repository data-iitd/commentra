
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int menu [ 5 ] [ 2 ] = { 0 };
    int i, j, ans = 0;
    for ( i = 0 ; i < 5 ; i++ ) {
        scanf ( "%d", &menu [ i ] [ 0 ] );
        menu [ i ] [ 1 ] = menu [ i ] [ 0 ] % 10;
        if ( menu [ i ] [ 1 ] == 0 )
            menu [ i ] [ 1 ] = 10;
    }
    for ( i = 1 ; i < 5 ; i++ ) {
        for ( j = 0 ; j < 2 ; j++ ) {
            ans += ceil ( menu [ i ] [ j ] / 10.0 ) * 10;
        }
    }
    printf ( "%d\n", ans + menu [ 0 ] [ 0 ] );
    return 0;
}

