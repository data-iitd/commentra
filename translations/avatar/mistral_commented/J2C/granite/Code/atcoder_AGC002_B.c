
#include <stdio.h> // Include the standard input/output library

int main ( void ) { // Define the main function
    int N, M, x, y, counter = 0; // Declare and initialize the variables N, M, x, y, and counter
    scanf ( "%d %d", &N, &M ); // Read the first and second integers from the user
    int boxes [ N ]; // Declare an array of integers with size N
    for ( int i = 0 ; i < N ; i ++ ) { // Initialize the boxes array with red color
        boxes [ i ] = 1;
    }
    for ( int i = 0 ; i < M ; i ++ ) { // Read the moves from the user and perform them on the boxes
        scanf ( "%d %d", &x, &y );
        if ( boxes [ x - 1 ] == 1 ) { // If the box at index x - 1 has red color
            boxes [ x - 1 ] = 0; // Set the box at index x - 1 to be empty
            boxes [ y - 1 ] += 1; // Increment the number of items in the box at index y - 1
            if ( boxes [ x - 1 ] == 1 ) { // If the box at index x - 1 was red
                boxes [ y - 1 ] = 1; // Set the box at index y - 1 to be red
            }
        }
    }
    for ( int i = 0 ; i < N ; i ++ ) { // Count the number of red boxes
        if ( boxes [ i ] == 1 ) {
            counter += 1;
        }
    }
    printf ( "%d", counter ); // Print the result
    return 0; // Return 0 to indicate successful execution
}

