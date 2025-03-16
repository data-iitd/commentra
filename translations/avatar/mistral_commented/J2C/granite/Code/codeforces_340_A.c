
#include <stdio.h>  // Include the standard input/output library

int main ( void ) {  // Main function to start the program
    long x, y, a, b, j = 2, i, x1 = 0, y1 = 0, c = 0 ;  // Declare and initialize variables
    int ans = 1 ;  // Declare and initialize a boolean variable to keep track of the result

    scanf ( "%ld %ld %ld %ld", &x, &y, &a, &b ) ;  // Read the input values from the user

    c = ( x > y )? x : y ;  // Find the maximum value between x and y

    if ( c > b ) {  // Check if the maximum value is greater than b
        printf ( "0" ) ;  // If true, print 0 and set ans to 0
        ans = 0 ;
    }

    while ( c % ( x < y? x : y )!= 0 && ans ) {  // Loop to find the greatest common divisor (GCD)
        if ( x > y ) {  // If x is greater than y
            c = x * j ;  // Multiply x by j and update c
            j ++ ;  // Increment j
        } else {
            c = y * j ;  // Multiply y by j and update c
            j ++ ;  // Increment j
        }

        if ( c > b ) {  // Check if the current value of c is greater than b
            printf ( "0" ) ;  // If true, print 0 and set ans to 0
            ans = 0 ;
            break ;  // Exit the loop
        }
    }

    if ( ans ) {  // If the GCD has been found
        long count = 0 ;  // Declare a counter variable
        i = a ;  // Start the loop from a

        for ( i = a ; i <= b ; i ++ ) {  // Loop to find the number of times c divides i
            if ( i % c == 0 ) break ;  // If i is divisible by c, break the loop
        }

        if ( i!= b + 1 ) {  // Check if the last number in the range is divisible by c
            printf ( "%ld", ( ( b - i ) / c ) + 1 ) ;  // Print the result
        } else {
            printf ( "0" ) ;  // If the last number is not divisible by c, print 0
        }
    }

    return 0 ;  // Return 0 to indicate successful execution
}
