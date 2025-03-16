
# Importing required modules for file I/O and Scanner
import sys

# Main method starts the execution of the program
def main ( ):
    sc = sys.stdin.readline().rstrip().split ( ) # Initialize Scanner for user input
    H = int ( sc [ 0 ] ) # Height of the grid
    W = int ( sc [ 1 ] ) # Width of the grid
    A = int ( sc [ 2 ] ) # Number of columns in the first row
    B = int ( sc [ 3 ] ) # Number of rows in the last row

    # Check if the grid dimensions meet the conditions
    if ( W < 2 * A ) or ( H < 2 * B ):
        print ( - 1 ) # Print -1 if the conditions are not met
        return # Exit the program

    # Write the grid to the output
    for i in range ( H ):
        for j in range ( W ):
            # Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if ( ( i < B ) and ( j < A ) ) or ( ( i >= B ) and ( j >= A ) ):
                sys.stdout.write ( "0" )
            else:
                sys.stdout.write ( "1" )
        sys.stdout.write ( "\n" ) # Move to the next line after writing a row

# Call the main method to start the program
main ( )

