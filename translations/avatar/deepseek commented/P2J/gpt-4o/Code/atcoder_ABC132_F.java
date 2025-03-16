import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int MOD = 1000000007;  // Set the modulus to 10^9 + 7
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of n and k from input
        long n = scanner.nextLong();
        int k = scanner.nextInt();
        
        // Calculate the coefficients for the number of multiples of each divisor up to n
        long[] coef = new long[(int) (n + 1)];
        int nn = 0;
        
        for (long i = 1; i * i <= n; i++) {
            coef[nn++] = (n / i) - (n / (i + 1));  // Calculate the number of multiples of i
        }
        
        for (int i = nn; i < coef.length; i++) {
            coef[i] = 1;  // Adjust for remaining numbers
        }
        
        // Reverse the coefficients for dynamic programming
        long[] reversedCoef = new long[nn];
        for (int i = 0; i < nn; i++) {
            reversedCoef[i] = coef[nn - 1 - i];
        }
        
        // Initialize the dp table
        long[][] dp = new long[k + 1][nn];
        dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements
        
        // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
        for (int i = 1; i <= k; i++) {
            long tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
            for (int j = nn - 1; j >= 0; j--) {
                tmp += dp[i - 1][nn - 1 - j];  // Update the temporary sum
                tmp %= MOD;
                dp[i][j] = (reversedCoef[j] * tmp) % MOD;  // Update the dp table
            }
        }
        
        // Print the result: the sum of the last row of dp modulo mod
        long result = 0;
        for (int j = 0; j < nn; j++) {
            result = (result + dp[k][j]) % MOD;
        }
        
        System.out.println(result);
        scanner.close();
    }
}
// <END-OF-CODE>
