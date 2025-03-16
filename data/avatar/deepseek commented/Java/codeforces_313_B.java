import java.io.* ; 
import java.util.StringTokenizer ; 

public class Main { 
    public static void main ( String [ ] args ) throws IOException { 
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        PrintWriter pw = new PrintWriter ( new OutputStreamWriter ( System.out ) ) ; 
        Fast f = new Fast ( ) ; 
        f.sol ( br , pw ) ; 
        pw.close ( ) ; 
    } 
} 

class Fast { 
    public void sol ( BufferedReader br , PrintWriter pw ) throws IOException { 
        // Read the input string
        StringTokenizer st = new StringTokenizer ( br.readLine ( ) ) ; 
        String s = st.nextToken ( ) ; 
        
        // Initialize the cumulative array to store counts of consecutive identical characters
        Integer cum [ ] = new Integer [ s.length ( ) + 1 ] ; 
        cum [ 0 ] = cum [ s.length ( ) ] = 0 ; 
        
        // Fill the cumulative array with counts of consecutive identical characters
        for ( int i = 1 ; i < s.length ( ) ; i ++ ) { 
            if ( s.charAt ( i ) == s.charAt ( i - 1 ) ) 
                cum [ i ] = cum [ i - 1 ] + 1 ; 
            else 
                cum [ i ] = cum [ i - 1 ] ; 
        } 
        
        // Read the number of queries
        st = new StringTokenizer ( br.readLine ( ) ) ; 
        Integer q = Integer.parseInt ( st.nextToken ( ) ) ; 
        
        // Process each query
        while ( q -- != 0 ) { 
            st = new StringTokenizer ( br.readLine ( ) ) ; 
            Integer l = Integer.parseInt ( st.nextToken ( ) ) ; 
            Integer r = Integer.parseInt ( st.nextToken ( ) ) - 1 ; 
            
            // Calculate and print the result for the query
            pw.println ( cum [ r ] - cum [ l - 1 ] ) ; 
        } 
    } 
}
