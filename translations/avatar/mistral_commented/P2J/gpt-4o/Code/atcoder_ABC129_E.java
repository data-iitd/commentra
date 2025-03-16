import java.util.Scanner;

public class Main {
    // Modulus constant for fast modular arithmetic
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        // Read input string length
        Scanner scanner = new Scanner(System.in);
        String l = scanner.nextLine();
        int n = l.length();

        // Initialize 2D dynamic programming table
        long[][] dp = new long[n + 1][2];

        // Base case: empty string has 1 solution
        dp[0][0] = 1;

        // Iterate through each character in the input string
        for (int i = 0; i < n; i++) {
            char c = l.charAt(i);
            // Update dp[i+1][0] based on current character '0' or '1'
            if (c == '0') {
                dp[i + 1][0] += dp[i][0];
                dp[i + 1][1] += dp[i][1] * 3;
            } else {
                dp[i + 1][0] += dp[i][0] * 2;
                dp[i + 1][1] += dp[i][0];
                dp[i + 1][1] += dp[i][1] * 3;
            }

            // Perform modular arithmetic to keep the values within the modulus
            dp[i + 1][0] %= MOD;
            dp[i + 1][1] %= MOD;
        }

        // Calculate the final answer
        System.out.println((dp[n][0] + dp[n][1]) % MOD);
    }
}
// <END-OF-CODE>
