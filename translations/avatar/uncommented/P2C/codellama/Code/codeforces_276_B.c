
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main ( ) {
    char *s = ( char * ) malloc ( 100 * sizeof ( char ) );
    scanf ( "%s", s );
    int len = strlen ( s );
    bool x = true;
    int cnt = 0;
    int dt [ 100 ];
    for ( int i = 0; i < len; i++ ) {
        if ( dt [ s [ i ] - 'a' ] == 0 ) {
            dt [ s [ i ] - 'a' ] = 1;
        } else {
            dt [ s [ i ] - 'a' ]++;
        }
    }
    for ( int i = 0; i < 100; i++ ) {
        if ( dt [ i ] % 2 != 0 && cnt < 1 ) {
            cnt++;
        } else if ( dt [ i ] % 2 != 0 && cnt >= 1 ) {
            x = false;
            break;
        }
    }
    if ( x ) {
        printf ( "First\n" );
    } else if ( !x && len % 2 == 0 ) {
        printf ( "Second\n" );
    } else if ( !x && len % 2 != 0 ) {
        printf ( "First\n" );
    }
    return 0;
}