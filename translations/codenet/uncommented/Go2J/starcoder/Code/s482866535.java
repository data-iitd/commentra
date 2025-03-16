package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = scanner.nextInt();
		int[] mm = new int[n+1];
		int[][] dp = new int[n+1][n+1];
		for (int i = 0; i <= n; i++) {
			dp[i][i] = 0;
		}
		for (int i = 0; i < n; i++) {
			mm[i] = scanner.nextInt();
			mm[i+1] = scanner.nextInt();
		}

		for (int l = 2; l <= n; l++) {
			for (int i = 1; i <= n-l+1; i++) {
				int j = i + l - 1;
				for (int k = i; k <= j-1; k++) {
					int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
					if (dp[i][j] == 0 || dp[i][j] > d) {
						dp[i][j] = d;
					}
				}
			}
		}

		writer.write(Integer.toString(dp[1][n]));
		writer.newLine();

		writer.flush();
		writer.close();
	}
}

