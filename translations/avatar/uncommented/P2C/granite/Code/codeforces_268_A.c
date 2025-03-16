
#include <stdio.h>

int main ( ) {
    int n, i, j, k, count = 0;
    char q [ 100 ] [ 100 ];
    scanf ( "%d", &n );
    for ( i = 0; i < n; i ++ ) {
        scanf ( "%s", q [ i ] );
    }
    for ( i = 0; i < n; i ++ ) {
        for ( j = 0; j < n; j ++ ) {
            if ( i == j ) {
                continue;
            }
            else if ( q [ i ] [ 0 ] == q [ j ] [ strlen ( q [ j ] ) - 1 ] ) {
                count += 1;
            }
            else {
                continue;
            }
        }
    }
    printf ( "%d", count );
    return 0;
}
