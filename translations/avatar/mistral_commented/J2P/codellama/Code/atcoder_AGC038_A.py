# Importing required classes for file I/O and Scanner
from sys import stdin
from sys import stdout
from math import sqrt

# Main method starts the execution of the program
def main ( ):
    # Initialize Scanner for user input
    sc = stdin.readline ( )
    # Initialize BufferedWriter for output
    bw = stdout.write
    # Read input values for H, W, A, and B
    H, W, A, B = map ( int, sc.split ( ) )
    # Check if the grid dimensions meet the conditions
    if ( W < 2 * A or H < 2 * B ):
        # Print -1 if the conditions are not met
        bw ( - 1 )
        # Exit the program
        return
    # Write the grid to the output
    for i in range ( H ):
        for j in range ( W ):
            # Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if ( i < B and j < A ) or ( i >= B ) and ( j >= A ):
                bw ( "0" )
            else:
                bw ( "1" )
        # Move to the next line after writing a row
        bw ( "\n" )
    # Flush the buffer to write the output to the console
    bw ( )

# Call the main method
main ( )



Translate the above Python code to C++ and end with comment "