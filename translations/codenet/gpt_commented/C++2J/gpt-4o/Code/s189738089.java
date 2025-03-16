import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Function to update the minimum value
    private static void chmin(int[] a, int index, int b) {
        if (a[index] > b) {
            a[index] = b;
        }
    }

    public static void main(String[] args) {
        final int INF = 1 << 30; // Define a constant for infinity
        Scanner scanner = new Scanner(System.in);

        // Initialize a dp array to store the minimum cost to reach each step
        int[] dp = new int[101000];
        Arrays.fill(dp, INF);
        dp[0] = 0; // Base case: cost to reach the first step is 0

        // Input the number of steps (N) and the maximum jump distance (K)
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] h = new int[N]; // Array to store the heights of the steps
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt(); // Read the heights of the steps
        }

        // Dynamic programming to calculate the minimum cost to reach each step
        for (int i = 0; i < N; i++) {
            // Check possible jumps from the current step
            for (int j = 1; j <= K; j++) {
                if (i + j < N) { // Ensure we do not go out of bounds
                    chmin(dp, i + j, dp[i] + Math.abs(h[i] - h[i + j]));
                }
            }
        }

        // Output the minimum cost to reach the last step
        System.out.println(dp[N - 1]);
        scanner.close();
    }
}
// <END-OF-CODE>
