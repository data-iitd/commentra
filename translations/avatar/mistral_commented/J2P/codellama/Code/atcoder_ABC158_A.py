
import sys

def main ( ) :
    # Main method to start the program

    inputStream = sys.stdin ; # Initialize input stream
    outputStream = sys.stdout ; # Initialize output stream
    in = inputStream.readline ( ) ; # Read the next input string

    # Check if the string contains both 'A' and 'B'
    if ( "A" in in and "B" in in ) :
        outputStream.write ( "Yes" + "\n" ) ; # Print "Yes" if both characters are present
    else :
        outputStream.write ( "No" + "\n" ) ; # Print "No" if either character is missing

    outputStream.close ( ) ; # Close the output stream

if ( __name__ == "__main__" ) :
    main ( ) ; # Call the main method

