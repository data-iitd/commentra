#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int main ( ) {
    char s [ 1000001 ];
    int pp, na, i, cc;
    scanf ( "%s", s );
    pp = na = 0;
    for ( i = 0 ; i < strlen ( s ) ; i ++ ) {
        cc = na + s [ i ] - '0';
        na = 0;
        if ( cc <= 4 )
            pp += cc;
        else {
            if ( i == strlen ( s ) - 1 )
                pp += 1;
            else
                pp += 10 - cc;
        }
    }
    printf ( "%d", pp );
    return 0;
}

