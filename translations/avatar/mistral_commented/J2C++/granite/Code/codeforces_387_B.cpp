
// Include necessary C++ utility headers
#include <iostream>
#include <vector>
#include <algorithm>

// Main method is the entry point of the C++ application
int main ( ) {
    // Initialize std::cin to read input from the standard input
    std::cin.tie ( NULL ) ;
    std::ios_base::sync_with_stdio ( false ) ;

    // Read the number of requests and preemptions from the input
    int n, m ;
    std::cin >> n >> m ;

    // Create std::vector to store request indices
    std::vector < int > req ( n ) ;

    // Read request indices and store them in the std::vector
    for ( int i = 0 ; i < n ; i ++ ) {
        std::cin >> req [ i ] ;
        // Comment: Read and store request index i
    }

    // Create std::vector to store preemption indices
    std::vector < int > pre ( m ) ;

    // Read preemption indices and store them in the std::vector
    for ( int i = 0 ; i < m ; i ++ ) {
        std::cin >> pre [ i ] ;
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
    std::cout << ans + i + 1 << std::endl ;

    // Return 0 to indicate successful execution
    return 0 ;
}
