
#include <stdio.h>

// Function to check if it's possible to place the required number of 'L' islands in the grid
void printIsland ( int n, int count ) {
    int a = ( n + 1 ) / 2 ; // Calculate the side length 'a' of the square grid of size 'n x n'
    int b = n / 2 ; // Calculate the square of the side length 'b' of the grid
    int max = a * a + b * b ; // Calculate the maximum number of 'L' islands that can be placed in the grid

    // Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
    if ( count > max ) {
        printf ( "NO\n" ) ; // If yes, print "NO" and return from the function
        return ;
    }

    printf ( "YES\n" ) ; // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

    // Initialize a character array 'grid' to store a row of the grid
    char grid [ n ] [ n ] ;
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            // If the cell is in the position where an 'L' island can be placed, set the corresponding element of the grid to 'L' and decrement the count
            if ( ( i + j ) % 2 == 0 && count > 0 ) {
                grid [ i ] [ j ] = 'L' ;
                count -- ;
            } else {
                // Otherwise, set the corresponding element of the grid to 'S'
                grid [ i ] [ j ] = 'S' ;
            }
        }
    }

    // Print the contents of the grid to represent a row of the grid
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            printf ( "%c", grid [ i ] [ j ] ) ; // Print the character at the corresponding position in the grid
        }
        printf ( "\n" ) ; // Move to the next line to print the next row of the grid
    }
}

// Entry point of the program
int main ( ) {
    int n, count ; // Declare variables to store the size of the grid and the number of 'L' islands to be placed
    scanf ( "%d %d", & n, & count ) ; // Read the size of the grid and the number of 'L' islands to be placed from the standard input stream
    printIsland ( n, count ) ; // Call the printIsland function with the arguments 'n' and 'count'
    return 0 ; // Return 0 to indicate successful execution of the program
}

// Translate the above C code to Python and end with comment "