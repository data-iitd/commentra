package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader reader;
	BufferedWriter writer;

	void run() throws IOException {
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new BufferedWriter(new OutputStreamWriter(System.out));
		solve();
		writer.close();
	}

	void solve() throws IOException {
		int N = nextInt();
		int M = nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = nextInt();
		}
		int maxProfit = 0;
		int maxCnt = 0;
		int maxA = A[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			int profit = Math.max(0, maxA - A[i]);
			if (maxProfit < profit) {
				maxProfit = profit;
				maxCnt = 1;
			} else if (maxProfit == profit) {
				maxCnt++;
			}
			maxA = Math.max(maxA, A[i]);
		}
		out(maxCnt);
	}

	String next() throws IOException {
		while (reader.ready()) {
			return reader.readLine();
		}
		return null;
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	void out(Object... o) throws IOException {
		writer.write(Arrays.deepToString(o));
		writer.write("\n");
	}
}

