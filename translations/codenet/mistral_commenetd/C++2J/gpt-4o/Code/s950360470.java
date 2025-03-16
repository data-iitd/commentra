import java.util.Scanner;

public class Main {
    // Constants
    static final long MOD = 1000000007; // Modulus value

    // Helper functions
    // a^n
    static long pow(long a, long n) {
        long res = 1; // Initialize result
        while (n > 0) { // While n is greater than 0
            if ((n & 1) == 1) res *= a; // If n is odd, multiply result with base
            a *= a; // Square the base
            n >>= 1; // Divide n by 2
        }
        return res; // Return the final result
    }

    // a^n % mod
    static long mod_pow(long a, long n, long mod) {
        long res = 1; // Initialize result
        while (n > 0) { // While n is greater than 0
            if ((n & 1) == 1) res = (res * a) % mod; // If n is odd, multiply result with base and take modulo
            a = (a * a) % mod; // Square the base and take modulo
            n >>= 1; // Divide n by 2
        }
        return res; // Return the final result
    }

    // a^(-1) % mod (only if : a % p != 0)
    static long mod_inv(long a, long mod) {
        return mod_pow(a, mod - 2, mod); // Calculate the modular inverse of 'a'
    }

    // nCk % mod
    static long mod_nCk(int n, int k, long mod) {
        if (n == 0 || k == 0) return 1; // Base case: nC0 = kC0 = 1

        long p = 1, q = 1; // Initialize p and q
        for (int i = n - k + 1; i <= n; i++) // Calculate p = nC(n-k+1)
            p = (p * i) % mod;

        for (int i = 2; i <= k; i++) // Calculate q = k!
            q = (q * i) % mod;

        q = mod_inv(q, mod); // Calculate q^(-1) modulo 'mod'
        return (p * q) % mod; // Return the final result: nCk = p * q
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read input value for n
        int k = scanner.nextInt(); // Read input value for k

        System.out.println(mod_nCk(k, n, MOD)); // Print the result of nCk modulo 'MOD'
        scanner.close();
    }
}

// <END-OF-CODE>
