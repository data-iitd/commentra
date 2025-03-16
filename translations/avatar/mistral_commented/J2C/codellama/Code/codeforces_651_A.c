
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Defining a structure for storing two integers
struct int_pair {
    int a ;
    int b ;
} ;

// Defining a structure for storing three integers
struct int_triplet {
    int a ;
    int b ;
    int c ;
} ;

// Defining a function for swapping two integers
void swap ( int *a , int *b ) {
    // Swapping 'a' and 'b' by using a temporary variable 't'
    int t = *b ;
    *b = *a ;
    *a = t ;
}

// Defining a function for debugging purposes
void debug ( char *msg , int a , int b , int c ) {
    // Printing the debug information using printf() function
    printf ( "%s: a = %d, b = %d, c = %d\n" , msg , a , b , c ) ;
}

// Defining a function for exiting the main function
void exitMainFunction ( ) {
    // Exiting the main function by using exit() function
    exit ( 0 ) ;
}

// Defining the main function
int main ( ) {
    // Creating a structure for storing two integers
    struct int_pair pair ;

    // Reading two integers 'a' and 'b' from the standard input
    scanf ( "%d%d" , &pair.a , &pair.b ) ;

    // Initializing variable 'c' to 0
    int c = 0 ;

    // Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if ( pair.a == 1 && pair.b == 1 ) {
        printf ( "0\n" ) ;  // Printing 0 as the output
        exitMainFunction ( ) ;  // Exiting the main function
    }

    // If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
    else {
        // Performing the loop until either 'a' or 'b' becomes 0
        while ( pair.a >= 1 || pair.b >= 1 ) {
            // If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
            if ( pair.a >= pair.b ) {
                pair.b++ ;
                pair.a -= 2 ;
            }
            // If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
            else {
                pair.a++ ;
                pair.b-- ;
            }

            // Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
            if ( pair.a <= 0 || pair.b <= 0 ) {
                c++ ;
                break ;
            }

            // Incrementing 'c' for each iteration of the loop
            c++ ;
        }

        // Printing the final result 'c' as the output
        printf ( "%d\n" , c ) ;
    }

    // Returning 0 from the main function
    return 0 ;
}

