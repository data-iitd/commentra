
#include <stdio.h>
#include <string.h>

int main ( ) {
    char s [ 100000 ];
    scanf ( "%s", s );
    int dt [ 256 ] = { 0 };
    int len = strlen ( s );
    for ( int i = 0 ; i < len ; i ++ ) {
        dt [ s [ i ] ] += 1;
    }
    int cnt = 0;
    for ( int i = 0 ; i < 256 ; i ++ ) {
        if ( dt [ i ] % 2!= 0 ) {
            cnt += 1;
            if ( cnt >= 2 ) {
                printf ( "Second" );
                return 0;
            }
        }
    }
    printf ( "First" );
    return 0;
}
