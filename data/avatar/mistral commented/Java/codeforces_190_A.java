// Importing necessary classes for file I/O and collections
import java.io.* ;
import java.util.* ;

// Main method is the entry point of the Java application
public class Main {
    // Declaring a static variable named 'sc' of Scanner class
    // to read input from the standard input stream
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;

        // Reading the first integer 'n' from the standard input
        int n = sc.nextInt ( ) ;

        // Reading the second integer 'm' from the standard input
        int m = sc.nextInt ( ) ;

        // Checking if 'n' is equal to zero
        if ( n == 0 ) {
            // If 'm' is not equal to zero, print "Impossible"
            if ( m != 0 ) {
                System.out.println ( "Impossible" ) ;
            } else { // If 'm' is also zero, print '0' space '0'
                System.out.println ( 0 + " " + 0 ) ;
            }
            // Returning from the main method
            return ;
        }

        // Checking if 'm' is less than or equal to 'n'
        if ( m <= n ) {
            // If 'm' is zero, assign it the value 1
            if ( m == 0 ) {
                m = 1 ;
            }
            // Printing 'n' and the sum of 'm' and 'n' minus one
            System.out.print ( n + " " + ( m + n - 1 ) ) ;
            // Returning from the main method
            return ;
        }

        // If 'm' is greater than 'n', print 'm' and the sum of 'm' and 'n' minus one
        System.out.print ( m + " " + ( m + n - 1 ) ) ;
    }
}
