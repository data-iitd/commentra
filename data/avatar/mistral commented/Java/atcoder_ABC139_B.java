// Importing necessary classes for input and output
import java.io.PrintWriter ;
import java.util.Scanner ;

// Main method is the entry point of the Java application
public class Main {
    // Declare main method with String array as argument
    public static void main ( String [ ] args ) {
        // Initialize Scanner object to read input from standard input
        Scanner sc = new Scanner ( System.in ) ;

        // Read first integer input A from user
        int A = Integer.parseInt ( sc.next ( ) ) ;

        // Read second integer input B from user
        int B = Integer.parseInt ( sc.next ( ) ) ;

        // Initialize variables for storing remainders and result
        int amari = 0 ;
        int result = 0 ;

        // Calculate the result by dividing B by A - 1 and storing the quotient
        result = ( B - 1 ) / ( A - 1 ) ;

        // Calculate the remainder of B divided by A - 1 and store it in amari
        amari = ( B - 1 ) % ( A - 1 ) ;

        // Check if the remainder is not zero
        if ( amari != 0 ) {
            // If the remainder is not zero, increment the result by 1
            result += 1 ;
        }

        // Initialize PrintWriter object to write output to standard output
        PrintWriter out = new PrintWriter ( System.out ) ;

        // Write the result to the standard output
        out.println ( result ) ;

        // Close the Scanner object to release system resources
        sc.close ( ) ;

        // Flush the PrintWriter buffer to write the output immediately
        out.flush ( ) ;
    }
}
