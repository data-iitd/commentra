import java.util.*;

public class Main {
    // Define constants for modular arithmetic
    static final long MOD2 = 1000000007;
    static final long MOD = 998244353;
    static final long INF = (1 << 30) - 1;
    static final long LINF = (1L << 60);
    static final double EPS = 1e-10;

    // Arrays for factorials and their modular inverses
    static long[] fact = new long[1100000];
    static long[] revfact = new long[1100000];
    static long[] rev = new long[1100000];

    // Function to initialize factorials and their inverses
    static void init() {
        long m = MOD; // Set the modulus
        fact[0] = 1; // Base case for factorial
        revfact[0] = 1; // Base case for inverse factorial
        rev[0] = 0; // Not used
        rev[1] = 1; // Inverse of 1 is 1

        // Precompute factorials and their modular inverses
        for (int i = 1; i < 1100000; i++) {
            fact[i] = fact[i - 1] * i % m; // Compute factorial
            if (i > 1)
                rev[i] = MOD / i * (MOD - rev[(int) (MOD % i)]) % MOD; // Compute modular inverse
            revfact[i] = revfact[i - 1] * rev[i] % MOD; // Compute inverse factorial
        }
    }

    // 2D array for storing combinations
    static long[][] comb = new long[1100][1100];

    // Function to compute n choose k (combinations)
    static long nCk(long n, long k) {
        if (n < k) return 0; // If n < k, return 0
        if (comb[(int) n][(int) k] != 0) return comb[(int) n][(int) k]; // Return cached result if available
        long res = fact[(int) n] * revfact[(int) (n - k)] % MOD * revfact[(int) k] % MOD; // Compute combinations
        comb[(int) n][(int) k] = res; // Cache the result
        return res;
    }

    // Function to compute modular exponentiation
    static long mod_pow(long x, long a, long m) {
        if (a == 0) return 1; // Base case
        long res = mod_pow(x, a / 2, m); // Recursive call
        res = res * res % m; // Square the result
        if (a % 2 != 0) res = res * x % m; // If a is odd, multiply by x
        return res; // Return result modulo m
    }

    // Function to compute modular inverse using Fermat's Little Theorem
    static long inv(long x, long m) {
        return mod_pow(x, m - 2, m); // Inverse is x^(m-2) mod m
    }

    public static void main(String[] args) {
        init(); // Initialize factorials and inverses
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements

        long aall = 0, ball = 0; // Total sums of arrays a and b
        long[] a = new long[440], b = new long[440]; // Input arrays
        long[][][][] dp = new long[440][440][2][2]; // Dynamic programming table

        // Read input arrays and compute their total sums
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
            b[i] = scanner.nextLong();
            aall += a[i]; // Sum of array a
            ball += b[i]; // Sum of array b
        }

        // Initialize the dynamic programming table
        dp[0][0][0][0] = 1; // Base case for DP
        for (int i = 1; i <= n; i++) {
            int id = i % 2; // Current index for alternating DP
            // Iterate over possible sums and counts
            for (long asum = aall; asum >= 0; asum--) {
                for (long cnt = 0; cnt <= ball; cnt++) {
                    for (int p = 0; p < 2; p++) {
                        if (asum - a[i - 1] < 0) continue; // Skip if sum is not feasible
                        long pw = 1; // Power variable for combinations
                        // Iterate over possible uses of b[i-1]
                        for (long use = 0; use < b[i - 1]; use++) {
                            if (cnt - use >= 0) {
                                long tmp = nCk(cnt, use) % MOD * pw % MOD; // Compute combinations
                                // Update DP table based on previous states
                                dp[(int) asum][(int) cnt][p][0] += dp[(int) (asum - a[i - 1])][(int) (cnt - use)][p ^ 1][0] * tmp % MOD;
                                dp[(int) asum][(int) cnt][p][1] += dp[(int) (asum - a[i - 1])][(int) (cnt - use)][p ^ 1][1] * tmp % MOD;
                            } else break; // Break if not enough count
                            pw = pw * a[i - 1] % MOD; // Update power for next use
                        }
                        // Handle the case where we use one more from b[i-1]
                        if (cnt - b[i - 1] + 1 >= 0)
                            dp[(int) asum][(int) cnt][p][1] += dp[(int) (asum - a[i - 1])][(int) (cnt - b[i - 1] + 1)][p ^ 1][0] * nCk(cnt, b[i - 1] - 1) % MOD * pw % MOD;
                        // Apply modulo to keep values within bounds
                        dp[(int) asum][(int) cnt][p][0] %= MOD;
                        dp[(int) asum][(int) cnt][p][1] %= MOD;
                    }
                }
            }
        }

        // Final computation of the answer
        long ans = 0; // Final answer
        for (long asum = 0; asum <= aall; asum++) {
            long rev_asum_pow = 1; // Initialize power for the current sum
            for (long cnt = 0; cnt <= ball; cnt++) {
                rev_asum_pow = rev_asum_pow * rev[(int) asum] % MOD; // Update power for the sum
                for (int p = 0; p < 2; p++) {
                    // Compute contribution to the answer based on DP values
                    long x = dp[(int) asum][(int) cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * rev[(int) asum] % MOD;
                    if (p == 1) ans += x; // Add if p is 1
                    else ans -= x; // Subtract if p is 0
                    ans %= MOD; // Ensure answer is within bounds
                }
            }
        }

        // Adjust answer if negative
        if (ans < 0) ans += MOD;
        System.out.println(ans); // Output the final answer
    }
}
// <END-OF-CODE>
