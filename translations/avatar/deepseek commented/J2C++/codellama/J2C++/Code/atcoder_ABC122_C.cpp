
#include <iostream> 
#include <cstring> 

using namespace std ; 

// Define a constant for modulo operations
const long mod = 1000000007 ; 

int main ( ) { 
    // Create a Scanner object to read input
    int n, q ; 
    char c [ 100000 ] ; 
    int range [ 100000 ] [ 2 ] ; 
    int frag [ 100000 ] ; 
    int rui [ 100000 ] ; 

    // Read the length of the string and the number of queries
    cin >> n >> q ; 

    // Read the string as a character array
    cin >> c ; 

    // Read the ranges for the queries and store them in a 2D array
    for ( int i = 0 ; i < q ; i ++ ) { 
        cin >> range [ i ] [ 0 ] >> range [ i ] [ 1 ] ; 
    } 

    // Initialize arrays to count "AC" fragments and store cumulative sums
    for ( int i = 0 ; i < n ; i ++ ) { 
        frag [ i ] = 0 ; 
        rui [ i ] = 0 ; 
    } 

    // Process the string to find "AC" fragments
    for ( int i = 2 ; i <= n ; i ++ ) { 
        if ( c [ i - 2 ] == 'A' && c [ i - 1 ] == 'C' ) { 
            // Increment the count of "AC" fragments at position i
            frag [ i ] ++ ; 
        } 
        // Update the cumulative sum array
        rui [ i ] = rui [ i - 1 ] + frag [ i ] ; 
    } 

    // Process the queries
    for ( int i = 0 ; i < q ; i ++ ) { 
        int left = range [ i ] [ 0 ] ; 
        int right = range [ i ] [ 1 ] ; 
        // Calculate the number of "AC" fragments in the given range
        cout << rui [ right ] - rui [ left ] << endl ; 
    } 

    return 0 ; 
} 

