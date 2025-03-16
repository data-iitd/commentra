
#include <iostream> 
#include <cstdlib> 

using namespace std ; 

int main ( ) { 
    // Read the number of elements
    int n ; 
    cin >> n ; 
    
    // Initialize arrays to store the elements
    int h [ n ] ; 
    int g [ n ] ; 
    
    // Read n pairs of integers from the standard input
    for ( int i = 0 ; i < n ; i ++ ) { 
        cin >> h [ i ] >> g [ i ] ; 
    } 
    
    // Initialize the result variable to 0
    int result = 0 ; 
    
    // Iterate through each element in array h
    for ( int i = 0 ; i < n ; i ++ ) { 
        // Compare each element in array h with each element in array g
        for ( int j = 0 ; j < n ; j ++ ) { 
            if ( h [ i ] == g [ j ] ) { 
                // If a match is found, increment the result
                result ++ ; 
            } 
        } 
    } 
    
    // Print the value of result
    cout << result << endl ; 
    
    return 0 ; 
}

