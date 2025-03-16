import java.util.Scanner;

public class Main {
    // Function to find the maximum of two integers
    public static int max(int lhs, int rhs) {
        return Math.max(lhs, rhs);
    }

    public static void main(String[] args) {
        // Initialize variables N and M to read input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        // Initialize arrays values and weights of size N to read input
        int[] values = new int[N];
        int[] weights = new int[N];
        // Read input values and weights for each index i from 0 to N-1
        for (int i = 0; i < N; i++) {
            // Read input values and weights using nextInt() and store in respective arrays
            weights[i] = scanner.nextInt();
            values[i] = scanner.nextInt();
        }
        // Initialize 2D array dp of size (N+1) x (M+1)
        int[][] dp = new int[N + 1][M + 1];
        // Iterate through each index i from 1 to N and each index j from 0 to M
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                // Initialize dp[i][j] with dp[i-1][j]
                dp[i][j] = dp[i - 1][j];
                // If j is greater than or equal to the weight of the current index i-1,
                // update dp[i][j] with the maximum value between dp[i][j] and dp[i-1][j-weights[i-1]]+values[i-1]
                if (j >= weights[i - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
                }
            }
        }
        // Print the final value of dp[N][M]
        System.out.println(dp[N][M]);
        // End of the code
    }
}
