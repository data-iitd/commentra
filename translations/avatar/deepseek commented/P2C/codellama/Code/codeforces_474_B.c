
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int i, j, k, r, n, m;
    char *input, *token, *str;
    int *L;

    // Initialize an empty list L to store the results.
    L = ( int * ) malloc ( sizeof ( int ) );
    L [ 0 ] = 0;

    // Take the first input from the user.
    scanf ( "%d", &n );
    // Split the first input into a list of strings and iterate over each string.
    for ( i = 0; i < n; i++ ) {
        scanf ( "%d", &k );
        for ( j = 0; j < k; j++ ) {
            L = ( int * ) realloc ( L, ( i + 1 ) * sizeof ( int ) );
            L [ i ] = r;
            r++;
        }
    }

    // Take the second input from the user.
    scanf ( "%d", &m );
    // Split the second input into a list of strings and iterate over each string.
    for ( i = 0; i < m; i++ ) {
        scanf ( "%d", &j );
        printf ( "%d\n", L [ j - 1 ] );
    }

    free ( L );
    return 0;
}

