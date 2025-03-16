#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( ) {
    char *s = ( char * ) malloc ( 100 * sizeof ( char ) );
    scanf ( "%s", s );
    int len = strlen ( s );
    int even [ 2 ] = { 0 };
    int odd [ 2 ] = { 0 };
    for ( int i = 0; i < len; i++ ) {
        if ( i % 2 == 0 ) {
            if ( s [ i ] == '0' ) {
                even [ 0 ]++;
            } else {
                even [ 1 ]++;
            }
        } else {
            if ( s [ i ] == '0' ) {
                odd [ 0 ]++;
            } else {
                odd [ 1 ]++;
            }
        }
    }
    int min = len - ( even [ 0 ] + odd [ 1 ] );
    if ( min > len - ( even [ 1 ] + odd [ 0 ] ) ) {
        min = len - ( even [ 1 ] + odd [ 0 ] );
    }
    printf ( "%d", min );
    return 0;
}
