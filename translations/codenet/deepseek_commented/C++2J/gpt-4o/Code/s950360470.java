import java.util.Scanner;

public class Main {
    static final long MOD = 1000000007; // Define a constant for modulo operation

    // Function to calculate a^n % mod
    static long modPow(long a, long n, long mod) {
        long res = 1; // Initialize result
        while (n > 0) { // Loop until n becomes 0
            if ((n & 1) == 1) res = res * a % mod; // If n is odd, multiply result by a modulo mod
            a = a * a % mod; // Square a modulo mod
            n >>= 1; // Divide n by 2
        }
        return res; // Return the result
    }

    // Function to calculate a^(-1) % mod (only if a % mod != 0)
    static long modInv(long a, long mod) {
        return modPow(a, mod - 2, mod); // Use Fermat's little theorem
    }

    // Function to calculate nCk % mod
    static long modNCK(int n, int k, long mod) {
        if (n == 0 || k == 0) return 1; // Base case: nCk is 1 if n or k is 0
        long p = 1, q = 1; // Initialize p and q
        for (int i = n - k + 1; i <= n; i++) // Calculate numerator
            p = (p * i) % mod;
        for (int i = 2; i <= k; i++) // Calculate denominator
            q = (q * i) % mod;
        q = modInv(q, mod); // Calculate inverse of denominator
        return (p * q) % mod; // Return the result
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt(); // Read values of n and k
        System.out.println(modNCK(k, n, MOD)); // Calculate and print nCk % MOD
        scanner.close();
    }
}

// <END-OF-CODE>
