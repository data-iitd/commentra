#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>

// Main method is the entry point of the C application
int main ( int argc, char * argv [ ] ) {
    // Declare main method that takes command line arguments
    int n = atoi ( argv [ 1 ] ) ;
    int m = atoi ( argv [ 2 ] ) ;

    // Declare variables to store request and preemption indices
    int req [ n ] ;
    int pre [ m ] ;

    // Read request indices and store them in the req array
    for ( int i = 0 ; i < n ; i ++ ) {
        req [ i ] = atoi ( argv [ i + 3 ] ) ;
        // Comment: Read and store request index i
    }

    // Read preemption indices and store them in the pre array
    for ( int i = 0 ; i < m ; i ++ ) {
        pre [ i ] = atoi ( argv [ i + 3 + n ] ) ;
        // Comment: Read and store preemption index i
    }

    // Initialize index variables for requests and preemptions
    int i = n - 1 ;
    int j = m - 1 ;

    // Initialize answer variable
    int ans = 0 ;

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
    printf ( "%d %d", ans, i + 1 ) ;

    // Return from main method
    return 0 ;
}

