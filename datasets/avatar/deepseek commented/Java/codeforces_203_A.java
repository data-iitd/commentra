import java.io.* ; 
import java.util.* ; 

public class Main { 
    private void solve ( ) { 
        // Reading the number of test cases (t) and other required values
        int x = nextInt ( ) ; // Target value x
        int t = nextInt ( ) ; // Number of test cases (unused in this code)
        int a = nextInt ( ) ; // Value a
        int b = nextInt ( ) ; // Value b
        int da = nextInt ( ) ; // Difference a (da)
        int db = nextInt ( ) ; // Difference b (db)
        
        // Variables to store calculated values
        int first ; 
        int second ; 
        
        // Flag to determine if a solution is found
        boolean ok = false ; 
        
        // Nested loop to calculate possible values of first and second
        for ( int i = 0 ; i < t ; i ++ ) { 
            first = a - ( da * i ) ; // Calculate first value
            for ( int j = 0 ; j < t ; j ++ ) { 
                second = b - ( db * j ) ; // Calculate second value
                if ( second + first == x || second == x || first == x || x == 0 ) { 
                    // Check if the sum of first and second equals x, or if either value equals x, or if x is zero
                    ok = true ; 
                    break ; 
                } 
            } 
            if ( ok ) break ; // Exit the outer loop if a solution is found
        } 
        
        // Print the result based on the flag
        if ( ok ) out.print ( "YES" ) ; 
        else out.print ( "NO" ) ; 
    } 
    
    public static void main ( String [ ] args ) { 
        new Main ( ).run ( ) ; 
    } 
    
    // BufferedReader and StringTokenizer for reading input
    BufferedReader br ; 
    StringTokenizer st ; 
    
    // PrintWriter for output
    PrintWriter out ; 
    
    private void run ( ) { 
        try { 
            br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
            out = new PrintWriter ( System.out ) ; 
            solve ( ) ; 
            br.close ( ) ; 
            out.close ( ) ; 
        } catch ( IOException e ) { 
            e.printStackTrace ( ) ; 
        } 
    } 
    
    // Method to read the next integer from the input
    private int nextInt ( ) { 
        return Integer.parseInt ( next ( ) ) ; 
    } 
    
    // Method to read the next token from the input
    private String next ( ) { 
        while ( st == null || ! st.hasMoreTokens ( ) ) { 
            try { 
                st = new StringTokenizer ( br.readLine ( ) ) ; 
            } catch ( IOException e ) { 
                e.printStackTrace ( ) ; 
                return "END_OF_FILE" ; 
            } 
        } 
        return st.nextToken ( ) ; 
    } 
}
