
import java.util.Scanner;

public class atcoder_ABC132_F{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int mod = 100000007;  // Set the modulus to 10^9 + 7

        // Calculate the coefficients for the number of multiples of each divisor up to n
        int[] coef = new int[n];
        for (int i = 1; i <= Math.sqrt(n); i++) {
            coef[i - 1] = (n / i) - (n / (i + 1));
        }
        for (int i = (int) Math.sqrt(n) + 1; i < n; i++) {
            coef[i - 1] = 1;
        }

        int nn = coef.length;  // Get the length of the coefficient array
        long[][] dp = new long[k + 1][nn];  // Initialize the dp table
        dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements

        // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
        for (int i = 1; i <= k; i++) {
            long tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
            for (int j = nn - 1; j >= 0; j--) {
                tmp += dp[i - 1][(nn - 1) - j];  // Update the temporary sum
                tmp %= mod;
                dp[i][j] = coef[j] * tmp % mod;  // Update the dp table
            }
        }

        // Print the result: the sum of the last row of dp modulo mod
        long sum = 0;
        for (long x : dp[k]) {
            sum += x;
        }
        System.out.println(sum % mod);
    }
}

Translate the above Java code to C++ and end with comment "