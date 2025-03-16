#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    char s[100000];
    int t;
    scanf ( "%d", &t );
    while ( t-- ) {
        scanf ( "%s", s );
        if ( strstr ( s, "hackerrank" ) ) printf ( "ACC\n" );
        else printf ( "WA\n" );
    }
    return 0;
}

