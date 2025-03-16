import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Array to store computed results for dynamic programming
    static long[] dp;
    // Modulus value to prevent overflow
    static int mod = 1000000007;

    public static void main(String[] args) throws Exception {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        // Read the integer input 's' from the user
        int s = sc.nextInt();
        // Close the scanner to prevent resource leaks
        sc.close();

        // Initialize the dp array with size s + 1 and fill it with -1
        dp = new long[s + 1];
        Arrays.fill(dp, -1);
        // Base case: there is one way to achieve a sum of 0
        dp[0] = 1;
        // Call the dfs function to compute the result and print it
        System.out.println(dfs(s));
    }

    // Recursive function to compute the number of ways to achieve the sum 's'
    static long dfs(int s) {
        // If the result for this sum has already been computed, return it
        if (dp[s] != -1) {
            return dp[s];
        }

        // Variable to accumulate the number of ways to achieve the sum
        long ret = 0;
        // Iterate from s - 3 down to 0 to explore all possible previous sums
        for (int i = s - 3; i >= 0; i--) {
            // Recursively call dfs to find the number of ways for the previous sum
            ret += dfs(i);
            // Apply modulus to prevent overflow
            ret %= mod;
        }
        // Store the computed result in the dp array and return it
        return dp[s] = ret;
    }
}
