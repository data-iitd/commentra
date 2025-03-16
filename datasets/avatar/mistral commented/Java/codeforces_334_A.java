
import java.io.* ;  // Importing required packages for input and output
import java.util.* ;  // Importing required package for ArrayList

public class Main {

    public static void main ( String [ ] args ) {
         // Initializing scanner for input and PrintWriter for output
        Scanner in = new Scanner ( System.in ) ;
        PrintWriter pw = new PrintWriter ( System.out ) ;

        int n = in.nextInt ( ) ;  // Reading the number 'n' from the user

        int square = n * n ;  // Calculating the square of the number 'n'

        ArrayList < Integer > odd = new ArrayList < > ( ) ;  // Creating an empty ArrayList for odd numbers
        ArrayList < Integer > even = new ArrayList < > ( ) ;  // Creating an empty ArrayList for even numbers

        for ( int i = 1 ; i <= square ; i ++ ) {  // Looping from 1 to square
            if ( i % 2 == 0 ) {  // If the number is even
                even.add ( i ) ;  // Add the number to the even ArrayList
            } else {  // If the number is odd
                odd.add ( i ) ;  // Add the number to the odd ArrayList
            }
        }

        int loop = square / n ;  // Calculating the number of pairs to be printed
        int div = loop / 2 ;  // Calculating half of the number of pairs

        for ( int i = 1 ; i <= loop ; i ++ ) {  // Looping through each pair
            for ( int j = 0 ; j < div ; j ++ ) {  // Looping through half of the pair
                if ( i % 2 == 1 ) {  // If the current pair is odd
                    pw.print ( odd.remove ( 0 ) + " " + ( even.remove ( even.size ( ) - 1 ) ) + " " ) ;  // Print the first and last numbers of the current pair
                } else {  // If the current pair is even
                    pw.print ( even.remove ( 0 ) + " " + ( odd.remove ( odd.size ( ) - 1 ) ) + " " ) ;  // Print the last and first numbers of the current pair
                }
            }
            pw.println ( ) ;  // Printing a newline after each pair
        }

        pw.close ( ) ;  // Closing the PrintWriter after printing all the pairs
    }

    static void debug ( Object...obj ) {  // Debugging method to print the contents of an array
        System.err.println ( Arrays.deepToString ( obj ) ) ;
    }
}