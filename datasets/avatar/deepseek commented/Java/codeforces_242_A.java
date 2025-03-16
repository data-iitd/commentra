
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; // Initialize Scanner to read input
        int x , y , a , b ; 
        x = in.nextInt ( ) ; // Read first integer input
        y = in.nextInt ( ) ; // Read second integer input
        a = in.nextInt ( ) ; // Read third integer input
        b = in.nextInt ( ) ; // Read fourth integer input

        int count = 0 ; // Initialize counter to keep track of valid pairs

        // Nested loops to iterate through possible pairs (i, j)
        for ( int i = a ; i <= x ; i ++ ) { 
            for ( int j = b ; j <= y ; ++ j ) { 
                if ( i <= j ) continue ; // Skip pairs where i is not greater than j
                count ++ ; // Increment counter for each valid pair
            } 
        } 

        System.out.println ( count ) ; // Print the total count of valid pairs

        // Print each valid pair
        for ( int i = a ; i <= x ; i ++ ) { 
            for ( int j = b ; j <= y ; ++ j ) { 
                if ( i <= j ) continue ; // Skip pairs where i is not greater than j
                System.out.println ( i + " " + j ) ; // Print each valid pair
            } 
        } 

        in.close ( ) ; // Close the Scanner to free up resources
    } 
}
