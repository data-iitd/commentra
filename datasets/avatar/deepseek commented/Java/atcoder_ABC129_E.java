import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
        int M = 1000000007; // Defining a constant for modulo operation
        char[] s = sc.nextLine().toCharArray(); // Reading the input string and converting it to a char array
        int n = s.length; // Getting the length of the input string
        int[][] dp = new int[n + 1][2]; // Initializing the dynamic programming table
        dp[0][0] = 1; // Setting the base case for dp[0][0]

        // Iterating through each character of the input string
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                dp[i + 1][0] = dp[i][0]; // Copying the previous state for '0'
                dp[i + 1][1] = dp[i][1]; // Copying the previous state for '0'
            } else {
                dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M; // Updating dp[i+1][1] for '1'
            }

            // Additional updates for '0' and '1'
            if (s[i] == '0') {
                dp[i + 1][1] += (dp[i][1] * 2) % M; // Updating dp[i+1][1] for '0'
                dp[i + 1][1] %= M; // Ensuring the value stays within the modulo range
            } else {
                dp[i + 1][0] += (dp[i][0] * 2) % M; // Updating dp[i+1][0] for '1'
                dp[i + 1][1] += (dp[i][1] * 2) % M; // Updating dp[i+1][1] for '1'
                dp[i + 1][0] %= M; // Ensuring the value stays within the modulo range
                dp[i + 1][1] %= M; // Ensuring the value stays within the modulo range
            }
        }

        // Printing the result as the sum of dp[n][0] and dp[n][1] modulo M
        System.out.println((dp[n][0] + dp[n][1]) % M);
    }
}
