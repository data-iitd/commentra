# Importing necessary modules for file I/O and collections
import sys

# Main method is the entry point of the Python application
def main ( ) :
    # Reading the first integer 'n' from the standard input
    n = int ( sys.stdin.readline ( ) )

    # Reading the second integer 'm' from the standard input
    m = int ( sys.stdin.readline ( ) )

    # Checking if 'n' is equal to zero
    if ( n == 0 ) :
        # If 'm' is not equal to zero, print "Impossible"
        if ( m != 0 ) :
            print ( "Impossible" )
        else : # If 'm' is also zero, print '0' space '0'
            print ( 0, 0 )
        # Returning from the main method
        return

    # Checking if 'm' is less than or equal to 'n'
    if ( m <= n ) :
        # If 'm' is zero, assign it the value 1
        if ( m == 0 ) :
            m = 1
        # Printing 'n' and the sum of 'm' and 'n' minus one
        print ( n, m + n - 1 )
        # Returning from the main method
        return

    # If 'm' is greater than 'n', print 'm' and the sum of 'm' and 'n' minus one
    print ( m, m + n - 1 )

# Calling the main method
main ( )


