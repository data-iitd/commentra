
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = Integer.parseInt ( sc.next ( ) ) ; // Read the first integer n
        int m = Integer.parseInt ( sc.next ( ) ) ; // Read the second integer m
        int [ ] a = new int [ n ] ; 
        
        // Initialize array a with size n, where each element is half of the next input
        for ( int i = 0 ; i < n ; i ++ ) { 
            a [ i ] = Integer.parseInt ( sc.next ( ) ) / 2 ; 
        } 
        
        long gcd ; 
        long lcd = 1 ; 
        
        // Calculate the least common multiple (LCM) of the elements in array a
        for ( int i = 0 ; i < n ; i ++ ) { 
            gcd = getGCD ( lcd , a [ i ] ) ; 
            lcd = lcd * a [ i ] / gcd ; 
            if ( lcd > m ) { // Check if LCM exceeds m
                System.out.println ( 0 ) ; 
                return ; 
            } 
        } 
        
        // Check if the LCM is even for any element in the array
        for ( int i = 0 ; i < n ; i ++ ) { 
            if ( ( lcd / a [ i ] ) % 2 == 0 ) { 
                System.out.println ( 0 ) ; 
                return ; 
            } 
        } 
        
        // Calculate and print the number of integers up to m that are divisible by the LCM
        System.out.println ( ( m / lcd + 1 ) / 2 ) ; 
    } 
    
    // Helper function to compute the greatest common divisor (GCD) of two numbers
    public static long getGCD ( long a , long b ) { 
        if ( b == 0 ) { 
            return a ; 
        } else { 
            return getGCD ( b , a % b ) ; 
        } 
    } 
}
