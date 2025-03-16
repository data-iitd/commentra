
#include <iostream>
#include <cmath>

using namespace std ; 

int main ( ) { 
    int q ; // Declare the number of queries variable q
    cin >> q ; // Read the number of queries
    
    while ( q -- > 0 ) { 
        int n ; // Declare the number n for the current query
        cin >> n ; // Read the number n for the current query
        long s = 0 ; // Initialize the sum variable s
        
        int x = ( int ) ( log ( n ) / log ( 2 ) ) ; // Calculate the position of the most significant bit of n
        x ++ ; // Increment x by 1
        
        s = - 1 * ( long ) pow ( 2 , x ) + 2 + ( ( long ) n * ( long ) ( n + 1 ) ) / 2 - ( long ) pow ( 2 , x ) ; 
        // Calculate s using arithmetic operations and power functions
        
        cout << s << endl ; // Print the result s for the current query
    } 
}

