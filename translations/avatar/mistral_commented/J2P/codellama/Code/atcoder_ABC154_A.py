#######
# Importing necessary Python libraries
#######
import sys

#######
# Main method is the entry point of the Python application
#######
def main ( ) :

    # Reading the first line of input as an array of strings
    str = sys.stdin.readline ( ).split ( )

    # Reading the second line of input as separate tokens
    a, b = map ( int, sys.stdin.readline ( ).split ( ) )

    # Reading the third line of input as a string
    u = sys.stdin.readline ( )

    # Checking if the first string from the first line matches with the given string 'u'
    if u == str [ 0 ] :

        # If the condition is true, then print the result as (a-1) and b
        print ( a - 1, b )

    else :

        # If the condition is false, then print the result as a and (b-1)
        print ( a, b - 1 )

#######
# Calling the main method to start the execution of the Python application
#######
if __name__ == "__main__" :
    main ( )

