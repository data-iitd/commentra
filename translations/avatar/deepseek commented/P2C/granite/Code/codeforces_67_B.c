
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, k, * M, m = 0, j, p, l ;
    scanf ( "%d %d", & n, & k ) ;
    // Taking input from the user and splitting it into two integers
    // Assigning the values to variables `n` and `k`

    M = ( int * ) malloc ( n * sizeof ( int ) ) ;
    // Dynamically allocating memory for an array of integers of size `n`
    // Storing the address of the first element of the array in the variable `M`

    for ( j = 0 ; j < n ; j ++ ) {
        scanf ( "%d", & M [ j ] ) ;
        // Taking input from the user and storing it in the array `M`
    }

    for ( j = 0 ; j < n ; j ++ ) {
        for ( p = 0 ; p < n ; p ++ ) {
            if ( 0 == M [ p ] ) {
                printf ( "%d ", p + 1 ) ;
                // If the condition is true, print the position `p + 1`
                break ;
                // Break out of the loop after printing the position
            }
        }

        for ( l = 0 ; l < p + 1 - k ; l ++ ) {
            M [ l ] -= 1 ;
            // Decreasing the elements in the array `M` from position 0 to `p - k` by 1
        }

        M [ p ] -= 1 ;
        // Decreasing the element at position `p` by 1
    }

    free ( M ) ;
    // Freeing the dynamically allocated memory

    return 0 ;
    // Returning 0 to indicate successful execution of the program
}

Translate the above C code to Java and end with comment "