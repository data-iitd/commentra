// Import necessary Java utility classes
import java.util.ArrayList ;
import java.util.Scanner ;

// Main method is the entry point of the Java application
public class Main {
    // Declare main method that takes command line arguments
    public static void main ( String [ ] args ) {
        // Initialize Scanner to read input from the standard input
        Scanner input = new Scanner ( System.in ) ;

        // Read the number of requests and preemptions from the input
        int n = input.nextInt ( ) ;
        int m = input.nextInt ( ) ;

        // Create ArrayLists to store request and preemption indices
        ArrayList < Integer > req = new ArrayList < Integer > ( ) ;
        ArrayList < Integer > pre = new ArrayList < Integer > ( ) ;

        // Read request indices and store them in the ArrayList
        for ( int i = 0 ; i < n ; i ++ ) {
            req.add ( input.nextInt ( ) ) ;
            // Comment: Read and store request index i
        }

        // Read preemption indices and store them in the ArrayList
        for ( int i = 0 ; i < m ; i ++ ) {
            pre.add ( input.nextInt ( ) ) ;
            // Comment: Read and store preemption index i
        }

        // Initialize index variables for requests and preemptions
        int i = n - 1 ;
        int j = m - 1 ;

        // Initialize answer variable
        int ans = 0 ;

        // While there are still requests and preemptions to compare
        while ( i >= 0 && j >= 0 ) {
            // If the current request can preempt the current preemption
            if ( req.get ( i ) > pre.get ( j ) ) {
                // Increment answer variable
                ans ++ ;
            } else {
                // Decrement preemption index
                j -- ;
            }
            // Decrement request index
            i -- ;
        }

        // Print the answer and the number of remaining requests
        System.out.print ( ans + i + 1 ) ;
    }
}
