#include <stdio.h>
#include <string.h>
int main ( ) {
    char a [ 100 ], b [ 100 ];
    scanf ( "%s %s", a, b );
    int x = strlen ( a ) > strlen ( b )? strlen ( a ) : strlen ( b );
    strcpy ( a, a.rjust ( x, '0' ) );
    strcpy ( b, b.ljust ( x, '0' ) );
    char s [ 100 ] = "";
    int c = 0;
    for ( int i = 0 ; i < x ; i ++ ) {
        int d = ( int ) b [ i ] + ( int ) a [ x - i - 1 ] + c;
        if ( d > 9 ) {
            strcat ( s, ( char * ) &d + 1 );
            c = 1;
        }
        else {
            strcat ( s, ( char * ) &d );
            c = 0;
        }
    }
    if ( c == 1 ) {
        strcat ( s, "1" );
    }
    printf ( "%s\n", s );
    return 0;
}
