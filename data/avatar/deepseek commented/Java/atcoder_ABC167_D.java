
import java.util.* ; 

public class Main { 
    Scanner sc = new Scanner ( System.in ) ; 
    final int MOD = 1000000007 ; 
    final int MAX = Integer.MAX_VALUE ; 
    final long LMAX = Long.MAX_VALUE ; 
    int len = ( int ) 1e6 + 1 ; 
    
    void doIt ( ) { 
        // Read the number of elements N and the value K
        int N = sc.nextInt ( ) ; 
        long K = sc.nextLong ( ) ; 
        
        // Read the array A with N elements, adjusting each element by -1 for 0-based indexing
        int A [ ] = new int [ N ] ; 
        for ( int i = 0 ; i < N ; i ++ ) { 
            A [ i ] = sc.nextInt ( ) - 1 ; 
        } 
        
        // Set to track visited indices
        Set < Integer > used = new HashSet < > ( ) ; 
        
        // Arrays to store index and position information
        int idx [ ] = new int [ N ] ; 
        int pos [ ] = new int [ N ] ; 
        
        // Initialize variables for cycle detection
        int next = 0 , cur = 0 ; 
        
        // Detect the cycle in the array A
        while ( ! used.contains ( next ) ) { 
            used.add ( next ) ; 
            idx [ next ] = cur ; 
            pos [ cur ] = next ; 
            next = A [ next ] ; 
            cur ++ ; 
        } 
        
        // Calculate the length of the cycle and adjust the position based on K
        long a = ( long ) cur - idx [ next ] ; 
        long b = ( long ) idx [ next ] ; 
        int ans = ( int ) ( ( 10000 * a + K - b ) % a + b ) ; 
        
        // Adjust the answer if necessary based on the cycle length
        if ( b > K ) ans = ( int ) K ; 
        
        // Output the final position
        System.out.println ( pos [ ans ] + 1 ) ; 
    } 
    
    public static void main ( String [ ] args ) { 
        new Main ( ).doIt ( ) ; 
    } 
}

