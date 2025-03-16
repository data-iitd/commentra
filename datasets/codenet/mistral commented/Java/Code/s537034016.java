import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Declare static variables
    static long[] dp;
    static int mod = 1000000007;

    public static void main(String[] args) throws Exception {
        // Initialize scanner to read input from the standard input
        Scanner sc = new Scanner(System.in);

        // Read the first integer from the input
        int s = sc.nextInt();
        // Close the scanner to save resources
        sc.close();

        // Initialize a long array 'dp' of size 's+1' with all elements set to -1
        dp = new long[s + 1];
        Arrays.fill(dp, -1);
        // Set the first element of dp to 1
        dp[0] = 1;

        // Call the recursive function 'dfs' with the given integer 's' and print the result
        System.out.println(dfs(s));
    }

    // Recursive function to calculate the number of ways to represent 's' as the sum of three integers
    static long dfs(int s) {
        // If dp[s] has already been calculated, return the value from dp
        if (dp[s] != -1) {
            return dp[s];
        }

        // Initialize a long variable 'ret' to 0
        long ret = 0;
        // Iterate through the numbers from 's-3' down to 0
        for (int i = s - 3; i >= 0; i--) {
            // Add the result of recursively calling 'dfs' with 'i' to 'ret'
            ret += dfs(i);
            // Modulo the result by 'mod' to keep the value within the range
            ret %= mod;
        }
        // Set dp[s] to the calculated value of 'ret'
        return dp[s] = ret;
    }
}
