#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    char s [ n + 1 ];
    scanf ( "%s", s );
    bool f = true;
    int i = - 1;
    for ( int v = 0; v < n; v++ ) {
        if ( s [ v ] == s [ v + 1 ] ) {
            f = false;
        }
        if ( s [ v ] == s [ v - 1 ] ) {
            f = false;
        }
        if ( s [ v ] == s [ v + 2 ] ) {
            f = false;
        }
        if ( s [ v ] == s [ v - 2 ] ) {
            f = false;
        }
        i++;
    }
    if ( f ) {
        printf ( "Yes" );
    } else {
        printf ( "No" );
    }
    return 0;
}
