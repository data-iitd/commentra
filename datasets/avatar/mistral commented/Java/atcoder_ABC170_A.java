// Importing necessary Java classes for reading input from the console and writing output to the console
import java.io.BufferedReader ;
import java.io.IOException ;
import java.io.PrintWriter ;

// Main method is the entry point of the Java application
public class Main {

    // Main method takes command line arguments as a String array
    public static void main ( String [ ] args ) throws IOException {

        // Creating BufferedReader object to read input from the console
        BufferedReader br = new BufferedReader( new java.io.InputStreamReader( System.in ) ) ;

        // Creating PrintWriter object to write output to the console
        PrintWriter pw = new PrintWriter( System.out ) ;

        // Reading input array from the console
        String [ ] input_array = br.readLine().split(" ") ;

        // Initializing result variable to 0
        int result = 0 ;

        // Iterating through each string in the input array
        for ( String str : input_array ) {

            // Incrementing result variable for each non-zero string encountered
            result++ ;

            // Breaking the loop if a zero string is encountered
            if ( "0".equals( str ) ) break ;
        }

        // Writing the result to the console
        pw.println( result ) ;

        // Closing the BufferedReader and PrintWriter objects
        br.close() ;
        pw.close() ;
    }
}
