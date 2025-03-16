// Include necessary C++ utility classes
#include <iostream>
#include <vector>

// Main function is the entry point of the C++ application
int main ( ) {
    // Declare variables to store the number of requests and preemptions
    int n, m ;

    // Declare variables to store the request and preemption indices
    std::vector < int > req, pre ;

    // Read the number of requests and preemptions from the input
    std::cin >> n >> m ;

    // Read request indices and store them in the vector
    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        std::cin >> x ;
        req.push_back ( x ) ;
        // Comment: Read and store request index i
    }

    // Read preemption indices and store them in the vector
    for ( int i = 0 ; i < m ; i ++ ) {
        int x ;
        std::cin >> x ;
        pre.push_back ( x ) ;
        // Comment: Read and store preemption index i
    }

    // Initialize index variables for requests and preemptions
    int i = n - 1, j = m - 1 ;

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

    // End of code
    return 0 ;
}