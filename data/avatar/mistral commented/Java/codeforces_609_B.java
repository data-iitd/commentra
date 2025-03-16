// Importing the required utility class Scanner from the Java standard library
import java.util.Scanner ;

// Main method is the entry point of the Java application
public class Main {

    // Initializing the main method with an empty string array as arguments
    public static void main ( String [ ] args ) {

        // Creating a new Scanner object to read input from the standard input stream
        Scanner in = new Scanner ( System.in ) ;

        // Reading the first integer input n from the user
        int n = in.nextInt ( ) ;

        // Reading the second integer input m from the user
        int m = in.nextInt ( ) ;

        // Creating an integer array arr of size n to store the input integers
        int arr [ ] = new int [ n ] ;

        // Creating an integer array gen of size 11 to store the count of each integer occurrence
        int gen [ ] = new int [ 11 ] ;

        // Reading the input integers and storing them in the arr array
        for ( int i = 0 ; i < n ; i ++ ) {
            arr [ i ] = in.nextInt ( ) ;
            // Incrementing the count of the arr[i] in the gen array
            gen [ arr [ i ] ] ++ ;
        }

        // Calculating the answer
        long ans = 0 ;
        for ( int i = 1 ; i <= m ; i ++ ) {
            for ( int k = 1 ; k <= m ; k ++ ) {
                // Skipping the case when i and k are equal to avoid double counting
                if ( i != k ) {
                    // Multiplying the count of i and k and adding it to the answer
                    ans += ( long ) gen [ i ] * gen [ k ] ;
                }
            }
        }

        // Printing the answer divided by 2
        System.out.println ( ans / 2 ) ;
    }
}
