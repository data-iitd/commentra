
// Include necessary header files
#include <stdio.h>
#include <stdlib.h>

// Main function is the entry point of the program
int main ( ) {
    // Declare variables for the length of the array, the array of integers, and the left and right indices
    int len ;
    int * a ;
    int l ;
    int r ;

    // Read the length of the array from the user input
    scanf ( "%d", & len ) ;

    // Allocate memory for the array of integers
    a = ( int * ) malloc ( len * sizeof ( int ) ) ;

    // Read each integer from the user input and store it in the array
    for ( int i = 0 ; i < len ; i ++ ) {
        scanf ( "%d", & a [ i ] ) ;
    }

    // Initialize variables for the left and right indices and a flag
    l = 0 ;
    r = 0 ;
    bool flag = false ;

    // Start the loop to search for two non-consecutive numbers
    for ( int i = 0 ; i < len ; i ++ ) {

        // Check if the current number is not in its correct position
        if ( a [ i ]!= i + 1 &&! flag ) {
            // Update the left index
            l = i + 1 ;
            // Set the flag to true to indicate that we have found the first non-consecutive number
            flag = true ;
            // Continue to the next iteration of the loop
            continue ;
        }

        // Check if the current number is also not in its correct position and the flag is set
        if ( a [ i ]!= i + 1 && flag ) {
            // Update the right index
            r = i + 1 ;

            // Check if the difference between the previous number and the current number is greater than 1
            if ( ( a [ r - 1 ] - a [ r - 2 ] > 0 ) ) {
                // Set the isTrue flag to true if the condition is satisfied
                isTrue = true ;
                // Break out of the loop if the flag is set to true
                break ;
            }
        }
    }

    // Print the result based on the value of the isTrue flag
    printf ( "%d %d", (! isTrue )? l : 0, (! isTrue )? r : 0 ) ;

    // Free the memory allocated for the array of integers
    free ( a ) ;

    // End the program
    return 0 ;
}
