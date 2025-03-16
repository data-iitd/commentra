
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Initialize a Scanner object to read input from the user
        Scanner scanner = new Scanner ( System.in ) ; 
        
        // Read three integers from the user
        int n = scanner.nextInt ( ) ; 
        int maxn = 4010 ; 
        int a = scanner.nextInt ( ) ; 
        int b = scanner.nextInt ( ) ; 
        int c = scanner.nextInt ( ) ; 
        
        // Store the coin values in an array
        int [ ] arr = { a , b , c } ; 
        
        // Initialize a dp array with all elements set to Integer.MIN_VALUE
        int [ ] dp = new int [ maxn ] ; 
        for ( int i = 0 ; i < n ; i ++ ) { 
            dp [ i ] = Integer.MIN_VALUE ; 
        } 
        
        // Set the base case where dp[0] is 0
        dp [ 0 ] = 0 ; 
        
        // Iterate over the coin values and update the dp array
        for ( int i = 0 ; i < 3 ; i ++ ) { 
            for ( int j = arr [ i ] ; j < dp.length ; j ++ ) { 
                dp [ j ] = Math.max ( dp [ j ] , dp [ j - arr [ i ] ] + 1 ) ; 
            } 
        } 
        
        // Print the value of dp[n]
        System.out.println ( dp [ n ] ) ; 
    } 
}
