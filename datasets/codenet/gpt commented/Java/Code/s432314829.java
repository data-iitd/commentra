import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from standard input
        Scanner stdIn = new Scanner(System.in);

        // Read the total number of steps (n) and the number of blocked steps (m)
        int n = stdIn.nextInt();
        int m = stdIn.nextInt();

        // Initialize a dynamic programming array to store the number of ways to reach each step
        int dp[] = new int[n + 2];

        // Base cases: 
        // dp[n + 1] represents the step beyond the last step (0 ways to reach)
        dp[n + 1] = 0;
        // dp[n] represents the last step (1 way to reach it)
        dp[n] = 1;

        // Mark the blocked steps in the dp array
        for (int i = 0; i < m; i++)
            dp[stdIn.nextInt()] = -1; // -1 indicates a blocked step

        // Fill the dp array from the second last step down to the first step
        for (int i = n - 1; i >= 0; i--) {
            // If the current step is blocked, set the number of ways to 0
            if (dp[i] == -1)
                dp[i] = 0;
            else
                // Calculate the number of ways to reach the current step
                // by summing the ways to reach the next two steps
                dp[i] = (dp[i + 1] + dp[i + 2]) % 1000000007; // Use modulo to prevent overflow
        }

        // Output the number of ways to reach the first step
        System.out.println(dp[0]);
    }
}
