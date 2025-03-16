
#include <stdio.h>  // Include the standard input/output library

int main ( void ) {   // Define the main function
    int n ;  // Declare an integer variable to store the size of the array

    scanf ( "%d", &n ) ;  // Read the first integer from the input as the size of the array

    int arr [ n ] ;  // Declare an integer array of size n to store the input

    for ( int i = 0 ; i < n ; i ++ ) {   // Loop through the input to store the indices of the 1's in the array
        scanf ( "%d", &arr [ i ] ) ;
    }

    long result = 1 ;  // Initialize the result variable to 1

    for ( int i = 1 ; i < n ; i ++ ) {  // Loop through the array to calculate the result
        result *= arr [ i ] - arr [ i - 1 ] ;  // Multiply the difference between two consecutive indices to the result
    }

    printf ( "%ld", result ) ;  // Print the result as the output

    return 0 ;  // Return 0 to indicate successful execution of the program
}
