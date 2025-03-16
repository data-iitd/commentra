package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		// Create an Io instance for reading input
		Io io = new Io();
		// Parse input using the NextInt function of the Io instance
		int X = io.NextInt();
		int N = io.NextInt();
		int[] p = new int[N];
		for (int i = 0; i < N; i++) {
			p[i] = io.NextInt();
		}
		// Check if X or its neighbors are present in the p slice
		for (int i = 0; i <= 100; i++) {
			if (find(X-i, p) == 1) {
				System.out.println(X-i);
				return;
			}
			if (find(X+i, p) == 1) {
				System.out.println(X+i);
				return;
			}
		}
		// Output generation part is not present in the code
		// // OUTPUT GENERATION PART
		// int ans = 0;
		// System.out.println(ans);
		// If ans > 0, print "Yes" and exit; otherwise, print "No"
		// if (ans > 0) {
		//   System.out.println("Yes");
		// } else {
		//   System.out.println("No");
		// }
	}

	// find function checks if a given number n is present in the p slice
	public static int find(int n, int[] p) {
		for (int i = 0; i < p.length; i++) {
			if (n == p[i]) {
				return 0;
			}
		}
		return 1;
	}
}

class Io {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public Io() {
		reader = new BufferedReader(new InputStreamReader(System.in));
		tokenizer = new StringTokenizer("");
	}

	public void Flush() throws Exception {
		reader.close();
	}

	public String Next() throws Exception {
		while (!tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public int NextInt() throws Exception {
		return Integer.parseInt(Next());
	}

	public long NextLong() throws Exception {
		return Long.parseLong(Next());
	}

	public double NextDouble() throws Exception {
		return Double.parseDouble(Next());
	}
}

