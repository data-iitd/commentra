
import java.util.* ;  // Importing the utility class for handling collections and iterators
import java.lang.* ;  // Importing the core Java language classes
import java.io.* ;   // Importing the I/O classes

public class Main {

    public static void main ( String [ ] args ) throws java.lang.Exception {
         // Initializing the Scanner object to read input from the standard input stream
        Scanner sc = new Scanner ( System.in ) ;

        int n ;  // Declaring an integer variable to store the first number

        // Reading the first number from the user input
        n = sc.nextInt ( ) ;

        System.out.println ( n + " " ) ;  // Printing the first number to the standard output stream

        int m = n ;  // Initializing an integer variable 'm' with the value of 'n'

        // Finding the factors of the number 'n' using a for loop
        for ( int i = n - 1 ; i > 0 ; i -- ) {
            if ( m % i == 0 ) {  // Checking if 'i' is a factor of 'm'
                System.out.println ( i + " " ) ;  // Printing the factor to the standard output stream
                m = i ;  // Updating the value of 'm' with the current factor
            }
        }
    }
}

These comments should provide a clear understanding of the code's functionality and logic. Let me know if you need any further assistance.