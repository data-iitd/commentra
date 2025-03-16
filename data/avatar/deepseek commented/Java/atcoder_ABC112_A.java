
import java.io.* ; 
import java.util.* ; 
import java.util.stream.* ; 

public class Main { 
    private static BufferedReader br = null ; 

    public static void main ( String [ ] args ) { 
        // Reading the number of inputs
        int n = Integer.parseInt ( read ( 1 ) [ 0 ] ) ; 

        // Processing the input based on the value of n
        if ( n == 1 ) { 
            // Outputting "Hello World" if n is 1
            System.out.println ( "Hello World" ) ; 
        } else { 
            // Reading two strings and calculating their sum if n is not 1
            String [ ] strs = read ( 2 ) ; 
            System.out.println ( Integer.parseInt ( strs [ 0 ] ) + Integer.parseInt ( strs [ 1 ] ) ) ; 
        } 
    } 

    // Method to read input from the standard input stream
    private static String [ ] read ( int len ) { 
        List < String > strList = new ArrayList < > ( ) ; 
        try { 
            if ( br == null ) { 
                br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
            } 
            for ( int i = 0 ; i < len ; i ++ ) { 
                strList.add ( br.readLine ( ) ) ; 
            } 
        } catch ( IOException e ) { 
            // Handle the exception if an I/O error occurs
        } 
        return strList.toArray ( new String [ 0 ] ) ; 
    } 

    // Method to close the BufferedReader if it is open
    private static void close ( ) { 
        try { 
            if ( br != null ) { 
                br.close ( ) ; 
            } 
        } catch ( IOException e ) { 
            // Handle the exception if an I/O error occurs
        } 
    } 
}
