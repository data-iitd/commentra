

import sys ; # Input stream to read input
import os ; # Output stream to write output

def main ( ) :
    # Main method to start the program

    inputStream = sys.stdin ; # Initialize input stream
    outputStream = sys.stdout ; # Initialize output stream

    s = input ( ) ; # Read the next input string

    # Check if the string contains both 'A' and 'B'
    if ( 'A' in s and 'B' in s ) :
        print ( "Yes" ) ; # Print "Yes" if both characters are present
    else :
        print ( "No" ) ; # Print "No" if either character is missing

if __name__ == "__main__" :
    main ( ) ; # Call the main method to start the program

