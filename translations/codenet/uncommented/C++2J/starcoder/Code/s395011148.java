import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		int[][][] dp = new int[N + 1][2][20];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < 20; j++) {
				dp[i][0][j] = -(1 << 60);
				dp[i][1][j] = -(1 << 60);
			}
		}
		dp[0][0][10] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 6; j <= 14; j++) {
				if (dp[i - 1][0][j]!= -(1 << 60)) {
					dp[i][1][j + 1] = Math.max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
					dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][0][j]);
				}
				if (dp[i - 1][1][j]!= -(1 << 60)) {
					dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][1][j]);
				}
			}
		}

		int V = 10 + (N / 2) - (N - (N / 2));
		int T1 = dp[N][0][V];
		int T2 = dp[N][1][V];
		System.out.println(Math.max(T1, T2));
	}
}

