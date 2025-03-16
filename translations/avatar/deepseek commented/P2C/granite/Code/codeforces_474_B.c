

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, m, i, j, k;
    int *L;
    scanf ( "%d", &n );
    // Take the first input from the user and store it in the variable n.
    L = ( int * ) malloc ( n * sizeof ( int ) );
    // Allocate memory for the list L with n elements.
    for ( i = 0; i < n; i ++ ) {
        scanf ( "%d", &m );
        // Take the next input from the user and store it in the variable m.
        for ( j = 0; j < m; j ++ ) {
            L [ i * m + j ] = i + 1;
            // Multiply the string '1' by the integer value of the string and store the result in the element at the index i * m + j of the list L.
        }
    }
    scanf ( "%d", &m );
    // Take the second input from the user and store it in the variable m.
    for ( i = 0; i < m; i ++ ) {
        scanf ( "%d", &n );
        // Take the next input from the user and store it in the variable n.
        printf ( "%d\n", L [ n - 1 ] );
        // Print the element at the index n - 1 of the list L.
    }
    free ( L );
    // Free the memory allocated for the list L.
    return 0;
}
