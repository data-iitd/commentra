
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Initialize an empty list `L`
    int *L = NULL;
    // Read the first input, which is the number of elements to add to the list
    int n;
    scanf ( "%d", &n );
    // Use a for loop to iterate through each integer in the input
    for ( int i = 0; i < n; i++ ) {
        // Add `r` elements to the list `L` with the value `r`
        L = realloc ( L, ( i + 1 ) * sizeof ( int ) );
        L [ i ] = i + 1;
    }
    // Read the second input, which represents the indices of the elements to print from the list
    int m;
    scanf ( "%d", &m );
    // Use another for loop to iterate through each integer in the input
    for ( int j = 0; j < m; j++ ) {
        // Print the element at the given index using the index as an offset from the beginning of the list
        printf ( "%d\n", L [ j ] );
    }
    // Free the memory allocated for the list
    free ( L );
    return 0;
}

