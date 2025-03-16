
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int t, i, k, a, b, c;
    char *res;
    scanf ( "%d", &t );
    res = ( char * ) malloc ( t * 4 + 1 );
    for ( i = 0; i < t; i++ ) {
        scanf ( "%d %d %d", &a, &b, &c );
        k = a / b;
        if ( k * c >= a ) {
            res [ i * 4 ] = 'Y';
            res [ i * 4 + 1 ] = 'e';
            res [ i * 4 + 2 ] = 's';
            res [ i * 4 + 3 ] = '\n';
        } else {
            res [ i * 4 ] = 'N';
            res [ i * 4 + 1 ] = 'o';
            res [ i * 4 + 2 ] = '\n';
        }
    }
    res [ t * 4 ] = '\0';
    printf ( "%s", res );
    free ( res );
    return 0;
}

