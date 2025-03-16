import java.io.* ;  // Importing required Java packages for input and output
import java.util.* ;

public class Main {
    // Class declaration and initialization of static variables
    static int N = 200 + 10 ;  // Initializing the size of the arrays
    static int f [ ] = new int [ N ] ;  // Initializing the failure function array
    static char b [ ] = new char [ N ] ;  // Initializing the character arrays

    static void getFail ( char b [ ] , int m ) {
        // Function declaration and initialization of variables
        int j = 0 ;
        f [ 0 ] = f [ 1 ] = 0 ;  // Initializing the first two elements of the failure function array

        // Main logic of the function
        for ( int i = 2 ; i <= m ; i ++ ) {
            while ( j > 0 && b [ j + 1 ] != b [ i ] ) j = f [ j ] ;  // Searching for the longest common prefix of the current and previous strings
            if ( b [ j + 1 ] == b [ i ] ) j ++ ;  // If the characters match, move to the next character in the current string
            f [ i ] = j ;  // Updating the failure function for the current index
        }
    }

    public static void main ( String [ ] args ) {
        // Main function declaration and initialization of variables
        InputReader in = new InputReader ( System.in ) ;  // Creating an instance of the InputReader class for reading input
        PrintWriter out = new PrintWriter ( System.out ) ;  // Creating an instance of the PrintWriter class for writing output

        int n = in.nextInt ( ) ;  // Reading the number of characters in the strings
        String s1 = in.next ( ) , str = in.next ( ) ;  // Reading the two strings from the input

        int cnt = 0 ;  // Initializing a counter for the number of characters in the combined string

        // Concatenating the two strings and creating character arrays for each
        for ( int i = 0 ; i < n ; i ++ ) b [ ++ cnt ] = str.charAt ( i ) ;
        for ( int i = 0 ; i < n ; i ++ ) b [ ++ cnt ] = s1.charAt ( i ) ;

        getFail ( b , cnt ) ;  // Calling the getFail function to compute the failure function

        int len = Math.min ( f [ cnt ] , Math.min ( n , n ) ) ;  // Computing the length of the longest common prefix

        out.println ( 2 * n - len ) ;  // Writing the output to the console

        out.flush ( ) ;  // Flushing the output buffer
    }

    static class InputReader {
        // Class declaration and initialization of variables
        BufferedReader reader ;
        StringTokenizer tokenizer ;

        public InputReader ( InputStream stream ) {
            reader = new BufferedReader ( new InputStreamReader ( stream ) , 32768 ) ;
            tokenizer = null ;
        }

        // Function for reading strings from the input
        public String next ( ) {
            while ( tokenizer == null || ! tokenizer.hasMoreTokens ( ) ) {
                try {
                    tokenizer = new StringTokenizer ( reader.readLine ( ) ) ;
                } catch ( IOException e ) {
                    throw new RuntimeException ( e ) ;
                }
            }
            return tokenizer.nextToken ( ) ;
        }

        // Function for reading integers from the input
        public int nextInt ( ) {
            return Integer.parseInt ( next ( ) ) ;
        }
    }
}
