
import sys ; # Importing the sys module for reading input

def main ( ) : # Starting the main function
    n = sys.stdin.readline ( ).strip ( ) ; # Reading a string from the console and removing any leading or trailing whitespace

    s = False ; # Initializing a boolean variable's' to false

    for i in range ( len ( n ) ) : # Starting a for loop to iterate through each character in the string 'n'
        if n [ i ] == '.' : # Checking if the current character is a '.'
            if s : # If the boolean variable's' is true
                print ( 1, end = '' ) ; # Printing '1' to the console without a newline character
                s = False ; # Setting the boolean variable's' to false
            else : # If the boolean variable's' is false
                print ( 0, end = '' ) ; # Printing '0' to the console without a newline character
        else : # If the current character is not a '.'
            if s : # If the boolean variable's' is true
                print ( 2, end = '' ) ; # Printing '2' to the console without a newline character
                s = False ; # Setting the boolean variable's' to false
            else : # If the boolean variable's' is false
                s = True ; # Setting the boolean variable's' to true

if __name__ == '__main__' : # Starting the main block
    main ( ) ; # Calling the main function

