
import java.util.* ; 
import java.lang.* ; 
import java.io.* ; 

public class Main { 
    public static void main ( String [ ] args ) throws java.lang.Exception { 
        // Read an integer n from the user input
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; 
        
        // Print the value of n
        System.out.println ( n + " " ) ; 
        
        // Initialize a variable m with the value of n
        int m = n ; 
        
        // Enter a loop that runs from n-1 down to 1
        for ( int i = n - 1 ; i > 0 ; i -- ) { 
            // Check if m is divisible by i
            if ( m % i == 0 ) { 
                // If m is divisible by i, print i and update m to i
                System.out.println ( i + " " ) ; 
                m = i ; 
            } 
        } 
    } 
}
