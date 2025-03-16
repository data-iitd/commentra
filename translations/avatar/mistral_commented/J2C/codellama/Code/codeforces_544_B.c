#include <stdio.h>
#include <stdlib.h>

// Entry point of the program
int main ( int argc , char *argv [ ] ) {
    int n , count ; // Declare two integers 'n' and 'count' to store the values of the first and second integers read from the standard input stream
    scanf ( "%d %d" , &n , &count ) ; // Read the first and second integers from the input
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
        printf ( "NO\n" ) ; // If yes, print "NO" and return from the method
        return ;
    }

    printf ( "YES\n" ) ; // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

    // Initialize a character array 'grid' to store a row of the grid
    char grid [ n ] [ n ] ; // Declare a two-dimensional character array 'grid' of size 'n x n'
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            // If the cell is in the position where an 'L' island can be placed, assign an 'L' character to the cell and decrement the count
            if ( ( i + j ) % 2 == 0 && count > 0 ) {
                grid [ i ] [ j ] = 'L' ;
                count -- ;
            } else {
                // Otherwise, assign an 'S' character to the cell
                grid [ i ] [ j ] = 'S' ;
            }
        }
    }

    // Print the contents of the grid to represent the grid
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            printf ( "%c" , grid [ i ] [ j ] ) ;
        }
        printf ( "\n" ) ;
    }
}

