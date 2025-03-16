import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner s = new Scanner(System.in);
        
        // Read the number of items (n) from input
        int n = Integer.parseInt(s.next());
        
        // Initialize arrays to hold values (v), costs (c), and dynamic programming results (dp)
        int[] v = new int[n];
        int[] c = new int[n];
        int[] dp = new int[n];

        // Initialize the dp array to zero
        for (int i = 0; i < n; i++) {
            dp[i] = 0; // Base case: no items means zero profit
        }

        // Read the values of the items from input
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(s.next());
        }

        // Read the costs of the items from input
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(s.next());
        }

        // Set the first element of dp to zero (base case)
        dp[0] = 0;

        // Fill the dp array using a dynamic programming approach
        for (int i = 1; i < n; i++) {
            // Calculate the profit if the current item is included
            int tmp = dp[i - 1] + (v[i - 1] - c[i - 1]);
            // Update dp[i] to the maximum profit between including or excluding the current item
            dp[i] = tmp > dp[i - 1] ? tmp : dp[i - 1];
        }

        // Calculate the profit for the last item and update dp[n-1]
        int tmp = dp[n - 1] + (v[n - 1] - c[n - 1]);
        dp[n - 1] = tmp > dp[n - 1] ? tmp : dp[n - 1];

        // Output the maximum profit that can be achieved
        System.out.println(dp[n - 1]);
    }
}
