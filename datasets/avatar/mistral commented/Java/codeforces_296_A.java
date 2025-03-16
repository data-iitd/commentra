
import java.io.* ;  // Importing required Java classes for input and output
import java.util.StringTokenizer ;

public class Main {
    public static void main ( String [ ] args ) {  // Main method to start the program
        InputStream inputStream = System.in ;   // Creating input stream from standard input
        OutputStream outputStream = System.out ; // Creating output stream to standard output
        InputReader in = new InputReader ( inputStream ) ; // Creating InputReader object for reading input
        PrintWriter out = new PrintWriter ( outputStream ) ; // Creating PrintWriter object for writing output
        Task solver = new Task ( ) ;              // Creating Task object to solve the problem
        solver.solve ( in , out ) ;               // Calling the solve method of Task object to solve the problem
        out.close ( ) ;                           // Closing the output stream
    }

    static class Task {
        public void solve ( InputReader in , PrintWriter out ) { // Method to solve the problem
            int n = in.nextInt ( ) ;                          // Reading the number of elements in the array
            int [ ] array = new int [ 1001 ] ;                  // Creating an array of size 1001 to store the frequency of each element
            for ( int i = 0 ; i < n ; i ++ ) {                  // Loop to read and store the elements in the array
                int index = in.nextInt ( ) ;
                array [ index ] ++ ;                           // Incrementing the frequency of the element at the given index
            }
            int countMax = - 1 ;                               // Initializing the maximum frequency to -1
            for ( int i = 1 ; i < array.length ; i ++ ) {       // Loop to find the maximum frequency
                if ( countMax < array [ i ] ) countMax = array [ i ] ;
            }
            if ( n % 2 == 0 ) {                                // Checking if the number of elements is even
                if ( countMax <= n / 2 ) {                     // If the maximum frequency is less than or equal to half of the number of elements
                    out.println ( "YES" ) ;                   // Printing "YES" as the output
                } else {
                    out.println ( "NO" ) ;                    // Else printing "NO" as the output
                }
            } else {                                           // If the number of elements is odd
                if ( countMax <= n / 2 + 1 ) {                 // If the maximum frequency is less than or equal to half of the number of elements plus one
                    out.println ( "YES" ) ;                   // Printing "YES" as the output
                } else {
                    out.println ( "NO" ) ;                    // Else printing "NO" as the output
                }
            }
        }
    }

    static class InputReader {
        BufferedReader reader ;
        StringTokenizer tokenizer ;

        public InputReader ( InputStream stream ) {
            reader = new BufferedReader ( new InputStreamReader ( stream ) , 32768 ) ; // Creating BufferedReader object for reading input
        }

        String next ( ) {
            while ( tokenizer == null || ! tokenizer.hasMoreElements ( ) ) {
                try {
                    tokenizer = new StringTokenizer ( reader.readLine ( ) ) ; // Creating StringTokenizer object for tokenizing the input line
                } catch ( IOException e ) {
                    throw new RuntimeException ( e ) ;
                }
            }
            return tokenizer.nextToken ( ) ;
        }

        int nextInt ( ) {
            return Integer.parseInt ( next ( ) ) ;
        }

        long nextLong ( ) {
            return Long.parseLong ( next ( ) ) ;
        }

        double nextDouble ( ) {
            return Double.parseDouble ( next ( ) ) ;
        }

        String nextLine ( ) {
            String str = "" ;
            try {
                str = reader.readLine ( ) ;
            } catch ( IOException e ) {
                e.printStackTrace ( ) ;
            }
            return str ;
        }
    }
}

These comments should provide a clear understanding of the logic behind each block of code.