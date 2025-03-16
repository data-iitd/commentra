
#include <stdio.h>
#include <string.h>

int main ( ) {
    char S [ 100001 ];
    scanf ( "%s", S );
    int c [ 256 ] = { 0 };
    int l = strlen ( S );
    for ( int i = 0; i < l; i++ ) {
        c [ S [ i ] ]++;
    }
    int a = 0;
    for ( int i = 0; i < 256; i++ ) {
        if ( c [ i ] == 2 ) {
            a++;
        }
    }
    if ( a == 2 ) {
        printf ( "Yes\n" );
    } else {
        printf ( "No\n" );
    }
    return 0;
}
