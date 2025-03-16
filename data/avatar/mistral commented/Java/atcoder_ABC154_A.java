#######
// Importing necessary Java libraries
#######
import java.io.BufferedReader ;
import java.io.InputStreamReader ;
import java.io.IOException ;
import java.util.* ;

#######
// Main method is the entry point of the Java application
#######
public class Main {

    // Main method starts the execution of the Java application
    public static void main ( String [ ] args ) throws IOException {

        // Creating a BufferedReader object to read input from the console
        BufferedReader in = new BufferedReader ( new InputStreamReader ( System.in ) ) ;

        // Reading the first line of input as an array of strings
        String [ ] str = in.readLine ( ).split ( " " ) ;

        // Creating a StringTokenizer object to read the second line of input as separate tokens
        StringTokenizer st = new StringTokenizer ( in.readLine ( ) ) ;

        // Reading the first two integers as input
        int a = Integer.parseInt ( st.nextToken ( ) ) ;
        int b = Integer.parseInt ( st.nextToken ( ) ) ;

        // Reading the third line of input as a string
        String u = in.readLine ( ) ;

        // Checking if the first string from the first line matches with the given string 'u'
        if ( u.equals ( str [ 0 ] ) ) {

            // If the condition is true, then print the result as (a-1) and b
            System.out.println ( ( a - 1 ) + " " + b ) ;

        } else {

            // If the condition is false, then print the result as a and (b-1)
            System.out.println ( a + " " + ( b - 1 ) ) ;
        }

        // Closing the BufferedReader object to release the system resources
        in.close ( ) ;
    }
}
