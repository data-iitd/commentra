import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = in.nextInt();

		// Initialize dp array with minimum values
		int[][][] dp = new int[N + 1][2][20];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < 20; j++) {
				dp[i][0][j] = -(1 << 60); // Initialize dp[i][0][j] with a very large negative value
				dp[i][1][j] = -(1 << 60); // Initialize dp[i][1][j] with a very large negative value
			}
		}

		// Base case: dp[0][0][10] = 0
		dp[0][0][10] = 0;

		// Iterate through all the elements of the array A
		for (int i = 1; i <= N; i++) {
			for (int j = 6; j <= 14; j++) { // We only consider the cases where j is between 6 and 14
				if (dp[i - 1][0][j]!= -(1 << 60)) { // If dp[i-1][0][j] is not equal to the very large negative value
					dp[i][1][j + 1] = Math.max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]); // Update dp[i][1][j+1] with the maximum of its current value and dp[i-1][0][j] + A[i]
					dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][0][j]); // Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][0][j]
				}
				if (dp[i - 1][1][j]!= -(1 << 60)) { // If dp[i-1][1][j] is not equal to the very large negative value
					dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][1][j]); // Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][1][j]
				}
			}
		}

		// Calculate the value of T1 and T2
		int V = 10 + (N / 2) - (N - (N / 2));
		int T1 = dp[N][0][V];
		int T2 = dp[N][1][V];

		// Print the maximum value of T1 and T2
		System.out.println(Math.max(T1, T2));
	}
}

