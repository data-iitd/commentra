import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Initialize a dp vector to store the minimum cost to reach each step
    int[] dp = new int[101000];
    Arrays.fill(dp, Integer.MAX_VALUE);
    dp[0] = 0; // Base case: cost to reach the first step is 0

    // Input the number of steps (N) and the maximum jump distance (K)
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int K = sc.nextInt();
    int[] h = new int[N]; // Vector to store the heights of the steps
    for (int i = 0; i < N; i++) h[i] = sc.nextInt(); // Read the heights of the steps

    // Dynamic programming to calculate the minimum cost to reach each step
    for (int i = 0; i < N; i++) {
      // Check possible jumps from the current step
      for (int j = 1; j <= K; j++) {
        // Update the minimum cost to reach step i + j
        dp[i + j] = Math.min(dp[i + j], dp[i] + Math.abs(h[i] - h[i + j]));
      }
    }

    // Output the minimum cost to reach the last step
    System.out.println(dp[N - 1]);
  }
}

