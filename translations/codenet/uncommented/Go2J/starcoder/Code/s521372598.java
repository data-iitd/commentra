package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader br;
	PrintWriter out;

	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int n = nextInt();
		int[] as = new int[n];
		for (int i = 0; i < n; i++) {
			as[i] = nextInt();
		}

		int[] xs = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = as[i] - i + 1;
		}
		Arrays.sort(xs);

		int b = xs[n / 2];
		int ans = 0;
		for (int x : xs) {
			ans += Math.abs(x - b);
		}
		out.println(ans);

		out.close();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}

	String nextString() throws IOException {
		return br.readLine();
	}
}

