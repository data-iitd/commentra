
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Initialize Scanner to read input
        int a , b ; 
        a = sc.nextInt ( ) ; // Read first integer input
        b = sc.nextInt ( ) ; // Read second integer input
        int count = 0 ; // Initialize count to keep track of loop iterations
        
        // Loop continues until the condition is met to break
        while ( true ) { 
            if ( a > 0 && b > 0 ) { // Check if both a and b are positive
                count ++ ; // Increment count
                a -- ; // Decrement a
                b -- ; // Decrement b
            } else break ; // Break the loop if a or b is not positive
        }
        
        int ans = a / 2 + b / 2 ; // Calculate the value of ans
        System.out.println ( count + " " + ans ) ; // Print the results
    } 
}

