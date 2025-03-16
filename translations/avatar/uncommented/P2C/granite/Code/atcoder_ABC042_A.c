
#include <stdio.h>

int main ( void ) {
    int ABC [ 3 ];
    for ( int i = 0 ; i < 3 ; i ++ ) {
        scanf ( "%d", & ABC [ i ] );
    }
    if ( ABC [ 0 ] == 5 || ABC [ 1 ] == 5 || ABC [ 2 ] == 5 ) {
        if ( ABC [ 0 ] + ABC [ 1 ] + ABC [ 2 ] == 17 ) {
            printf ( "YES\n" );
        } else {
            printf ( "NO\n" );
        }
    } else {
        printf ( "NO\n" );
    }
    return 0;
}

