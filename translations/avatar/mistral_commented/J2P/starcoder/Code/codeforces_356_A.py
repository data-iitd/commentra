
import java.util.*;
import java.io.*;

public class Main {

    public static void main ( String [ ] args ) throws Exception {
        // Initializing FastReader for reading input
        FastReader in = new FastReader ( ) ;

        int n = in.nextInt ( ) ;  // Reading the number of elements in the array

        TreeSet < Integer > left = new TreeSet < > ( ) ;  // Creating a TreeSet to store the indices of elements in the sorted order
        int [ ] answer = new int [ n ] ;  // Creating an array to store the answer for each index

        // Adding all the indices to the TreeSet and initializing the answer array with -1
        for ( int i = 0 ; i < n ; i ++ ) {
            left.add ( i ) ;
            answer [ i ] = -1 ;
        }

        int q = in.nextInt ( ) ;  // Reading the number of queries

        // Processing each query
        while ( q -- > 0 ) {
            int l = in.nextInt ( ) - 1 ;  // Reading the left index of the query range
            int r = in.nextInt ( ) - 1 ;  // Reading the right index of the query range
            int win = in.nextInt ( ) ;  // Reading the winning index

            // Updating the answer for the winning index and all the indices between the left and right indices
            while ( left.ceiling ( l )!= null && left.ceiling ( l ) <= r ) {
                int curr = left.ceiling ( l ) ;
                answer [ curr ] = win ;
                left.remove ( curr ) ;
            }

            // Updating the answer for the winning index in the answer array
            answer [ win - 1 ] = 0 ;

            // Adding the winning index back to the TreeSet
            left.add ( win - 1 ) ;
        }

        StringBuilder ans = new StringBuilder ( ) ;  // Creating a StringBuilder to store the answer as a string

        // Printing the answer for each index in the answer array
        for ( int i = 0 ; i < n ; i ++ ) {
            ans.append ( answer [ i ] + "" ) ;
            if ( i!= n - 1 ) {
                ans.append ( " " ) ;
            }
        }

        System.out.println ( ans ) ;  // Printing the answer as a single line
    }

    static class FastReader {
        StringTokenizer st ;  // Creating a StringTokenizer for reading input tokens
        BufferedReader br ;  // Creating a BufferedReader for reading input lines

        public FastReader ( ) {
            br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
        }

        String next ( ) {
            while ( st == null ||! st.hasMoreElements ( ) ) {
                try {
                    st = new StringTokenizer ( br.readLine ( ) ) ;
                } catch ( IOException e ) {
                    e.printStackTrace ( ) ;
                }
            }
            return st.nextToken ( ) ;
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
            String s = "" ;
            while ( st == null || st.hasMoreElements ( ) ) {
                try {
                    s = br.readLine ( ) ;
                } catch ( IOException e ) {
                    e.printStackTrace ( ) ;
                }
            }
            return s ;
        }
    }
}

