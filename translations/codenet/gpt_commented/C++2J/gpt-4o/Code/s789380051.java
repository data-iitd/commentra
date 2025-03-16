import java.util.Scanner;

public class Main {
    private static final long MOD = 1000000007; // Define a constant for modulo operation

    // Function to compute (x^n) % MOD using modular exponentiation
    private static long modPow(long x, long n) {
        long ans = 1; // Initialize result
        while (n > 0) { // Loop until n becomes 0
            if ((n & 1) == 1) { // If n is odd
                ans = ans * x % MOD; // Multiply ans by x and take modulo
            }
            x = x * x % MOD; // Square x and take modulo
            n >>= 1; // Divide n by 2
        }
        return ans; // Return the result
    }

    // Function to compute combination C(n, r) % MOD using modular arithmetic
    private static long combS(long n, long r) {
        long tmpN = 1; // Temporary variable for numerator
        long tmpD = 1; // Temporary variable for denominator
        long ans = 0; // Variable to store the final answer
        for (int i = 1; i <= r; i++) { // Loop to calculate numerator and denominator
            tmpN = (tmpN * (n + 1 - i)) % MOD; // Calculate numerator
            tmpD = (tmpD * i) % MOD; // Calculate denominator
            ans = tmpN * modPow(tmpD, MOD - 2) % MOD; // Calculate combination using modular inverse
        }
        return ans; // Return the combination result
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n; // Variable to store the total number of elements
        long a; // Variable to store the first subset size
        long b; // Variable to store the second subset size
        long ans = 1; // Initialize answer variable

        // Input the values of n, a, and b
        n = scanner.nextLong();
        a = scanner.nextLong();
        b = scanner.nextLong();

        // Calculate 2^n - 1 (total subsets excluding the empty set)
        ans = modPow(2, n);
        ans--;

        long tmpNd; // Temporary variable to store combinations

        // Calculate C(n, a) and subtract from ans
        tmpNd = combS(n, a);
        ans = (ans - tmpNd + MOD) % MOD; // Subtract combinations of size a

        // Calculate C(n, b) and subtract from ans
        tmpNd = combS(n, b);
        ans = (ans - tmpNd + MOD) % MOD; // Subtract combinations of size b

        // Output the final result
        System.out.println(ans);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
