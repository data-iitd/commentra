#include <stdio.h>

int main ( ) {
    int t ; // Declare a variable to store the number of test cases
    int a, b, c ; // Declare variables to store the three integers
    int count = 0 ; // Declare a variable to store the number of valid cases

    // Read the number of test cases from the standard input
    scanf ( "%d", &t ) ;

    // Process each test case in the while loop
    while ( t -- > 0 ) {
        // Read the three integers from the standard input
        scanf ( "%d %d %d", &a, &b, &c ) ;

        // Check if any of the given integers are equal to 1. If so, increment the counter.
        if ( ( a == 1 && b == 1 ) || ( a == 1 && c == 1 ) || ( b == 1 && c == 1 ) || ( a == 1 && b == 1 && c == 1 ) ) {
            count ++ ; // Increment the counter if any of the given integers are equal to 1
        }
    }

    // Print the value of the counter to the standard output
    printf ( "%d\n", count ) ;

    return 0 ;
}

