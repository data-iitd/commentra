import java.util.Scanner;

public class Main {
    // Minimum update function
    private static void chmin(int[] a, int index, int b) {
        if (a[index] > b) {
            a[index] = b;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Initialize dynamic programming array dp with initial value INF for all indices
        final int INF = 1 << 30;
        int[] dp = new int[101000];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;

        // Read input
        int N = scanner.nextInt(); // Number of elements in the array
        int K = scanner.nextInt(); // The size of the window
        int[] h = new int[N]; // Array of heights
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt(); // Read each height from the input
        }

        // Dynamic programming calculation
        for (int i = 0; i < N; i++) { // Iterate through all indices i
            for (int j = 1; j <= K; j++) { // Iterate through all window sizes j
                if (i + j < N) { // Ensure we do not go out of bounds
                    chmin(dp, i + j, dp[i] + Math.abs(h[i] - h[i + j]));
                }
            }
        }

        // Output the result
        System.out.println(dp[N - 1]); // Print the minimum cost to reach the last index with window size K
        scanner.close();
    }
}
// <END-OF-CODE>
