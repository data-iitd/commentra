#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main ( ) {
    char S [ 1000000 ];
    scanf ( "%s", S );
    int c [ 26 ];
    for ( int i = 0; i < 26; i++ ) {
        c [ i ] = 0;
    }
    for ( int i = 0; i < strlen ( S ); i++ ) {
        c [ S [ i ] - 'a' ]++;
    }
    bool Sa [ 26 ];
    for ( int i = 0; i < 26; i++ ) {
        Sa [ i ] = false;
    }
    int count = 0;
    for ( int i = 0; i < strlen ( S ); i++ ) {
        if ( Sa [ S [ i ] - 'a' ] == false ) {
            Sa [ S [ i ] - 'a' ] = true;
            count++;
        }
    }
    if ( count != 2 ) {
        printf ( "No\n" );
        return 0;
    }
    for ( int i = 0; i < 26; i++ ) {
        if ( c [ i ] != 2 ) {
            printf ( "No\n" );
            return 0;
        }
    }
    printf ( "Yes\n" );
    return 0;
}
