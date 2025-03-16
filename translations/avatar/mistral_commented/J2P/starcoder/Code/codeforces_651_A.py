
# Importing necessary Python classes for input and output operations
import sys
import math

# Importing necessary Python classes for utilities like Scanner and PrintWriter
from java.io import *
from java.math import *
from java.util import *

# Main method is the entry point of the Python application
if __name__ == '__main__' :
    # Creating Scanner object for reading input from the standard input
    in = Scanner ( System.in )
    # Creating PrintWriter object for writing output to the standard output
    pw = PrintWriter ( System.out )

    # Reading two integers 'a' and 'b' from the standard input
    a = in.nextInt ( )
    b = in.nextInt ( )

    # Initializing variable 'c' to 0
    c = 0

    # Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if ( a == 1 and b == 1 ) :
        pw.println ( 0 ) ;  # Printing 0 as the output
        exitMainFunction () ;  # Exiting the main function

    # If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
    else :
        # Performing the loop until either 'a' or 'b' becomes 0
        while ( a >= 1 or b >= 1 ) :
            # If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
            if ( a >= b ) :
                b += 1
                a -= 2

            # If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
            else :
                a += 1
                b -= 1

            # Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
            if ( a <= 0 or b <= 0 ) :
                c += 1
                break

            # Incrementing 'c' for each iteration of the loop
            c += 1

        # Printing the final result 'c' as the output
        pw.println ( c )

    # Closing the PrintWriter object
    pw.close ( )

# Static method for swapping two integers
def swap ( a, b ) :
    # Swapping 'a' and 'b' by using a temporary variable 't'
    t = b
    b = a
    a = t

# Static method for debugging purposes
def debug ( *obj ) :
    # Printing the debug information using Arrays.deepToString() method
    System.err.println ( Arrays.deepToString ( obj ) )

# Helper method for exiting the main function
def exitMainFunction () :
    System.exit ( 0 )

