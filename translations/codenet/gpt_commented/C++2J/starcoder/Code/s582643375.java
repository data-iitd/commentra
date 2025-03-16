import java.util.*;
import java.io.*;

public class Main {
    // Define long long type for large integers
    static long long mod = 1e9 + 7;

    // Define constants for modulo operations and maximum size
    static int NMAX = 1000010;

    // Arrays to store factorials, inverse factorials, and modular inverses
    static long long fac[] = new long long[NMAX], finv[] = new long long[NMAX], inv[] = new long long[NMAX];

    // Function to initialize factorials and their inverses
    static void init() {
        // Base cases for factorials and their inverses
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;

        // Precompute factorials and their modular inverses
        for(int i = 2; i < NMAX; i++) {
            fac[i] = fac[i - 1] * i % mod; // Compute factorial mod
            inv[i] = mod - inv[mod % i] * (mod / i) % mod; // Compute modular inverse using Fermat's little theorem
            finv[i] = finv[i - 1] * inv[i] % mod; // Compute inverse factorial mod
        }
    }

    // Function to compute binomial coefficient C(n, k)
    static long long C(int n, int k) {
        // Return 0 if k is greater than n or if either is negative
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;

        // Calculate C(n, k) using precomputed factorials and inverses
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }

    public static void main(String[] args) {
        // Initialize factorials and inverses
        init();

        // Read input values for X and Y
        Scanner in = new Scanner(System.in);
        int X = in.nextInt();
        int Y = in.nextInt();

        // Check if the sum of X and Y is divisible by 3
        if((X + Y) % 3!= 0) {
            System.out.println(0); // If not, output 0 and exit
            return;
        }

        // Calculate n based on the sum of X and Y
        int n = (X + Y) / 3 + 1;

        // Calculate k based on the relationship to the line y = 2x
        int k = 2 * (n - 1) - Y + 1; // Determine how far the point is from the topmost point

        // Output the result of the binomial coefficient C(n-1, k-1)
        System.out.println(C(n - 1, k - 1));
    }
}

