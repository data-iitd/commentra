
# Importing necessary modules for file I/O and collections
import sys
import math

# Main method is the entry point of the Python application
def main ( ):
    # Declaring a variable named 'input' to read input from the standard input stream
    input = sys.stdin.read ( )

    # Declaring a list named 'input_list' to store the input values
    input_list = input.split ( )

    # Converting the input values from string to integer
    n = int ( input_list [ 0 ] )
    m = int ( input_list [ 1 ] )

    # Checking if 'n' is equal to zero
    if ( n == 0 ) :
        # If'm' is not equal to zero, print "Impossible"
        if ( m!= 0 ) :
            print ( "Impossible" )
        else : # If'm' is also zero, print '0' space '0'
            print ( 0, 0 )
        # Returning from the main method
        return

    # Checking if'm' is less than or equal to 'n'
    if ( m <= n ) :
        # If'm' is zero, assign it the value 1
        if ( m == 0 ) :
            m = 1
        # Printing 'n' and the sum of'm' and 'n' minus one
        print ( n, m + n - 1 )
        # Returning from the main method
        return

    # If'm' is greater than 'n', print'm' and the sum of'm' and 'n' minus one
    print ( m, m + n - 1 )

# Calling the main method to execute the program
main ( )

