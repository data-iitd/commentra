
// Package main contains the entry point of the program.
package main;

import java.util.*;
import java.io.*;

// main function is the entry point of the program.
public class s918723842{
	public static void main(String[] args) {
		// Initialize a new Scanner object named sc.
		Scanner sc = new Scanner(System.in);
		// Read the height H, width W, and number of obstacles N from the standard input.
		int H = sc.nextInt();
		int W = sc.nextInt();
		int N = sc.nextInt();
		// Calculate the maximum dimension A between H and W.
		int A = Math.max(H, W);
		// Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
		System.out.println((N + A - 1) / A);
	}
}

// Scanner class represents the input reader.
class Scanner {
	// BufferedReader field br is used for reading from the standard input.
	BufferedReader br;
	// StringTokenizer field st is used for tokenizing the input.
	StringTokenizer st;

	// Constructor for Scanner class.
	public Scanner(InputStream in) {
		br = new BufferedReader(new InputStreamReader(in));
		eat("");
	}

	// eat method reads the next token from the input, which can be a single word, number, or symbol.
	// It skips leading whitespaces and returns the result as a string.
	private void eat(String s) {
		st = new StringTokenizer(s);
	}

	// next method reads the next token from the input and returns it as a string.
	public String next() {
		while (!st.hasMoreTokens())
			eat(nextLine());
		return st.nextToken();
	}

	// nextLine method reads the next line from the input and returns it as a string.
	public String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			return null;
		}
	}

	// nextInt method reads an integer from the input and returns it.
	public int nextInt() {
		return Integer.parseInt(next());
	}

	// nextInt64 method reads a 64-bit integer from the input and returns it.
	public long nextInt64() {
		return Long.parseLong(next());
	}

	// nextFloat method reads a floating-point number from the input and returns it.
	public double nextFloat() {
		return Double.parseDouble(next());
	}

	// nextIntArray method reads an array of integers from the input and returns it.
	public int[] nextIntArray() {
		String line = nextLine();
		String[] tokens = line.split(" ");
		int[] result = new int[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			result[i] = Integer.parseInt(tokens[i]);
		}
		return result;
	}

	// nextInt64Array method reads an array of 64-bit integers from the input and returns it.
	public long[] nextInt64Array() {
		String line = nextLine();
		String[] tokens = line.split(" ");
		long[] result = new long[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			result[i] = Long.parseLong(tokens[i]);
		}
		return result;
	}

	// nextMap method reads a map from the input and returns it.
	public Map<Integer, Boolean> nextMap() {
		String line = nextLine();
		String[] tokens = line.split(" ");
		Map<Integer, Boolean> mp = new HashMap<>();
		for (String token : tokens) {
			int key = Integer.parseInt(token.split(":")[0]);
			mp.put(key, true);
		}
		return mp;
	}
}

