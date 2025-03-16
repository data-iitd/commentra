import java.io.* ; // Importing necessary I/O libraries for file handling and other operations
import java.util.StringTokenizer ; // Importing the StringTokenizer class for tokenizing strings

public class Main {
    public static void main ( String [ ] args ) {
        InputStream inputStream = System.in ; // Setting up input stream
        OutputStream outputStream = System.out ; // Setting up output stream
        InputReader in = new InputReader ( inputStream ) ; // Creating an InputReader object to read input
        PrintWriter out = new PrintWriter ( outputStream ) ; // Creating a PrintWriter object to write output
        Task solver = new Task ( ) ; // Creating an instance of the Task class
        solver.solve ( in , out ) ; // Calling the solve method of the Task class
        out.close ( ) ; // Closing the output stream
    }

    static class Task {
        public void solve ( InputReader in , PrintWriter out ) {
            int n = in.nextInt ( ) ; // Reading the number of elements
            int [ ] array = new int [ 1001 ] ; // Initializing an array to count occurrences
            for ( int i = 0 ; i < n ; i ++ ) { // Looping through each element
                int index = in.nextInt ( ) ; // Reading the current element
                array [ index ] ++ ; // Incrementing the count of the current element
            }
            int countMax = - 1 ; // Initializing the maximum count to -1
            for ( int i = 1 ; i < array.length ; i ++ ) { // Looping through the array to find the maximum count
                if ( countMax < array [ i ] ) countMax = array [ i ] ; // Updating the maximum count if necessary
            }
            if ( n % 2 == 0 ) { // Checking if n is even
                if ( countMax <= n / 2 ) { // Checking if the maximum count is less than or equal to half of n
                    out.println ( "YES" ) ; // Printing "YES" if the condition is met
                } else {
                    out.println ( "NO" ) ; // Printing "NO" if the condition is not met
                }
            } else { // If n is odd
                if ( countMax <= n / 2 + 1 ) { // Checking if the maximum count is less than or equal to half of n rounded up
                    out.println ( "YES" ) ; // Printing "YES" if the condition is met
                } else {
                    out.println ( "NO" ) ; // Printing "NO" if the condition is not met
                }
            }
        }
    }

    static class InputReader {
        BufferedReader reader ; // Declaring a BufferedReader object
        StringTokenizer tokenizer ; // Declaring a StringTokenizer object
        public InputReader ( InputStream stream ) {
            reader = new BufferedReader ( new InputStreamReader ( stream ) , 32768 ) ; // Initializing the BufferedReader
        }
        String next ( ) {
            while ( tokenizer == null || ! tokenizer.hasMoreElements ( ) ) { // Checking if there are more tokens
                try {
                    tokenizer = new StringTokenizer ( reader.readLine ( ) ) ; // Reading the next line and tokenizing it
                } catch ( IOException e ) {
                    throw new RuntimeException ( e ) ; // Throwing an exception if an error occurs
                }
            }
            return tokenizer.nextToken ( ) ; // Returning the next token
        }
        int nextInt ( ) {
            return Integer.parseInt ( next ( ) ) ; // Parsing the next token as an integer
        }
        long nextLong ( ) {
            return Long.parseLong ( next ( ) ) ; // Parsing the next token as a long
        }
        double nextDouble ( ) {
            return Double.parseDouble ( next ( ) ) ; // Parsing the next token as a double
        }
        String nextLine ( ) {
            String str = "" ; // Initializing an empty string
            try {
                str = reader.readLine ( ) ; // Reading the next line
            } catch ( IOException e ) {
                e.printStackTrace ( ) ; // Printing the stack trace if an error occurs
            }
            return str ; // Returning the read line
        }
    }
}
