package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader br;
	BufferedWriter bw;
	StringTokenizer st;

	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		solve();
		bw.close();
	}

	void solve() throws IOException {
		int N, A, B, C;
		String[] X = br.readLine().split(" ");
		N = Integer.parseInt(X[0]);
		A = Integer.parseInt(X[1]);
		B = Integer.parseInt(X[2]);
		C = Integer.parseInt(X[3]);
		int[] arr = new int[N];
		int[][] dp = new int[N][4];
		int ans = 10000;
		for (int i = 0; i < N; i++) {
			String[] Y = br.readLine().split(" ");
			arr[i] = Integer.parseInt(Y[0]);
		}
		dfs(dp, 0, arr);
		bw.write(ans + "\n");
	}

	void dfs(int[][] dp, int times, int[] arr) {
		if (times >= N) {
			ans = Math.min(ans, calc(dp, arr));
			return;
		}
		for (int i = 0; i < 4; i++) {
			dp[times][i] = i;
			dfs(dp, times + 1, arr);
		}
	}

	int calc(int[][] dp, int[] arr) {
		int cost = 0, AA = 0, BB = 0, CC = 0;
		int[] memo = new int[4];
		for (int i = 0; i < N; i++) {
			memo[dp[i][0]]++;
			if (dp[i][0] == 1) {
				AA += arr[i];
			} else if (dp[i][0] == 2) {
				BB += arr[i];
			} else if (dp[i][0] == 3) {
				CC += arr[i];
			}
		}
		cost += Math.abs(A - AA) + Math.abs(B - BB) + Math.abs(C - CC);
		for (int i = 1; i < 4; i++) {
			int a = memo[i];
			if (a < 1) {
				cost += 10000;
			} else {
				cost += (a - 1) * 10;
			}
		}
		return cost;
	}
}

