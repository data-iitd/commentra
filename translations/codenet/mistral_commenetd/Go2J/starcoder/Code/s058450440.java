package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Creating an io object for input/output handling
		IO io = new IO();

		// Reading the number of test cases
		int n = io.nextInt();

		// Initializing an empty map to store the frequency of each character
		Map<Character, Integer> dic = new HashMap<Character, Integer>();

		// Reading strings and updating the map
		for (int i = 0; i < n; i++) {
			char c = io.nextString().charAt(0);
			switch (c) {
			case 'M':
				dic.put(c, dic.getOrDefault(c, 0) + 1);
				break;
			case 'A':
				dic.put(c, dic.getOrDefault(c, 0) + 1);
				break;
			case 'R':
				dic.put(c, dic.getOrDefault(c, 0) + 1);
				break;
			case 'C':
				dic.put(c, dic.getOrDefault(c, 0) + 1);
				break;
			case 'H':
				dic.put(c, dic.getOrDefault(c, 0) + 1);
				break;
			}
		}

		// Converting map values to integers and appending them to the 'a' slice
		int[] a = new int[dic.size()];
		int i = 0;
		for (int v : dic.values()) {
			a[i++] = v;
		}

		// Initializing variables
		int ans = 0;

		// Calling the 'dfs' function with initial arguments
		dfs(3, 0, 1, a, ans);

		// Printing the answer
		System.out.println(ans);
	}

	// Function to perform Depth First Search (DFS) algorithm
	public static void dfs(int left, int i, int res, int[] a, int ans) {
		// Base case
		if (left == 0) {
			ans += res;
			return;
		}

		// Recursive case
		for (int j = i; j < a.length; j++) {
			dfs(left - 1, j + 1, res * a[j], a, ans);
		}
	}
}

// Struct definition for input/output handling
class IO {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public IO() {
		reader = new BufferedReader(new InputStreamReader(System.in));
		tokenizer = new StringTokenizer("");
	}

	public String nextLine() throws IOException {
		return reader.readLine();
	}

	public String nextString() throws IOException {
		while (!tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(nextLine());
		}
		return tokenizer.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextString());
	}
}

// 