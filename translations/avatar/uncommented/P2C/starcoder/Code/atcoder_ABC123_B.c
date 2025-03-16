#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int menu [ 5 ] [ 2 ] = { 0 };
    int ans = 0;
    for ( int i = 0 ; i < 5 ; i ++ ) {
        scanf ( "%d", & menu [ i ] [ 0 ] );
        if ( menu [ i ] [ 0 ] % 10 == 0 ) {
            menu [ i ] [ 1 ] = 10;
        } else {
            menu [ i ] [ 1 ] = menu [ i ] [ 0 ] % 10;
        }
    }
    qsort ( menu, 5, sizeof ( int ), cmp );
    for ( int i = 1 ; i < 5 ; i ++ ) {
        ans += ( menu [ i ] [ 0 ] + 9 ) / 10 * 10;
    }
    ans += menu [ 0 ] [ 0 ];
    printf ( "%d\n", ans );
    return 0;
}

int cmp ( const void * a, const void * b ) {
    return ( ( ( int * ) a ) [ 1 ] - ( ( int * ) b ) [ 1 ] );
}

