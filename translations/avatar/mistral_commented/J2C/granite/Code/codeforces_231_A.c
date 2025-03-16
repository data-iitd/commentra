
#include <stdio.h> // Include the standard input/output library

int main ( void ) { // Entry point of the program
    int t ; // Read the number of test cases from the standard input

    // Initialize a counter variable to keep track of the number of valid cases
    int count = 0 ;

    // Read the number of test cases and process each one in the while loop
    scanf ( "%d", &t ) ; // Read the number of test cases from the standard input
    while ( t -- > 0 ) {
        int a, b, c ; // Read the three integers from the standard input
        scanf ( "%d %d %d", &a, &b, &c ) ; // Read the three integers from the standard input

        // Check if any of the given integers are equal to 1. If so, increment the counter.
        if ( ( a == 1 && b == 1 ) || ( a == 1 && c == 1 ) || ( b == 1 && c == 1 ) || ( a == 1 && b == 1 && c == 1 ) ) {
            count ++ ; // Increment the counter if any of the given integers are equal to 1
        }
    }

    // Print the value of the counter to the standard output
    printf ( "%d\n", count ) ; // Print the value of the counter to the standard output

    return 0 ; // Return 0 to indicate successful execution of the program
}
