
import java.util.* ; 
import java.lang.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; // Read the number of elements in the array
        int f = 0 ; // Flag to indicate if the triplet is found
        int [ ] a = new int [ n ] ; // Array to store the elements
        
        // Read the elements of the array
        for ( int i = 0 ; i < n ; i ++ ) { 
            a [ i ] = sc.nextInt ( ) ; 
        } 
        
        int k = 0 , j = 0 , i = 0 ; // Initialize indices
        
        // Outer loop to iterate over each element as a potential a[k]
        for ( k = 0 ; k < n ; k ++ ) { 
            int t = a [ k ] ; // Current element as t
            
            // Inner loops to find two indices i and j such that a[i] + a[j] = t
            for ( i = 0 ; i < n ; i ++ ) { 
                for ( j = 0 ; j < n - 1 ; j ++ ) { 
                    if ( i != j && t == ( a [ i ] + a [ j ] ) ) { 
                        f = 1 ; // Set flag to 1 if triplet is found
                        break ; // Break out of the inner loop
                    } 
                } 
                if ( f == 1 ) break ; // Break out of the outer loop if triplet is found
            } 
            if ( f == 1 ) break ; // Break out of the main loop if triplet is found
        } 
        
        // Check if a triplet was found and print the result
        if ( f == 1 ) 
            System.out.println ( k + 1 + " " + ( j + 1 ) + " " + ( i + 1 ) ) ; 
        else 
            System.out.println ( "-1" ) ; 
    } 
}

