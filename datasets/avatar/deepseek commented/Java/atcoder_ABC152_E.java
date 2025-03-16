
import java.math.* ; 
import java.util.* ; 
import java.util.function.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int N = sc.nextInt ( ) ; 
        int [ ] A = new int [ N ] ; 
        
        // Read N integers into array A
        for ( int i = 0 ; i < N ; i ++ ) { 
            A [ i ] = sc.nextInt ( ) ; 
        } 
        sc.close ( ) ; 
        
        // Initialize LCM to 1
        BigInteger lcm = BigInteger.ONE ; 
        
        // Calculate the LCM of all elements in array A
        for ( int ai : A ) { 
            BigInteger a = BigInteger.valueOf ( ai ) ; 
            lcm = lcm.divide ( lcm.gcd ( a ) ).multiply ( a ) ; 
        } 
        
        // Define the modulo value
        long mod = 1000000007 ; 
        
        // Calculate the LCM modulo 10^9 + 7
        long modLcm = lcm.remainder ( BigInteger.valueOf ( mod ) ).longValue ( ) ; 
        
        // Initialize the answer to 0
        long ans = 0 ; 
        
        // Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
        for ( int ai : A ) 
            ans = ( ans + modDiv ( modLcm , ai , mod ) ) % mod ; 
        
        // Print the final answer
        System.out.println ( ans ) ; 
    } 
    
    // Function to perform modular division
    private static long modDiv ( long a , long b , long mod ) { 
        return ( a % mod ) * modInv ( b , mod ) % mod ; 
    } 
    
    // Function to calculate modular inverse
    private static long modInv ( long x , long mod ) { 
        return modPow ( x , mod - 2 , mod ) ; 
    } 
    
    // Function to perform modular exponentiation
    private static long modPow ( long b , long e , long mod ) { 
        long ans = 1 ; 
        long x = b % mod ; 
        for ( long y = e ; y != 0 ; y >>= 1 ) { 
            if ( ( y & 1 ) == 1 ) 
                ans = ( ans * x ) % mod ; 
            x = ( x * x ) % mod ; 
        } 
        return ans ; 
    } 
}

