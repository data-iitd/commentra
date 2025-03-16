

#include <stdio.h> // Include the standard input/output library

int main ( void ) { // Main function definition
    int A, B, n ; // Declare integer variables A, B, and n
    scanf ( "%d %d %d", & A, & B, & n ) ; // Read the values of A, B, and n from the standard input
    if ( A == 0 ) { // Check if A is equal to zero
        if ( B == 0 ) { // Check if B is also equal to zero
            printf ( "1\n" ) ; // If both A and B are zero, print 1
        } else {
            printf ( "No solution\n" ) ; // If A is zero but B is not, print "No solution"
            return 0 ; // Exit the program
        }
        return 0 ; // Exit the program
    }
    if ( B % A!= 0 ) { // Check if B is not divisible by A
        printf ( "No solution\n" ) ; // If B is not divisible by A, print "No solution"
        return 0 ; // Exit the program
    }
    B /= A ; // Divide B by A
    int neg = B < 0 ; // Check if B is negative
    if ( neg && n % 2 == 0 ) { // Check if n is even and B is negative
        printf ( "No solution\n" ) ; // If both conditions are true, print "No solution"
        return 0 ; // Exit the program
    }
    if ( neg ) B = - B ; // If B is negative, make it positive
    for ( int x = 0 ; x <= B ; x ++ ) { // Iterate through all possible values of x from 0 to B
        if ( pow ( x, n ) == B ) { // Check if x raised to the power of n is equal to B
            printf ( "%d\n", neg? - x : x ) ; // Print the value of x with its sign
            return 0 ; // Exit the program
        }
    }
    printf ( "No solution\n" ) ; // If no solution is found, print "No solution"
    return 0 ; // Exit the program
}

