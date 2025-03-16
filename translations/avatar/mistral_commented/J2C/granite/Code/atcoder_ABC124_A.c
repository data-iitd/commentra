
#include <stdio.h>  // Include standard input/output library

int main ( void ) {  // Entry point of the C application
    int a, b, sum = 0 ;  // Declare and initialize variables a, b, and sum

    scanf ( "%d %d", &a, &b ) ;  // Read two integers from standard input and store them in variables a and b

    for ( int i = 0 ; i < 2 ; i ++ ) {  // Iterate through two iterations
        if ( a >= b ) {  // Check if a is greater than or equal to b
            sum += a ;  // Add a to sum and decrement a by 1
            a-- ;  // Decrement a by 1
        } else {
            sum += b ;  // Add b to sum and decrement b by 1
            b-- ;  // Decrement b by 1
        }
    }

    printf ( "%d\n", sum ) ;  // Print the value of sum to standard output

    return 0 ;  // Return 0 to indicate successful execution of the program
}
