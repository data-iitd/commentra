
# Importing the Scanner class for reading input
import java.util.Scanner ;

# Defining the main class
class Main:
    # Starting the main method
    def main ( self ) :
        in = java.util.Scanner ( System.in ) ; # Creating a new Scanner object to read input from the console
        
        n = in.next ( ).toCharArray ( ) ; # Reading a string from the console and converting it to a character array

        s = False ; # Initializing a boolean variable's' to false

        for i in range ( 0, n.length ) : # Starting a for loop to iterate through each character in the character array 'n'
            if ( n [ i ] == '.' ) : # Checking if the current character is a '.'
                if ( s ) : # If the boolean variable's' is true
                    print ( 1 ) ; # Printing '1' to the console
                    s = False ; # Setting the boolean variable's' to false
                else : # If the boolean variable's' is false
                    print ( 0 ) ; # Printing '0' to the console
            else : # If the current character is not a '.'
                if ( s ) : # If the boolean variable's' is true
                    print ( 2 ) ; # Printing '2' to the console
                    s = False ; # Setting the boolean variable's' to false
                else : # If the boolean variable's' is false
                    s = True ; # Setting the boolean variable's' to true

        in.close ( ) ; # Closing the Scanner object to free up system resources

# 