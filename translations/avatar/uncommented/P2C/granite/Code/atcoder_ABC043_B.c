
#include <stdio.h>
#include <string.h>

int main ( ) {
    char s [ 1000 ];
    scanf ( "%s", s );
    char my_str [ 1000 ];
    int len = strlen ( s );
    int j = 0;
    for ( int i = 0; i < len; i ++ ) {
        if ( s [ i ] == '0' || s [ i ] == '1' ) {
            my_str [ j ++ ] = s [ i ];
        } else if ( s [ i ] == 'B' && j!= 0 ) {
            j --;
        }
    }
    my_str [ j ] = '\0';
    printf ( "%s\n", my_str );
    return 0;
}
