
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; 
        int n = in.nextInt ( ) ; // Read the number of elements
        int d = in.nextInt ( ) ; // Read the difference threshold
        int [ ] nums = new int [ n ] ; // Initialize an array to store the numbers
        
        for ( int i = 0 ; i < n ; i ++ ) { 
            nums [ i ] = in.nextInt ( ) ; // Read the numbers and store them in the array
        }
        
        int result = 0 ; // Initialize the result variable to 0
        int a = 0 ; // Initialize another variable to store the difference
        
        for ( int i = 1 ; i < n ; i ++ ) { 
            a = ( nums [ i - 1 ] - nums [ i ] ) ; // Calculate the difference between consecutive elements
            if ( a >= 0 ) { 
                result += a / d + 1 ; // Update the result based on the difference
                nums [ i ] += ( a / d + 1 ) * d ; // Adjust the current element to meet the condition
            } 
        }
        
        System.out.println ( result ) ; // Print the final result
    } 
}
