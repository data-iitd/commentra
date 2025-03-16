import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final long mod = 1000000007;
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] coef = new int[n];

        // Calculate coefficients based on the divisors of n
        int size = 0;
        for (int i = 1; i * i <= n; i++) {
            coef[size++] = (n / i) - (n / (i + 1));
        }
        for (int i = size; i < n; i++) {
            coef[i] = 1;
        }

        // Reverse the coefficients array for further processing
        for (int i = 0; i < size / 2; i++) {
            int temp = coef[i];
            coef[i] = coef[size - 1 - i];
            coef[size - 1 - i] = temp;
        }

        // Initialize a 2D array for dynamic programming
        long[][] dp = new long[k + 1][n];

        // Base case: there's one way to select 0 items (select nothing)
        dp[0][0] = 1;

        // Fill the dp table for k selections
        for (int i = 1; i <= k; i++) {
            long tmp = 0; // Temporary variable to accumulate values
            // Iterate through the coefficients in reverse order
            for (int j = 0; j < n; j++) {
                // Accumulate the number of ways to select items
                tmp += dp[i - 1][j];
                tmp %= mod;
                // Calculate the number of ways to select i items using the j-th coefficient
                dp[i][j] = coef[j] * tmp % mod;
            }
        }

        // Output the total number of ways to select k items, taking modulus
        long result = 0;
        for (int i = 0; i < n; i++) {
            result += dp[k][i];
            result %= mod;
        }
        System.out.println(result);
    }
}
