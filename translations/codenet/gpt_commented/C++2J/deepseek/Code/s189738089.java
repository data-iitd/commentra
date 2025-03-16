import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Function to update the minimum value
    static <T extends Comparable<T>> void chmin(T[] a, int index, T value) {
        if (a[index].compareTo(value) > 0) {
            a[index] = value;
        }
    }

    public static void main(String[] args) {
        // Initialize a dp array to store the minimum cost to reach each step
        final int INF = 1 << 30; // Define a constant for infinity
        int N, K;
        Scanner scanner = new Scanner(System.in);

        // Input the number of steps (N) and the maximum jump distance (K)
        N = scanner.nextInt();
        K = scanner.nextInt();
        int[] h = new int[N]; // Array to store the heights of the steps
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt(); // Read the heights of the steps
        }

        // Initialize dp array with infinity values
        Integer[] dp = new Integer[101000];
        Arrays.fill(dp, INF);
        dp[0] = 0; // Base case: cost to reach the first step is 0

        // Dynamic programming to calculate the minimum cost to reach each step
        for (int i = 0; i < N; i++) {
            // Check possible jumps from the current step
            for (int j = 1; j <= K; j++) {
                if (i + j < N) {
                    // Update the minimum cost to reach step i + j
                    chmin(dp, i + j, dp[i] + Math.abs(h[i] - h[i + j]));
                }
            }
        }

        // Output the minimum cost to reach the last step
        System.out.println(dp[N - 1]);
    }
}
