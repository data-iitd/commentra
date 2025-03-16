
import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStreamReader ; 
import java.io.PrintWriter ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) throws IOException { 
        // Create a FastReader object to read input
        FastReader sc = new FastReader ( ) ; 
        // Create a PrintWriter object to write output
        PrintWriter pw = new PrintWriter ( System.out ) ; 
        
        // Read an integer input
        int x = sc.nextInt ( ) ; 
        // Initialize a counter to keep track of the number of iterations
        int count = 0 ; 
        // Store the initial value of x in a temporary variable
        int tmp = x ; 
        
        // Initialize x to 0 to start the loop
        x = 0 ; 
        
        // Loop until x becomes 360
        while ( x != 360 ) { 
            // Increment x by tmp
            x = x + tmp ; 
            // If x exceeds 360, adjust it by subtracting 360
            if ( x > 360 ) { 
                x = x - 360 ; 
            } 
            // Increment the counter
            count ++ ; 
        } 
        
        // Print the final count
        System.out.println ( count ) ; 
    } 
} 

class FastReader { 
    BufferedReader br ; 
    StringTokenizer st ; 
    
    public FastReader ( ) { 
        br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
    } 
    
    String next ( ) { 
        while ( st == null || ! st.hasMoreElements ( ) ) { 
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
        String str = "" ; 
        try { 
            str = br.readLine ( ) ; 
        } catch ( IOException e ) { 
            e.printStackTrace ( ) ; 
        } 
        return str ; 
    } 
}

