
#include <iostream>  // Including necessary C++ headers for input and output operations
#include <cmath>  // Including necessary C++ headers for mathematical operations
#include <cstdlib>  // Including necessary C++ headers for utilities like exit()
#include <cstring>  // Including necessary C++ headers for string operations

using namespace std ;  // Using standard namespace for C++

// Main function is the entry point of the C++ application
int main ( ) {
    // Creating Scanner object for reading input from the standard input
    Scanner in ( stdin ) ;
    // Creating PrintWriter object for writing output to the standard output
    PrintWriter pw ( stdout ) ;

    // Reading two integers 'a' and 'b' from the standard input
    int a = in.nextInt ( ) , b = in.nextInt ( ) ;

    // Initializing variable 'c' to 0
    int c = 0 ;

    // Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if ( a == 1 && b == 1 ) {
        pw.println ( 0 ) ;  // Printing 0 as the output
        exitMainFunction () ;  // Exiting the main function
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
        pw.println ( c ) ;
    }

    // Closing the PrintWriter object
    pw.close ( ) ;

    // Returning 0 as the exit status
    return 0 ;
}

// Static method for swapping two integers
void swap ( int a , int b ) {
    // Swapping 'a' and 'b' by using a temporary variable 't'
    int t = b ;
    b = a ;
    a = t ;
}

// Static method for debugging purposes
void debug ( Object...obj ) {
    // Printing the debug information using Arrays.deepToString() method
    System.err.println ( Arrays.deepToString ( obj ) ) ;
}

// Helper method for exiting the main function
void exitMainFunction ( ) {
    exit ( 0 ) ;
}

// End of code
