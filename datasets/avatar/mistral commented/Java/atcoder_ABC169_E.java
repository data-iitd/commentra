
import java.util.* ;  // Importing necessary utility classes
import java.io.* ;

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String [ ] args ) throws Exception {
        int num = 998244353 ;  // Initializing a variable 'num' with a value
        BufferedReader bf = new BufferedReader ( new InputStreamReader ( System.in ) ) ;  // Creating a BufferedReader object to read input from the standard input stream
        PrintWriter out = new PrintWriter ( System.out ) ;  // Creating a PrintWriter object to write output to the standard output stream

        int n = Integer.parseInt ( bf.readLine ( ) ) ;  // Reading the number of test cases from the input
        ArrayList < Integer > ai = new ArrayList < Integer > ( ) ;  // Creating an empty ArrayList to store the first array elements
        ArrayList < Integer > bi = new ArrayList < Integer > ( ) ;  // Creating an empty ArrayList to store the second array elements

        for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through the test cases
            StringTokenizer st = new StringTokenizer ( bf.readLine ( ) ) ;  // Creating a StringTokenizer object to parse the input line
            ai.add ( Integer.parseInt ( st.nextToken ( ) ) ) ;  // Adding the first array element to the ArrayList
            bi.add ( Integer.parseInt ( st.nextToken ( ) ) ) ;  // Adding the second array element to the ArrayList
        }

        // Sorting the ArrayLists in ascending order
        Collections.sort ( ai ) ;
        Collections.sort ( bi ) ;

        if ( n % 2 == 1 ) {  // Checking if the number of test cases is odd
            out.println ( bi.get ( bi.size ( ) / 2 ) - ai.get ( ai.size ( ) / 2 ) + 1 ) ;  // Calculating and printing the answer for odd number of test cases
            out.close ( ) ;  // Closing the PrintWriter object
        } else {
            double b = ( ai.get ( ai.size ( ) / 2 ) + ai.get ( ai.size ( ) / 2 - 1 ) + 0.0 ) / 2 ;  // Calculating the average of the middle two elements of the first ArrayList
            double c = ( bi.get ( bi.size ( ) / 2 ) + bi.get ( bi.size ( ) / 2 - 1 ) + 0.0 ) / 2 ;  // Calculating the average of the middle two elements of the second ArrayList
            out.println ( ( int ) ( 2 * ( c - b ) + 1 ) ) ;  // Calculating and printing the answer for even number of test cases
            out.close ( ) ;  // Closing the PrintWriter object
        }
    }
}

These comments should provide a clear understanding of the code logic for anyone who reads it.