
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int max_level;
    scanf ( "%d", & max_level );
    int x [ max_level ];
    int y [ max_level ];
    for ( int i = 0 ; i < max_level ; i ++ ) {
        scanf ( "%d", & x [ i ] );
    }
    for ( int i = 0 ; i < max_level ; i ++ ) {
        scanf ( "%d", & y [ i ] );
    }
    int z [ max_level ];
    int k = 0;
    for ( int i = 0 ; i < max_level ; i ++ ) {
        if ( x [ i ]!= 0 ) {
            z [ k ] = x [ i ];
            k += 1;
        }
    }
    for ( int i = 0 ; i < max_level ; i ++ ) {
        if ( y [ i ]!= 0 ) {
            z [ k ] = y [ i ];
            k += 1;
        }
    }
    int flag = 0;
    for ( int i = 0 ; i < max_level ; i ++ ) {
        if ( z [ i ]!= i + 1 ) {
            flag = 1;
            break;
        }
    }
    if ( flag == 0 ) {
        printf ( "I become the guy.\n" );
    } else {
        printf ( "Oh, my keyboard!\n" );
    }
    return 0;
}
