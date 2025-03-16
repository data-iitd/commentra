
import java.util.* ;  // Importing the utility classes for collections and input/output
import java.io.* ;

public class Main {
    static TreeSet < Long > set ;  // Declaring a set to store unique elements

    public static void main ( String [ ] args ) {
        Scanner in = new Scanner ( System.in ) ;  // Creating a scanner object to read input
        PrintWriter pw = new PrintWriter ( System.out ) ;  // Creating a print writer object to write output

        int n = in.nextInt ( ) ;  // Reading the number of elements in the array
        long [ ] a = new long [ n ] ;  // Creating an array of size n to store the elements

        for ( int i = 0 ; i < n ; i ++ ) {  // Loop to read the elements of the array from the input
            a [ i ] = in.nextLong ( ) ;
        }

        long [ ] dp = new long [ n + 1 ] ;  // Creating an array of size n+1 to store the maximum subarray sum ending at each index
        Arrays.fill ( dp , - 1 ) ;  // Initializing all the elements of the dp array with -1
        dp [ n - 1 ] = a [ n - 1 ] ;  // Setting the last element of the dp array with the last element of the array

        for ( int i = n - 1 ; i >= 0 ; i -- ) {  // Loop to calculate the maximum subarray sum ending at each index
            dp [ i ] = Math.max ( dp [ i + 1 ] , a [ i ] ) ;
        }

        for ( int i = 0 ; i < n ; i ++ ) {  // Loop to print the answer for each test case
            if ( a [ i ] > dp [ i + 1 ] ) {  // If the current element is greater than the maximum subarray sum ending at next index
                pw.print ( 0 + " " ) ;  // Print 0 as the answer
            } else {
                pw.print ( ( dp [ i + 1 ] - a [ i ] + 1 ) + " " ) ;  // Else print the length of the subarray ending at current index
            }
        }

        pw.println ( ) ;  // Printing a newline character at the end of the output
        pw.close ( ) ;  // Closing the print writer object

        set = new TreeSet < Long > ( ) ;  // Initializing the set to store unique elements

        debug ( a ) ;  // Debugging the array elements
    }

    static void debug ( Object...obj ) {  // Debugging method to print the array in a readable format
        System.err.println ( Arrays.deepToString ( obj ) ) ;
    }
}

These comments should provide a clear understanding of the code logic and the purpose of each block.