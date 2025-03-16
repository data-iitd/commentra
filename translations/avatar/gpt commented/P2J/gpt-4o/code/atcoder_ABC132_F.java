import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define the modulus value for calculations to prevent overflow
        final int MOD = 1000000007;

        // Read input values for n and k
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Initialize an array to store coefficients
        int[] coef = new int[n + 1];

        // Calculate coefficients based on the divisors of n
        for (int i = 1; i <= Math.sqrt(n); i++) {
            coef[i] = (n / i) - (n / (i + 1));
        }

        // Fill the remaining coefficients with 1s to ensure the length matches n
        for (int i = 1; i <= n; i++) {
            coef[i] += 1;
        }

        // Reverse the coefficients array for further processing
        int[] reversedCoef = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            reversedCoef[i] = coef[n - i];
        }

        // Get the length of the coefficients array
        int nn = reversedCoef.length;

        // Initialize a 2D array for dynamic programming
        // dp[i][j] will store the result for i selections and j coefficients
        long[][] dp = new long[k + 1][nn];

        // Base case: there's one way to select 0 items (select nothing)
        dp[0][0] = 1;

        // Fill the dp table for k selections
        for (int i = 1; i <= k; i++) {
            long tmp = 0;  // Temporary variable to accumulate values
            // Iterate through the coefficients in reverse order
            for (int j = nn - 1; j >= 0; j--) {
                // Accumulate the number of ways to select items
                tmp += dp[i - 1][nn - 1 - j];
                tmp %= MOD;  // Ensure the value stays within modulus
                // Calculate the number of ways to select i items using the j-th coefficient
                dp[i][j] = (reversedCoef[j] * tmp) % MOD;
            }
        }

        // Output the total number of ways to select k items, taking modulus
        long result = 0;
        for (int j = 0; j < nn; j++) {
            result = (result + dp[k][j]) % MOD;
        }
        System.out.println(result);
    }
}
// <END-OF-CODE>
