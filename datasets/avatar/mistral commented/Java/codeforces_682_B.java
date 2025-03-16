
import java.io.* ;  // Importing necessary classes for input and output
import java.util.* ;  // Importing necessary classes for ArrayList and Collections

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String [ ] args ) {
        // Creating scanner object for reading input from the standard input
        Scanner in = new Scanner ( System.in ) ;
        // Creating print writer object for writing output to the standard output
        PrintWriter pw = new PrintWriter ( System.out ) ;

        // Reading the number of elements in the list from the input
        int n = in.nextInt ( ) ;

        // Creating an ArrayList of size 'n' to store the elements
        ArrayList < Integer > list = new ArrayList < > ( n ) ;

        // Reading 'n' elements from the input and adding them to the ArrayList
        for ( int i = 0 ; i < n ; i ++ ) {
            list.add ( in.nextInt ( ) ) ;  // Reading an integer from the input and adding it to the ArrayList
        }

        // Sorting the ArrayList in ascending order using Collections.sort() method
        Collections.sort ( list ) ;

        // Initializing a variable 'c' to keep track of the number of distinct elements
        int c = 1 ;

        // Iterating through the ArrayList to find the number of distinct elements
        for ( int i = 0 ; i < n ; i ++ ) {
            // If the current element is greater than or equal to the current count 'c', increment the count
            if ( list.get ( i ) >= c ) {
                c ++ ;
            }
        }

        // Writing the result to the output
        pw.println ( c ) ;

        // Closing the print writer object
        pw.close ( ) ;

        // Debugging method to print the deep toString representation of an object
        static void debug ( Object...obj ) {
            System.err.println ( Arrays.deepToString ( obj ) ) ;
        }
    }
}