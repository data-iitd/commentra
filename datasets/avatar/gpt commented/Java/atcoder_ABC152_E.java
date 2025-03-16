import java.math.*; 
import java.util.*; 
import java.util.function.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements N
        int N = sc.nextInt(); 
        
        // Initialize an array A to hold N integers
        int[] A = new int[N]; 
        
        // Read N integers into the array A
        for (int i = 0; i < N; i++) { 
            A[i] = sc.nextInt(); 
        } 
        
        // Close the scanner as we no longer need it
        sc.close(); 
        
        // Initialize BigInteger to calculate the least common multiple (LCM)
        BigInteger lcm = BigInteger.ONE; 
        
        // Calculate the LCM of all elements in the array A
        for (int ai : A) { 
            BigInteger a = BigInteger.valueOf(ai); 
            lcm = lcm.divide(lcm.gcd(a)).multiply(a); 
        } 
        
        // Define the modulus value
        long mod = 1000000007; 
        
        // Calculate the LCM modulo mod
        long modLcm = lcm.remainder(BigInteger.valueOf(mod)).longValue(); 
        
        // Initialize the answer variable to accumulate results
        long ans = 0; 
        
        // Calculate the sum of modDiv for each element in A
        for (int ai : A) 
            ans = (ans + modDiv(modLcm, ai, mod)) % mod; 
        
        // Print the final result
        System.out.println(ans); 
    } 
    
    // Method to perform modular division
    private static long modDiv(long a, long b, long mod) { 
        return (a % mod) * modInv(b, mod) % mod; 
    } 
    
    // Method to compute modular inverse using Fermat's Little Theorem
    private static long modInv(long x, long mod) { 
        return modPow(x, mod - 2, mod); 
    } 
    
    // Method to perform modular exponentiation
    private static long modPow(long b, long e, long mod) { 
        long ans = 1; 
        long x = b % mod; 
        
        // Loop to calculate b^e % mod using exponentiation by squaring
        for (long y = e; y != 0; y >>= 1) { 
            if ((y & 1) == 1) 
                ans = (ans * x) % mod; 
            x = (x * x) % mod; 
        } 
        
        // Return the final result of b^e % mod
        return ans; 
    } 
}
