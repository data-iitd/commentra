
#include <stdio.h>
#include <string.h>

int main ( ) {
    char s [ 1000 ];
    char my_str [ 1000 ];
    int i;
    scanf ( "%s", s );
    for ( i = 0; i < strlen ( s ); i++ ) {
        if ( s [ i ] == '0' || s [ i ] == '1' ) {
            strcat ( my_str, &s [ i ] );
        } else if ( s [ i ] == 'B' && strlen ( my_str ) != 0 ) {
            my_str [ strlen ( my_str ) - 1 ] = '\0';
        }
    }
    printf ( "%s\n", my_str );
    return 0;
}

