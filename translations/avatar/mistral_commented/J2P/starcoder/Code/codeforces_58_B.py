
import java.util.* ;  // Importing the utility class for handling collections and iterators
import java.lang.* ;  // Importing the core Java language classes
import java.io.* ;   // Importing the I/O classes

def main ( ):
    # Initializing the Scanner object to read input from the standard input stream
    sc = Scanner ( ) ;

    n = int ( input ( ) ) ;  # Reading the first number from the user input

    print ( n, end = " " ) ;  # Printing the first number to the standard output stream

    m = n ;  # Initializing an integer variable'm' with the value of 'n'

    # Finding the factors of the number 'n' using a for loop
    for i in range ( n - 1, 0, -1 ) :
        if ( m % i == 0 ) :  # Checking if 'i' is a factor of'm'
            print ( i, end = " " ) ;  # Printing the factor to the standard output stream
            m = i ;  # Updating the value of'm' with the current factor

    print ( "