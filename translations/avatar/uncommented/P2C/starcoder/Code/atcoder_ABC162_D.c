#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
int main ( ) {
    int n;
    char s [ MAX ];
    scanf ( "%d", &n );
    scanf ( "%s", s );
    int rNum = 0, gNum = 0, bNum = 0, sum = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( s [ i ] == 'R' )
            rNum++;
        if ( s [ i ] == 'G' )
            gNum++;
        if ( s [ i ] == 'B' )
            bNum++;
    }
    for ( int step = 1 ; step <= ( n + 1 ) / 2 ; step++ ) {
        for ( int i = 0 ; i < n - 2 * step ; i++ ) {
            char s [ 3 ];
            s [ 0 ] = s [ 1 ] = s [ 2 ] = 0;
            s [ 0 ] = s [ i ];
            s [ 1 ] = s [ i + step ];
            s [ 2 ] = s [ i + step * 2 ];
            if ( strcmp ( s, "RGB" ) == 0 || strcmp ( s, "RBG" ) == 0 || strcmp ( s, "BGR" ) == 0 || strcmp ( s, "BRG" ) == 0 || strcmp ( s, "GBR" ) == 0 || strcmp ( s, "GRB" ) == 0 )
                sum++;
        }
    }
    printf ( "%d", rNum * gNum * bNum - sum );
    return 0;
}

