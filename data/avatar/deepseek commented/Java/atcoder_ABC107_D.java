
import java.io.BufferedInputStream ; 
import java.util.Arrays ; 
import java.util.HashMap ; 
import java.util.Scanner ; 
import java.util.TreeMap ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner scan = new Scanner ( new BufferedInputStream ( System.in ) ) ; 
        int N = scan.nextInt ( ) ; // Read the size of the array
        int [ ] arr = new int [ N ] ; 
        for ( int i = 0 ; i < N ; i ++ ) 
            arr [ i ] = scan.nextInt ( ) ; // Read the array elements
        
        Task tsk = new Task ( ) ; 
        System.out.println ( tsk.solve ( arr ) ) ; // Print the result of the solve method
    } 
    
    static class Task { 
        public int solve ( int [ ] arr ) { 
            int n = arr.length ; 
            int [ ] sorted = Arrays.copyOf ( arr , n ) ; // Create a copy of the array and sort it
            Arrays.sort ( sorted ) ; 
            
            long total = ( long ) n * ( n + 1 ) / 2 ; // Calculate the total number of elements
            int l = 0 , r = n - 1 ; 
            
            // Implement binary search to find the median
            while ( l < r ) { 
                int mid = l + ( r - l ) / 2 ; 
                int target = sorted [ mid ] ; 
                int cur = 0 ; 
                long cnt = 0 ; 
                long [ ] bit = new long [ 2 * n + 2 ] ; 
                
                for ( int x = n + 1 ; x < bit.length ; x += x & - x ) 
                    bit [ x ] ++ ; // Initialize the binary indexed tree
                
                for ( int i = 0 ; i < n ; i ++ ) { 
                    cur += arr [ i ] <= target ? 1 : - 1 ; 
                    for ( int x = cur + n + 1 ; x < bit.length ; x += x & - x ) 
                        bit [ x ] ++ ; // Update the binary indexed tree
                    for ( int x = cur + n ; x > 0 ; x -= x & - x ) 
                        cnt += bit [ x ] ; // Calculate the count of elements less than or equal to the target
                } 
                
                if ( cnt >= total / 2 + 1 ) 
                    r = mid ; // Adjust the search range if the count is sufficient
                else 
                    l = mid + 1 ; 
            } 
            
            return sorted [ l ] ; // Return the median value
        } 
    } 
}