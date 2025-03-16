_

#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    int n, count ;
    cin >> n >> count ;
    printIsland ( n, count ) ;
}

// Method to check if it's possible to place the required number of 'L' islands in the grid
void printIsland ( int n, int count ) {
    int a = ( n + 1 ) / 2 ; // Calculate the side length 'a' of the square grid of size 'n x n'
    int b = n / 2 ; // Calculate the square of the side length 'b' of the grid
    int max = a * a + b * b ; // Calculate the maximum number of 'L' islands that can be placed in the grid

    // Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
    if ( count > max ) {
        cout << "NO" << endl ; // If yes, print "NO" and return from the method
        return ;
    }

    cout << "YES" << endl ; // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

    // Initialize a string's' to store a row of the grid
    string s ;
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            // If the cell is in the position where an 'L' island can be placed, append an 'L' character to the string and decrement the count
            if ( ( i + j ) % 2 == 0 && count > 0 ) {
                s += 'L' ;
                count -- ;
            } else {
                // Otherwise, append an 'S' character to the string
                s += 'S' ;
            }
        }
        // Print the contents of the string to represent a row of the grid
        cout << s << endl ;
        s = "" ;
    }
}

