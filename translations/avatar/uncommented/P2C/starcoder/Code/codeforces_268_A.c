#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, count = 0;
    char **q;
    scanf ( "%d", &n );
    q = ( char ** ) malloc ( n * sizeof ( char * ) );
    for ( int i = 0; i < n; i++ ) {
        q[i] = ( char * ) malloc ( 100 * sizeof ( char ) );
        scanf ( "%s", q[i] );
    }
    for ( int j = 0; j < n; j++ ) {
        for ( int k = 0; k < n; k++ ) {
            if ( k == j ) {
                continue;
            }
            if ( q[j][0] == q[k][strlen(q[k])-1] ) {
                count++;
            } else {
                continue;
            }
        }
    }
    printf ( "%d", count );
    return 0;
}
