#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    char s [ 1000000 ];
    scanf ( "%s", s );
    int i, j, k, c, a, max;
    char *p;
    p = strtok ( s, " " );
    while ( p != NULL ) {
        p = strtok ( NULL, " " );
    }
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            if ( s [ i ] == s [ j ] ) {
                c++;
            }
        }
        if ( c > max ) {
            max = c;
            a = i;
        }
        c = 0;
    }
    printf ( "%c", s [ a ] );
    return 0;
}
