
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner ( System.in ) ; 
        
        // Read the number of elements (n) and a threshold value (k)
        int n = in.nextInt ( ) ; 
        int k = in.nextInt ( ) ; 
        
        // Initialize variables to keep track of the last number and its consecutive occurrences
        int l = 0 , c = 1 ; 
        
        // Loop to read n numbers and count consecutive occurrences
        for ( int i = 0 ; i < n ; i ++ ) { 
            int a = in.nextInt ( ) ; 
            if ( a == l ) 
                c += 1 ; // Increment count if the current number is the same as the last
            else 
                c = 1 ; // Reset count if the current number is different
            l = a ; // Update the last number
        } 
        
        // Check if the number of consecutive occurrences plus the threshold value is greater than n
        if ( c + k > n ) 
            System.out.println ( n - c ) ; // Print the number of elements to remove
        else 
            System.out.println ( - 1 ) ; // Print -1 if it's not possible to satisfy the condition
    } 
}

