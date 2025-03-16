package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		Map<Integer, Integer> aa = new HashMap<Integer, Integer>();
		for (int i = 0; i < m; i++) {
			aa.put(scanner.nextInt(), 1);
		}

		int[] dp = new int[n + 1];
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
				if (aa.containsKey(i + ii)) {
					continue;
				}
				dp[i + ii] += dp[i];
				dp[i + ii] %= 1000000007;
			}
		}
		System.out.println(dp[n]);
	}
}

