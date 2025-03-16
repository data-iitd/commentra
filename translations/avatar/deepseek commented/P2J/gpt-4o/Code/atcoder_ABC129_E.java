import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long mod = 1000000007;  // Set the modulus to a large prime number
        Scanner scanner = new Scanner(System.in);
        String l = scanner.nextLine();  // Read the input string
        int n = l.length();  // Calculate the length of the input string

        // Initialize the dynamic programming table
        long[][] dp = new long[n + 1][2];
        dp[0][0] = 1;  // Base case: one empty sequence

        // Iterate over each character in the input string
        for (int i = 0; i < n; i++) {
            char c = l.charAt(i);
            if (c == '0') {
                dp[i + 1][0] += dp[i][0];  // Add sequences ending with zero
                dp[i + 1][1] += dp[i][1] * 3;  // Triple sequences ending with one
            } else {
                dp[i + 1][0] += dp[i][0] * 2;  // Double sequences ending with zero
                dp[i + 1][1] += dp[i][0];  // Add sequences ending with zero
                dp[i + 1][1] += dp[i][1] * 3;  // Triple sequences ending with one
            }

            // Take modulo to prevent overflow
            dp[i + 1][0] %= mod;
            dp[i + 1][1] %= mod;
        }

        // Calculate and print the final result
        long result = (dp[n][0] + dp[n][1]) % mod;
        System.out.println(result);
    }
}
// <END-OF-CODE>
