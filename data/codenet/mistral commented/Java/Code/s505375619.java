
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the console
        Scanner s = new Scanner(System.in);

        // Read the number of elements in the array from the user input
        int n = Integer.parseInt(s.next());

        // Allocate memory for two arrays: one for storing the values and another for storing the costs
        int[] v = new int[n];
        int[] c = new int[n];

        // Allocate memory for a dynamic programming array to store the maximum profit at each index
        int[] dp = new int[n];

        // Initialize all elements of the dp array to 0
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
        }

        // Read the values and costs from the user input and store them in the respective arrays
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(s.next());
        }
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(s.next());
        }

        // Initialize the first element of the dp array to 0 as there is no previous element to consider
        dp[0] = 0;

        // Iterate through the remaining elements of the dp array and calculate the maximum profit at each index
        for (int i = 1; i < n; i++) {
            // Calculate the maximum profit by considering the previous element or not
            int tmp = dp[i - 1] + (v[i - 1] - c[i - 1]);
            dp[i] = tmp > dp[i - 1] ? tmp : dp[i - 1];
        }

        // Calculate the maximum profit for the last element by considering it or not
        int tmp = dp[n - 1] + (v[n - 1] - c[n - 1]);
        dp[n - 1] = tmp > dp[n - 1] ? tmp : dp[n - 1];

        // Print the maximum profit obtained from the dynamic programming approach
        System.out.println(dp[n - 1]);
    }
}

