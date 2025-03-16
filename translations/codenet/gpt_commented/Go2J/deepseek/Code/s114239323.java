import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt();
        }

        int[] dp = new int[N];
        for (int i = 0; i < N; i++) {
            dp[i] = 0; // Set initial values to zero
        }

        // Base case: cost to jump from the first to the second height
        dp[1] = Math.abs(h[0] - h[1]);

        // Fill the dp slice with minimum costs for each position
        for (int i = 2; i < N; i++) {
            dp[i] = Math.min(
                dp[i - 1] + Math.abs(h[i] - h[i - 1]), // Cost from the previous height
                dp[i - 2] + Math.abs(h[i] - h[i - 2])  // Cost from two heights back
            );
        }

        // Output the minimum cost to reach the last height
        System.out.println(dp[N - 1]);
    }
}
