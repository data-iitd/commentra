#include <iostream>
#include <cmath>

using namespace std ;

// Entry point of the program
int main ( ) {
    int n , count ; // Declare two integers 'n' and 'count' to store the values read from the standard input stream
    cin >> n >> count ; // Read the first integer 'n' and the second integer 'count' from the input
    printIsland ( n , count ) ; // Call the printIsland method with the arguments 'n' and 'count'
    return 0 ;
}

// Method to check if it's possible to place the required number of 'L' islands in the grid
void printIsland ( int n , int count ) {
    int a = ( n + 1 ) / 2 ; // Calculate the side length 'a' of the square grid of size 'n x n'
    int b = n / 2 ; // Calculate the square of the side length 'b' of the grid
    int max = a * a + b * b ; // Calculate the maximum number of 'L' islands that can be placed in the grid

    // Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
    if ( count > max ) {
        cout << "NO" << endl ; // If yes, print "NO" and return from the method
        return ;
    }

    cout << "YES" << endl ; // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

    // Initialize a string 'row' to store a row of the grid
    for ( int i = 0 ; i < n ; i ++ ) {
        string row = "" ; // Initialize the string 'row' to an empty string
        for ( int j = 0 ; j < n ; j ++ ) {
            // If the cell is in the position where an 'L' island can be placed, append an 'L' character to the string 'row' and decrement the count
            if ( ( i + j ) % 2 == 0 && count > 0 ) {
                row += 'L' ;
                count -- ;
            } else {
                // Otherwise, append an 'S' character to the string 'row'
                row += 'S' ;
            }
        }
        // Print the contents of the string 'row' to represent a row of the grid
        cout << row << endl ;
    }
}

