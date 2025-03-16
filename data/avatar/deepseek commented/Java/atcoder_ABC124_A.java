
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Read two integers from the input
        int a = Integer.parseInt ( sc.next ( ) ) ; 
        int b = Integer.parseInt ( sc.next ( ) ) ; 
        
        // Initialize sum to 0, this will store the sum of the two numbers
        int sum = 0 ; 
        
        // Loop runs twice, each time adding the larger of the two numbers to sum
        // and decrementing that number by 1
        for ( int i = 0 ; i < 2 ; i ++ ) { 
            if ( a >= b ) { 
                sum += a ; 
                a = a - 1 ; 
            } else { 
                sum += b ; 
                b = b - 1 ; 
            } 
        } 
        
        // Print the final sum to the console
        System.out.println ( sum ) ; 
    } 
}

