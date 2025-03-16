import java.util.* ; 

public class Main { 
    public static void main ( String args [ ] ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int q = sc.nextInt ( ) ; // Read the number of queries
        
        while ( q -- > 0 ) { 
            int n = sc.nextInt ( ) ; // Read the number n for the current query
            long s = 0 ; // Initialize the sum variable s
            
            int x = ( int ) ( Math.log ( n ) / Math.log ( 2 ) ) ; // Calculate the position of the most significant bit of n
            x ++ ; // Increment x by 1
            
            s = - 1 * ( long ) Math.pow ( 2 , x ) + 2 + ( ( long ) n * ( long ) ( n + 1 ) ) / 2 - ( long ) Math.pow ( 2 , x ) ; 
            // Calculate s using arithmetic operations and power functions
            
            System.out.println ( s ) ; // Print the result s for the current query
        } 
    } 
}
