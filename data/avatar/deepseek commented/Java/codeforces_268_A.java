
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Read the number of elements
        int n = Integer.parseInt ( sc.nextLine ( ) ) ; 
        
        // Initialize arrays to store the elements
        int [ ] h = new int [ n ] ; 
        int [ ] g = new int [ n ] ; 
        
        // Read n pairs of integers from the standard input
        for ( int i = 0 ; i < n ; i ++ ) { 
            h [ i ] = sc.nextInt ( ) ; 
            g [ i ] = sc.nextInt ( ) ; 
        } 
        
        // Initialize the result variable to 0
        int result = 0 ; 
        
        // Iterate through each element in array h
        for ( int i = 0 ; i < n ; i ++ ) { 
            // Compare each element in array h with each element in array g
            for ( int j = 0 ; j < n ; j ++ ) { 
                if ( h [ i ] == g [ j ] ) { 
                    // If a match is found, increment the result
                    result ++ ; 
                } 
            } 
        } 
        
        // Print the value of result
        System.out.println ( result ) ; 
    } 
}

