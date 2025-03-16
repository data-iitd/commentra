import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);

        int n = stdIn.nextInt(); // Read the number of steps
        int m = stdIn.nextInt(); // Read the number of blocked steps
        int dp[] = new int[n + 2]; // Initialize the dp array with size n+2
        dp[n + 1] = 0; // Set the last element to 0
        dp[n] = 1; // Set the second last element to 1 (base case)

        // Read the blocked steps and set their corresponding dp values to -1
        for (int i = 0; i < m; i++)
            dp[stdIn.nextInt()] = -1;

        // Fill the dp array from n-1 down to 0
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == -1)
                dp[i] = 0; // If the step is blocked, set dp[i] to 0
            else
                dp[i] = (dp[i + 1] + dp[i + 2]) % 1000000007; // Calculate the number of ways to reach the step
        }

        // Print the number of ways to reach the first step
        System.out.println(dp[0]);
    }
}
