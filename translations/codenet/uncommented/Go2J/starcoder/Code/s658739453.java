package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p = sc.nextInt();
		sc.close();

		long[] mdans = new long[p];
		for (int i = 0; i < p; i++) {
			mdans[i] = sc.nextLong();
		}

		long[] dp = new long[n + 1];
		dp[0] = 1;
		dp[1] = 1;

		if (mdans[0] == 1) {
			dp[1] = 0;
		}

		for (int i = 2; i <= n; i++) {
			if (mdans[i - 1] == 1) {
				continue;
			}
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
		}

		System.out.println(dp[n]);
	}
}

