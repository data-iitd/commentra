
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner s = new Scanner(System.in);
        
        // Read the number of elements
        int n = Integer.parseInt(s.next());
        
        // Initialize arrays to store values and costs
        int[] v = new int[n];
        int[] c = new int[n];
        int[] dp = new int[n];

        // Initialize the dp array to 0
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
        }
        
        // Read the values of the elements
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(s.next());
        }
        
        // Read the costs of the elements
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(s.next());
        }

        // Initialize the dp array at index 0 to 0
        dp[0] = 0;

        // Calculate the maximum difference using dynamic programming
        for (int i = 1; i < n; i++) {
            int tmp = dp[i - 1] + (v[i - 1] - c[i - 1]);
            dp[i] = tmp > dp[i - 1] ? tmp : dp[i - 1];
        }

        // Calculate the final maximum difference
        int tmp = dp[n - 1] + (v[n - 1] - c[n - 1]);
        dp[n - 1] = tmp > dp[n - 1] ? tmp : dp[n - 1];

        // Print the maximum difference value
        System.out.println(dp[n - 1]);
    }
}

I hope this helps! Let me know if you have any further questions.