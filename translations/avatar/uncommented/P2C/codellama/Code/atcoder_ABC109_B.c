#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main ( ) {
    int n, i, j, k, l, m, t, u, v, w, x, y, z;
    char s[MAX], t[MAX];
    scanf ( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf ( "%s", s );
        for ( j = 0; j < n; j++ ) {
            scanf ( "%s", t );
            if ( strcmp ( s, t ) == 0 ) {
                printf ( "Yes" );
                return 0;
            }
        }
    }
    printf ( "No" );
    return 0;
}
