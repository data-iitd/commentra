// Including necessary header files for input and output
#include <stdio.h>
#include <stdlib.h>

// Main function is the entry point of the C program
int main ( ) {
    // Declare variables for storing input and result
    int A, B, amari, result ;

    // Read first integer input A from user
    scanf ( "%d", &A ) ;

    // Read second integer input B from user
    scanf ( "%d", &B ) ;

    // Calculate the result by dividing B by A - 1 and storing the quotient
    result = ( B - 1 ) / ( A - 1 ) ;

    // Calculate the remainder of B divided by A - 1 and store it in amari
    amari = ( B - 1 ) % ( A - 1 ) ;

    // Check if the remainder is not zero
    if ( amari != 0 ) {
        // If the remainder is not zero, increment the result by 1
        result += 1 ;
    }

    // Write the result to the standard output
    printf ( "%d\n", result ) ;

    // End of code
    return 0 ;
}
