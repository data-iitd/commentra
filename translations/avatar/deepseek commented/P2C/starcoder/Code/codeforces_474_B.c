
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int L [ ], r = 1, i, j, k, n;
    char input [ 1000 ];
    scanf ( "%s", input );
    scanf ( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf ( "%s", input );
        k = atoi ( input );
        for ( j = 0; j < k; j++ ) {
            L [ ] = r;
            r++;
        }
    }
    scanf ( "%s", input );
    for ( i = 0; i < n; i++ ) {
        scanf ( "%s", input );
        printf ( "%d\n", L [ atoi ( input ) - 1 ] );
    }
    return 0;
}

