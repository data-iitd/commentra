
import java.io.* ; 
import java.util.* ; 

public class Main { 
    static int N = 200 + 10 ; 
    static int f [ ] = new int [ N ] ; 
    static char b [ ] = new char [ N ] ; 
    
    // Computes the failure array for the given pattern
    static void getFail ( char b [ ] , int m ) { 
        int j = 0 ; 
        f [ 0 ] = f [ 1 ] = 0 ; 
        for ( int i = 2 ; i <= m ; i ++ ) { 
            while ( j > 0 && b [ j + 1 ] != b [ i ] ) 
                j = f [ j ] ; 
            if ( b [ j + 1 ] == b [ i ] ) 
                j ++ ; 
            f [ i ] = j ; 
        } 
    } 
    
    public static void main ( String [ ] args ) { 
        InputReader in = new InputReader ( System.in ) ; 
        PrintWriter out = new PrintWriter ( System.out ) ; 
        
        // Read input values
        int n = in.nextInt ( ) ; 
        String s1 = in.next ( ) ; 
        String str = in.next ( ) ; 
        
        // Construct a combined string
        int cnt = 0 ; 
        for ( int i = 0 ; i < n ; i ++ ) 
            b [ ++ cnt ] = str.charAt ( i ) ; 
        for ( int i = 0 ; i < n ; i ++ ) 
            b [ ++ cnt ] = s1.charAt ( i ) ; 
        
        // Compute the failure array for the combined string
        getFail ( b , cnt ) ; 
        
        // Calculate the result based on the failure array
        int len = Math.min ( f [ cnt ] , Math.min ( n , n ) ) ; 
        
        // Print the result
        out.println ( 2 * n - len ) ; 
        out.flush ( ) ; 
    } 
    
    static class InputReader { 
        public BufferedReader reader ; 
        public StringTokenizer tokenizer ; 
        
        // Constructor to initialize the input reader
        public InputReader ( InputStream stream ) { 
            reader = new BufferedReader ( new InputStreamReader ( stream ) , 32768 ) ; 
            tokenizer = null ; 
        } 
        
        // Read the next string from the input
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
        
        // Read the next integer from the input
        public int nextInt ( ) { 
            return Integer.parseInt ( next ( ) ) ; 
        } 
    } 
}