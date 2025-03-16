// Include necessary C libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the main function
int main ( ) {
    // Initialize the scanner for reading input
    int len ;
    scanf ( "%d", &len ) ;

    // Allocate memory for the array of integers
    int a [ len ] ;

    // Read each integer from the user input and store it in the array
    for ( int i = 0 ; i < len ; i ++ ) {
        scanf ( "%d", &a [ i ] ) ;
    }

    // Initialize variables for left and right indices and a flag
    int l = 0 ;
    int r = 0 ;
    bool flag = false ;

    // Start the loop to search for two non-consecutive numbers
    for ( int i = 0 ; i < len ; i ++ ) {

        // Check if the current number is not in its correct position
        if ( a [ i ] != i + 1 && ! flag ) {
            // Update the left index
            l = i + 1 ;
            // Set the flag to true to indicate that we have found the first non-consecutive number
            flag = true ;
            // Continue to the next iteration of the loop
            continue ;
        }

        // Check if the current number is also not in its correct position and the flag is set
        if ( a [ i ] != i + 1 && flag ) {
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
    printf ( ( ! isTrue ) ? "%d %d\n" : "0 0\n", l, r ) ;

    // End the program
    return 0 ;
}

