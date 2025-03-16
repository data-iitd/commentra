// Include necessary C utility libraries
#include <stdio.h>
#include <stdlib.h>

// Declare main method that takes command line arguments
int main ( int argc, char * argv [ ] ) {
    // Declare variables to store number of requests and preemptions
    int n, m ;

    // Declare variables to store request and preemption indices
    int * req, * pre ;

    // Declare variable to store answer
    int ans ;

    // Declare variable to store index of requests and preemptions
    int i, j ;

    // Read number of requests and preemptions from the standard input
    scanf ( "%d %d", & n, & m ) ;

    // Allocate memory for request and preemption indices
    req = ( int * ) malloc ( n * sizeof ( int ) ) ;
    pre = ( int * ) malloc ( m * sizeof ( int ) ) ;

    // Read request indices and store them in the array
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", & req [ i ] ) ;
        // Comment: Read and store request index i
    }

    // Read preemption indices and store them in the array
    for ( j = 0 ; j < m ; j ++ ) {
        scanf ( "%d", & pre [ j ] ) ;
        // Comment: Read and store preemption index j
    }

    // Initialize answer variable
    ans = 0 ;

    // Initialize index variables for requests and preemptions
    i = n - 1 ;
    j = m - 1 ;

    // While there are still requests and preemptions to compare
    while ( i >= 0 && j >= 0 ) {
        // If the current request can preempt the current preemption
        if ( req [ i ] > pre [ j ] ) {
            // Increment answer variable
            ans ++ ;
        } else {
            // Decrement preemption index
            j -- ;
        }
        // Decrement request index
        i -- ;
    }

    // Print the answer and the number of remaining requests
    printf ( "%d %d\n", ans, i + 1 ) ;

    // Free memory allocated for request and preemption indices
    free ( req ) ;
    free ( pre ) ;

    // Return 0 to indicate successful execution
    return 0 ;
}

