import java.util.* ; 
import java.io.* ; 

public class Main { 
    public static void main ( String [ ] args ) throws Exception { 
        FastReader in = new FastReader ( ) ; // Initialize FastReader for fast input
        int n = in.nextInt ( ) ; // Read the value of n
        TreeSet < Integer > left = new TreeSet < > ( ) ; // Initialize a TreeSet to keep track of indices
        int [ ] answer = new int [ n ] ; // Initialize an array to store the results
        for ( int i = 0 ; i < n ; i ++ ) { 
            left.add ( i ) ; // Add indices from 0 to n-1 to the TreeSet
        }
        int q = in.nextInt ( ) ; // Read the number of queries
        while ( q -- > 0 ) { // Process each query
            int l = in.nextInt ( ) - 1 ; // Read the left index and adjust for 0-based indexing
            int r = in.nextInt ( ) - 1 ; // Read the right index and adjust for 0-based indexing
            int win = in.nextInt ( ) ; // Read the winning index
            while ( left.ceiling ( l ) != null && left.ceiling ( l ) <= r ) { // While there are elements in the range
                int curr = left.ceiling ( l ) ; // Get the smallest element in the range
                answer [ curr ] = win ; // Assign the winning index to the current element
                left.remove ( curr ) ; // Remove the current element from the TreeSet
            }
            answer [ win - 1 ] = 0 ; // Set the winning index (adjusted for 0-based indexing) to 0
            left.add ( win - 1 ) ; // Add the winning index back to the TreeSet
        }
        StringBuilder ans = new StringBuilder ( ) ; // Initialize a StringBuilder for efficient string concatenation
        for ( int i = 0 ; i < n ; i ++ ) { 
            ans.append ( answer [ i ] + "" ) ; // Append each element of the answer array to the StringBuilder
        }
        System.out.println ( ans ) ; // Print the final result
    } 

    static class FastReader { 
        StringTokenizer st ; 
        BufferedReader br ; 
        public FastReader ( ) { 
            br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; // Initialize BufferedReader
        } 
        String next ( ) { 
            while ( st == null || ! st.hasMoreElements ( ) ) { 
                try { 
                    st = new StringTokenizer ( br.readLine ( ) ) ; // Read the next line
                } catch ( IOException e ) { 
                    e.printStackTrace ( ) ; 
                } 
            } 
            return st.nextToken ( ) ; // Return the next token
        } 
        int nextInt ( ) { 
            return Integer.parseInt ( next ( ) ) ; // Parse the next token as an integer
        } 
        long nextLong ( ) { 
            return Long.parseLong ( next ( ) ) ; // Parse the next token as a long
        } 
        double nextDouble ( ) { 
            return Double.parseDouble ( next ( ) ) ; // Parse the next token as a double
        } 
        String nextLine ( ) { 
            String s = "" ; 
            while ( st == null || st.hasMoreElements ( ) ) { 
                try { 
                    s = br.readLine ( ) ; // Read the next line
                } catch ( IOException e ) { 
                    e.printStackTrace ( ) ; 
                } 
            } 
            return s ; // Return the next line
        } 
    } 
}
