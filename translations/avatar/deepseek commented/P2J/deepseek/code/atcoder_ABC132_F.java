import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final long mod = (long) Math.pow(10, 9) + 7;  // Set the modulus to 10^9 + 7
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);  // Read the value of n from input
        int k = Integer.parseInt(input[1]);  // Read the value of k from input

        // Calculate the coefficients for the number of multiples of each divisor up to n
        ArrayList<Integer> coef = new ArrayList<>();
        for (int i = 1; i <= Math.sqrt(n); i++) {
            coef.add(0, (n / i) - (n / (i + 1)));  // Calculate the number of multiples of i
        }
        int remaining = n - coef.stream().mapToInt(Integer::intValue).sum();
        for (int i = 0; i < remaining; i++) {
            coef.add(0, 1);  // Adjust for remaining numbers
        }

        int nn = coef.size();  // Get the length of the coefficient list
        long[][] dp = new long[k + 1][nn];  // Initialize the dp table
        dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements

        // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
        for (int i = 1; i <= k; i++) {
            long tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
            for (int j = nn - 1; j >= 0; j--) {
                tmp += dp[i - 1][nn - 1 - j];  // Update the temporary sum
                tmp %= mod;
                dp[i][j] = (coef.get(j) * tmp) % mod;  // Update the dp table
            }
        }

        // Print the result: the sum of the last row of dp modulo mod
        long result = 0;
        for (int j = 0; j < nn; j++) {
            result += dp[k][j];
            result %= mod;
        }
        System.out.println(result);
    }
}
