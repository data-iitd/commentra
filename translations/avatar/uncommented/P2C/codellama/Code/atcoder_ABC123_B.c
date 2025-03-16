#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main ( ) {
    int menu [ 5 ] [ 2 ] , i , j , e , ans = 0;
    for ( i = 0 ; i < 5 ; i ++ ) {
        scanf ( "%d" , &menu [ i ] [ 0 ] );
        e = menu [ i ] [ 0 ] % 10;
        if ( e == 0 ) e = 10;
        menu [ i ] [ 1 ] = e;
    }
    for ( i = 0 ; i < 5 ; i ++ ) {
        for ( j = i + 1 ; j < 5 ; j ++ ) {
            if ( menu [ i ] [ 1 ] > menu [ j ] [ 1 ] ) {
                e = menu [ i ] [ 1 ];
                menu [ i ] [ 1 ] = menu [ j ] [ 1 ];
                menu [ j ] [ 1 ] = e;
                e = menu [ i ] [ 0 ];
                menu [ i ] [ 0 ] = menu [ j ] [ 0 ];
                menu [ j ] [ 0 ] = e;
            }
        }
    }
    for ( i = 1 ; i < 5 ; i ++ ) {
        ans += ( int ) ceil ( menu [ i ] [ 0 ] / 10.0 ) * 10;
    }
    printf ( "%d\n" , ans + menu [ 0 ] [ 0 ] );
    return 0;
}
