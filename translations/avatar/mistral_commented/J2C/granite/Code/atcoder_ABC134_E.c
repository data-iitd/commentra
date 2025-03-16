
#include <stdio.h>  // Include the standard input/output library
#include <stdlib.h>  // Include the standard library

int main ( void ) {  // Main function to start the program
    int n ;  // Declare an integer variable to store the number of test cases
    scanf ( "%d", & n ) ;  // Read the number of test cases from the console

    int * arr = ( int * ) malloc ( n * sizeof ( int ) ) ;  // Allocate memory for an array of size n to store the test cases

    for ( int i = 0 ; i < n ; i ++ ) {  // Loop through each test case
        scanf ( "%d", & arr [ i ] ) ;  // Read the test case from the console
    }

    int * freq = ( int * ) malloc ( 100001 * sizeof ( int ) ) ;  // Allocate memory for an array of size 100001 to store the frequency of each number

    for ( int i = 0 ; i < 100001 ; i ++ ) {  // Initialize the frequency array to 0
        freq [ i ] = 0 ;
    }

    for ( int i = 0 ; i < n ; i ++ ) {  // Loop through each test case
        freq [ arr [ i ] ] ++ ;  // Increment the frequency of the current number in the frequency array
    }

    int ans = 0 ;  // Initialize the answer variable to 0

    for ( int i = 0 ; i < 100001 ; i ++ ) {  // Loop through each number in the frequency array
        if ( freq [ i ] > 0 ) {  // If the frequency of the current number is greater than 0
            ans += freq [ i ] ;  // Add the frequency of the current number to the answer
        }
    }

    printf ( "%d", ans ) ;  // Print the answer to the console

    free ( arr ) ;  // Free the memory allocated for the array of test cases
    free ( freq ) ;  // Free the memory allocated for the frequency array

    return 0 ;  // Return 0 to indicate successful execution of the program
}

