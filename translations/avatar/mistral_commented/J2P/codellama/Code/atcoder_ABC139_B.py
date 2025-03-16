# Importing necessary libraries for input and output
import sys

# Main method is the entry point of the Python application
def main ( ) :
    # Initialize Scanner object to read input from standard input
    sc = sys.stdin

    # Read first integer input A from user
    A = int ( sc.readline ( ) )

    # Read second integer input B from user
    B = int ( sc.readline ( ) )

    # Initialize variables for storing remainders and result
    amari = 0
    result = 0

    # Calculate the result by dividing B by A - 1 and storing the quotient
    result = ( B - 1 ) // ( A - 1 )

    # Calculate the remainder of B divided by A - 1 and store it in amari
    amari = ( B - 1 ) % ( A - 1 )

    # Check if the remainder is not zero
    if ( amari != 0 ) :
        # If the remainder is not zero, increment the result by 1
        result += 1

    # Initialize PrintWriter object to write output to standard output
    out = sys.stdout

    # Write the result to the standard output
    out.write ( str ( result ) + "\n" )

    # Close the Scanner object to release system resources
    sc.close ( )

    # Flush the PrintWriter buffer to write the output immediately
    out.flush ( )

# Call the main method to start the application
main ( )

# End of code
