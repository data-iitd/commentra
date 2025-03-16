
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creating Scanner object for reading input from the standard input
    int a, b, c = 0 ;
    scanf ( "%d %d", &a, &b ) ;

    // Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if ( a == 1 && b == 1 ) {
        printf ( "%d", 0 ) ;
        exit ( 0 ) ;
    }

    // If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
    else {
        // Performing the loop until either 'a' or 'b' becomes 0
        while ( a >= 1 || b >= 1 ) {
            // If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
            if ( a >= b ) {
                b++ ;
                a -= 2 ;
            }
            // If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
            else {
                a++ ;
                b-- ;
            }

            // Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
            if ( a <= 0 || b <= 0 ) {
                c++ ;
                break ;
            }

            // Incrementing 'c' for each iteration of the loop
            c++ ;
        }

        // Printing the final result 'c' as the output
        printf ( "%d", c ) ;
    }

    // Exiting the program
    return 0 ;
}

