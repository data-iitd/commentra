// Import necessary Java packages
import java.util.Scanner; // For reading input
import java.io.*. // For handling input/output streams
import java.lang.Math.*; // For mathematical operations

// Main method is the entry point of the program
public class Main {

    // Initialize the scanner for reading input
    public static void main ( String [ ] args ) {
        Scanner scan = new Scanner ( System.in ) ;

        // Read the length of the array from the user input
        int len = scan.nextInt ( ) ;

        // Allocate memory for the array of integers
        int a [ ] = new int [ len ] ;

        // Read each integer from the user input and store it in the array
        for ( int i = 0 ; i < len ; i ++ ) {
            a [ i ] = scan.nextInt ( ) ;
        }

        // Initialize variables for left and right indices and a flag
        int l = 0 ;
        int r = 0 ;
        boolean flag = false ;

        // Start the loop to search for two non-consecutive numbers
        loop : for ( int i = 0 ; i < len ; i ++ ) {

            // Check if the current number is not in its correct position
            if ( a [ i ] != i + 1 && ! flag ) {
                // Update the left index
                l = i + 1 ;
                // Set the flag to true to indicate that we have found the first non-consecutive number
                flag = true ;
                // Continue to the next iteration of the loop
                continue ;
            }

            // Check if the current number is also not in its correct position and the flag is set
            if ( a [ i ] != i + 1 && flag ) {
                // Update the right index
                r = i + 1 ;

                // Check if the difference between the previous number and the current number is greater than 1
                if ( ( a [ r - 1 ] - a [ r - 2 ] > 0 ) ) {
                    // Set the isTrue flag to true if the condition is satisfied
                    isTrue = true ;
                    // Break out of the loop if the flag is set to true
                    break loop ;
                }
            }
        }

        // Print the result based on the value of the isTrue flag
        System.out.println ( ( ! isTrue ) ? l + " " + r : "0" + " " + "0" ) ;
    }
}
