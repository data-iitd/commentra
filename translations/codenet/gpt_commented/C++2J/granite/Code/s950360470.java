
import java.util.*;

public class s950360470{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long mod = 1000000007; // Define a constant for modulo operation (1000000007)

        // Function to compute a raised to the power n (a^n)
        long pow(long a, long n) {
            long res = 1; // Initialize result to 1
            while (n > 0) { // Loop until n becomes 0
                if (n % 2 == 1) res *= a; // If n is odd, multiply result by a
                a *= a; // Square the base
                n /= 2; // Divide n by 2
            }
            return res; // Return the computed power
        }

        // Function to compute a raised to the power n modulo mod (a^n % mod)
        long mod_pow(long a, long n, long mod) {
            long res = 1; // Initialize result to 1
            while (n > 0) { // Loop until n becomes 0
                if (n % 2 == 1) res = res * a % mod; // If n is odd, multiply result by a and take modulo
                a = a * a % mod; // Square the base and take modulo
                n /= 2; // Divide n by 2
            }
            return res; // Return the computed power modulo
        }

        // Function to compute modular multiplicative inverse of a modulo mod (a^(-1) % mod)
        // This function assumes that a is not divisible by mod
        long mod_inv(long a, long mod) {
            return mod_pow(a, mod - 2, mod); // Use Fermat's Little Theorem to compute inverse
        }

        // Function to compute n choose k modulo mod (nCk % mod)
        long mod_nCk(int n, int k, long mod) {
            if (n == 0 || k == 0) return 1; // Base case: nC0 = 1
            long p = 1, q = 1; // Initialize numerator (p) and denominator (q)

            // Calculate the numerator for nCk
            for (int i = n - k + 1; i <= n; i++)
                p = (p * i) % mod; // Multiply terms from (n-k+1) to n and take modulo

            // Calculate the denominator for nCk
            for (int i = 2; i <= k; i++)
                q = (q * i) % mod; // Multiply terms from 1 to k and take modulo

            q = mod_inv(q, mod); // Compute the modular inverse of the denominator
            return (p * q) % mod; // Return the result of nCk modulo
        }

        System.out.println(mod_nCk(k, n, mod)); // Compute and print nCk modulo mod
    }
}
