import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner scn = new Scanner ( System.in ) ; // Initialize Scanner to read input
        int n = scn.nextInt ( ) ; // Read the number of elements in the sequence
        int k = scn.nextInt ( ) ; // Read the initial value of k
        
        int i = 1 , req = 1 ; // Initialize i and req to 1
        
        // Loop continues as long as k - req is non-negative
        while ( k - req >= 0 ) { 
            if ( k - req >= 0 ) { 
                k = k - req ; // Subtract req from k if k - req is non-negative
            } else { 
                break ; // Exit the loop if k - req is negative
            }
            i ++ ; // Increment i
            if ( i % n != 0 ) { 
                req = i % n ; // Update req to i % n if i % n is not zero
            } else { 
                req = n ; // Update req to n if i % n is zero
            }
        }
        
        System.out.println ( k ) ; // Print the final value of k
    }
}
