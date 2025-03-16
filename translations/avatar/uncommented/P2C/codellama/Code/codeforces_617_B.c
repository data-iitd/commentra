#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( ) {
    char a [ 1000 ];
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    scanf ( "%s", a );
    for ( i = 0; a [ i ] != '\0'; i ++ ) {
        if ( a [ i ] == '1' ) {
            printf ( "0" );
            break;
        }
    }
    if ( a [ i ] == '\0' ) {
        for ( j = 0; a [ j ] != '\0'; j ++ ) {
            if ( a [ j ] == '0' ) {
                k ++;
            } else {
                if ( k != 0 ) {
                    printf ( "%d", k + 1 );
                    k = 0;
                }
            }
        }
        if ( k != 0 ) {
            printf ( "%d", k + 1 );
        }
    }
    printf ( "\n" );
    return 0;
}
