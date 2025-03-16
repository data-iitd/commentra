
# Importing the Java Util Library for Scanner class
import java.util.* ;

# Defining the Main class
class Main:
    # Creating a new Scanner object to read input from the console
    input = Scanner ( System.in ) ;

    # Defining the main method
    def main ( self ):
        n = input.nextInt ( ) ;  # Reading the first integer from the input as the size of the array

        arr = ArrayList ( ) ;  # Creating an empty ArrayList to store the indices of the 1's in the input

        for i in range ( n ):   # Loop through the input to find the indices of the 1's
            if ( input.nextInt ( ) == 1 ):
                arr.add ( i ) ;  # If the current input is 1, add its index to the ArrayList

        if ( arr.isEmpty ( ) ):   # Check if the ArrayList is empty
            print ( 0 ) ;  # If it is, print 0 as the output
        else:
            result = 1 ;  # Initialize the result variable to 1

            for i in range ( 1, arr.size ( ) ):  # Loop through the ArrayList to calculate the result
                result *= arr.get ( i ) - arr.get ( i - 1 ) ;  # Multiply the difference between two consecutive indices to the result

            print ( result ) ;  # Print the result as the output

# 