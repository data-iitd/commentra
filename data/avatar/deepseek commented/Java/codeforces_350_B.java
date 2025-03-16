import java.util.* ; 
import java.io.* ; 

public class Main { 
    static Scanner scanner = new Scanner ( System.in ) ; 
    
    public static void main ( String [ ] args ) { 
        // Read the number of elements
        int n = scanner.nextInt ( ) ; 
        
        // Initialize arrays to store the input values
        int a [ ] = new int [ n + 1 ] ; 
        int b [ ] = new int [ n + 1 ] ; 
        int num [ ] = new int [ n + 1 ] ; 
        
        // Read the elements of array a
        for ( int i = 1 ; i <= n ; i ++ ) 
            a [ i ] = scanner.nextInt ( ) ; 
        
        // Read the elements of array b
        for ( int i = 1 ; i <= n ; i ++ ) 
            b [ i ] = scanner.nextInt ( ) ; 
        
        // Count the occurrences of each element in array b
        for ( int i = 1 ; i <= n ; i ++ ) 
            num [ b [ i ] ] ++ ; 
        
        // Initialize variables to store the result
        String ss = "" ; 
        int ans = 0 ; 
        boolean st [ ] = new boolean [ n + 1 ] ; 
        
        // Iterate through the elements of array a
        for ( int i = 1 ; i <= n ; i ++ ) { 
            if ( a [ i ] == 1 ) { 
                // Mark the current element as visited
                st [ i ] = true ; 
                
                // Build the sequence of indices
                StringBuilder sb = new StringBuilder ( ) ; 
                int x = b [ i ] ; 
                StringBuilder sss = new StringBuilder ( ) ; 
                sss.append ( i ) ; 
                sb.append ( " " + sss.reverse ( ) ) ; 
                int s = 1 ; 
                
                // Continue building the sequence until a visited element or mismatch is found
                while ( ! st [ x ] && num [ x ] == 1 && x != 0 && a [ x ] != 1 ) { 
                    sss = new StringBuilder ( ) ; 
                    sss.append ( x ) ; 
                    sb.append ( " " + sss.reverse ( ) ) ; 
                    st [ x ] = true ; 
                    x = b [ x ] ; 
                    s ++ ; 
                } 
                
                // Update the result if a longer sequence is found
                if ( s > ans ) { 
                    ans = s ; 
                    ss = sb.reverse ( ).toString ( ) ; 
                } 
            } 
        } 
        
        // Print the result
        System.out.println ( ans ) ; 
        System.out.println ( ss ) ; 
    } 
}
