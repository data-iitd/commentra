import java.math.*;   // Importing BigInteger class for large integer arithmetic
import java.util.*;   // Importing Scanner class for reading input
import java.util.function.*; // Importing functional interfaces for lambda expressions

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );  // Creating a new Scanner object to read input from the standard input stream
        int N = sc.nextInt ( );                // Reading the number of integers N from the standard input
        int [ ] A = new int [ N ];              // Creating an integer array A of size N

        // Using a for loop to read each integer in the array A from the standard input
        for ( int i = 0 ; i < N ; i ++ ) {
            A [ i ] = sc.nextInt ( );
        }

        // Closing the Scanner object to prevent resource leaks
        sc.close ( );

        BigInteger lcm = BigInteger.ONE;       // Initializing lcm as 1

        // Using a for loop to calculate the least common multiple (lcm) of all integers in array A
        for ( int ai : A ) {
            BigInteger a = BigInteger.valueOf( ai );  // Converting integer ai to BigInteger a
            lcm = lcm.divide( lcm.gcd( a ) ).multiply( a ); // Calculating lcm using division and multiplication
        }

        long mod = 1000000007;                 // Setting the modulus value
        long modLcm = lcm.remainder( BigInteger.valueOf( mod ) ).longValue(); // Calculating the remainder of lcm modulo mod

        long ans = 0;                          // Initializing answer variable as 0

        // Using a for loop to calculate the answer using modular arithmetic
        for ( int ai : A ) {
            ans = ( ans + modDiv( modLcm , ai , mod ) ) % mod;
        }

        // Printing the answer to the standard output stream
        System.out.println( ans );
    }

    // A private method modDiv is used to perform modular division
    private static long modDiv ( long a , long b , long mod ) {
        return ( a % mod ) * modInv( b , mod ) % mod;
    }

    // A private method modInv is used to calculate the modular inverse of a number
    private static long modInv ( long x , long mod ) {
        return modPow( x , mod - 2 , mod );
    }

    // A private method modPow is used to calculate the power of a number using modular arithmetic
    private static long modPow ( long b , long e , long mod ) {
        long ans = 1;
        long x = b % mod;
        for ( long y = e ; y != 0 ; y >>= 1 ) {
            if ( ( y & 1 ) == 1 ) {
                ans = ( ans * x ) % mod;
            }
            x = ( x * x ) % mod;
        }
        return ans;
    }
}
