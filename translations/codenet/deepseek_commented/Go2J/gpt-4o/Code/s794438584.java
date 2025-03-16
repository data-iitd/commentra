import java.util.Scanner;

public class Knapsack {
    // max returns the maximum of two integers.
    private static int max(int lhs, int rhs) {
        return Math.max(lhs, rhs);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // N: number of items
        int M = scanner.nextInt(); // M: maximum weight capacity
        
        int[] values = new int[N]; // Array to store values of items
        int[] weights = new int[N]; // Array to store weights of items
        
        for (int i = 0; i < N; i++) {
            weights[i] = scanner.nextInt(); // Read the weight of each item
            values[i] = scanner.nextInt(); // Read the value of each item
        }
        
        int[][] dp = new int[N + 1][M + 1]; // Initialize the DP table
        
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][j] = dp[i - 1][j]; // Inherit the maximum value from the previous item
                if (j >= weights[i - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]); // Update the DP table with the current item
                }
            }
        }
        
        System.out.println(dp[N][M]); // Print the maximum value that can be achieved
        scanner.close();
    }
}

// <END-OF-CODE>
