import java.util.Scanner;

public class Knapsack {
    // max function returns the maximum of two integers.
    private static int max(int lhs, int rhs) {
        return Math.max(lhs, rhs);
    }

    public static void main(String[] args) {
        // Declare variables for the number of items (N) and the maximum weight (M).
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Initialize arrays to hold the weights and values of the items.
        int[] values = new int[N];
        int[] weights = new int[N];

        // Read the weights and values of each item from standard input.
        for (int i = 0; i < N; i++) {
            weights[i] = scanner.nextInt();
            values[i] = scanner.nextInt();
        }

        // Initialize a 2D array for dynamic programming table.
        int[][] dp = new int[N + 1][M + 1];

        // Fill the dynamic programming table.
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                // If the current item is not included, carry forward the previous value.
                dp[i][j] = dp[i - 1][j];

                // If the current item's weight is less than or equal to the current capacity.
                if (j >= weights[i - 1]) {
                    // Calculate the maximum value by including the current item.
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
                }
            }
        }

        // Output the maximum value that can be obtained with the given weight limit.
        System.out.println(dp[N][M]);
        scanner.close();
    }
}
// <END-OF-CODE>
