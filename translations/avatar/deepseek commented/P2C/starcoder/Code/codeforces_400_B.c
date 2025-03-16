
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n, m, i, j, k, a, b, c, d;
    scanf ( "%d %d", &n, &m );
    for ( i = 0; i < n; i++ ) {
        scanf ( "%s", s );
        for ( j = 0; j < m; j++ ) {
            if ( s[j] == 'S' ) {
                a = j;
            }
            if ( s[j] == 'G' ) {
                b = j;
            }
        }
        c = a - b;
        if ( c < 0 ) {
            printf ( "-1\n" );
            return 0;
        }
    }
    printf ( "%d\n", c );
    return 0;
}

