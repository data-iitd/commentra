

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Initialize an empty list `L`
    int *L = ( int * ) malloc ( sizeof ( int ) );
    int L_size = 0;

    // Read the first input, which is the number of elements to add to the list
    int n;
    scanf ( "%d", &n );

    // Use a for loop to iterate through each integer in the input
    for ( int i = 0; i < n; i ++ ) {
        // Read the next integer from the input
        int k;
        scanf ( "%d", &k );

        // Add `r` elements to the list `L` with the value `r`
        for ( int j = 0; j < k; j ++ ) {
            L = ( int * ) realloc ( L, ( L_size + 1 ) * sizeof ( int ) );
            L [ L_size ++ ] = i + 1;
        }
    }

    // Read the second input, which represents the indices of the elements to print from the list
    int m;
    scanf ( "%d", &m );

    // Use another for loop to iterate through each integer in the input
    for ( int i = 0; i < m; i ++ ) {
        // Read the next integer from the input
        int j;
        scanf ( "%d", &j );

        // Print the element at the given index using the index as an offset from the beginning of the list
        printf ( "%d\n", L [ j - 1 ] );
    }

    // Free the memory allocated for the list `L`
    free ( L );

    return 0;
}
