import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007; // Modulus value for modular arithmetic
    static final int NMAX = 1000010; // Maximum size of the arrays
    static long[] fac = new long[NMAX]; // Array for storing factorials
    static long[] finv = new long[NMAX]; // Array for storing factorial inverses
    static long[] inv = new long[NMAX]; // Array for storing fast inverses

    // Initialize the arrays with factorials, inverses, and fast inverse values
    static void init() {
        fac[0] = fac[1] = 1; // Base cases
        finv[0] = finv[1] = 1; // Base cases
        inv[1] = 1; // Base case
        for (int i = 2; i < NMAX; i++) { // Iterate from 2 to NMAX-1
            fac[i] = fac[i - 1] * i % MOD; // Multiply the current number with the previous factorial
            inv[i] = MOD - inv[(int)(MOD % i)] * (MOD / i) % MOD; // Calculate the inverse of the current number using extended Euclidean algorithm
            finv[i] = finv[i - 1] * inv[i] % MOD; // Multiply the previous fast inverse with the current inverse to get the fast inverse
        }
    }

    // Calculate the binomial coefficient C(n, k) using the precomputed values
    static long C(int n, int k) {
        if (n < k) return 0; // Return 0 if n is less than k
        if (n < 0 || k < 0) return 0; // Return 0 if n or k is negative
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD; // Multiply the factorial of n with the product of the fast inverse of k and the fast inverse of n-k, then take the modulo
    }

    public static void main(String[] args) {
        init(); // Initialize the arrays
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt(); // Read input value for X
        int Y = scanner.nextInt(); // Read input value for Y
        if ((X + Y) % 3 != 0) { // Check if the sum of X and Y is not divisible by 3
            System.out.println(0); // If not, print 0 and exit
            return;
        }
        int n = (X + Y) / 3 + 1; // Calculate the value of n = (X + Y) / 3 + 1
        int k = 2 * (n - 1) - Y + 1; // Calculate the value of k = 2 * (n - 1) - Y + 1
        System.out.println(C(n - 1, k - 1)); // Print the binomial coefficient C(n - 1, k - 1)
    }
}

// <END-OF-CODE>
