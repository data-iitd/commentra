#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main ( ) {
    char S [ 1000001 ];
    scanf ( "%s", S );
    int c [ 26 ] = { 0 };
    for ( int i = 0 ; i < strlen ( S ) ; i++ ) {
        c [ S [ i ] - 'a' ]++;
    }
    bool found = false;
    for ( int i = 0 ; i < 26 ; i++ ) {
        if ( c [ i ] == 2 ) {
            found = true;
        }
    }
    if ( found ) {
        printf ( "Yes\n" );
    } else {
        printf ( "No\n" );
    }
    return 0;
}
