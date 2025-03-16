
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

public class s940795037{
	// Creating a new scanner instance
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		// Reading the first integer from the standard input
		int n = sc.nextInt();
		// Initializing the answer variable
		double ans = 0.0;

		// Iterating through the given number of integers
		for (int i = 0; i < n; i++) {
			// Reading the next integer from the standard input
			int tmp = 1 / sc.nextInt();
			// Adding the reciprocal of the current integer to the answer
			ans += tmp;
		}

		// Printing the final answer
		System.out.printf("%.10f\n", 1 / ans);
	}
}

// Scanner class definition
class Scanner {
	// Defining the reader instance
	private BufferedReader r;
	private String[] buf;
	private int p;

	// Constructor to initialize the scanner instance with the reader instance
	public Scanner(InputStream in) {
		r = new BufferedReader(new InputStreamReader(in));
		buf = new String[0];
		p = 0;
	}

	// Next function reads the next token from the standard input
	String next() {
		// Preprocessing the input buffer
		pre();
		// Reading the next token from the input buffer
		String result = buf[p];
		// Incrementing the position of the input buffer pointer
		p++;
		// Returning the token
		return result;
	}

	// NextLine function reads the next line from the standard input
	String nextLine() {
		// Preprocessing the input buffer
		pre();
		// Reading the next line from the input buffer
		String result = Arrays.stream(buf, p, buf.length).collect(Collectors.joining(" "));
		// Incrementing the position of the input buffer pointer to the end of the line
		p = buf.length;
		// Returning the line
		return result;
	}

	// NextInt function reads the next integer from the standard input
	int nextInt() {
		// Reading the next token as a string
		String token = next();
		// Converting the token to an integer
		return Integer.parseInt(token);
	}

	// NextIntArray function reads an array of integers from the standard input
	int[] nextIntArray() {
		// Reading the next token as a string
		String token = next();
		// Initializing an empty array
		List<Integer> result = new ArrayList<>();
		// Reading each integer from the standard input and appending it to the array
		while (token.length() > 0 && token.charAt(token.length() - 1) >= '0' && token.charAt(token.length() - 1) <= '9') {
			// Converting the token to an integer and appending it to the array
			result.add(Integer.parseInt(token));
			// Reading the next token
			token = next();
			// If the current token is not a space character, then there is an error in the input
			if (token.charAt(0)!='') {
				throw new RuntimeException("Invalid input");
			}
		}
		// Returning the array
		return result.stream().mapToInt(i -> i).toArray();
	}

	// NextMap function reads a map from the standard input
	Map<Integer, Boolean> nextMap() {
		// Reading the next token as a string
		String token = next();
		// Initializing an empty map
		Map<Integer, Boolean> result = new HashMap<>();
		// Reading each key-value pair from the standard input and adding it to the map
		while (token.length() > 0 && token.charAt(token.length() - 1) >= '0' && token.charAt(token.length() - 1) <= '9') {
			// Converting the token to an integer and adding it as a key to the map
			int k = Integer.parseInt(token);
			result.put(k, true);
			// Reading the next token
			token = next();
			// If the current token is not a colon character, then there is an error in the input
			if (token.charAt(0)!= ':') {
				throw new RuntimeException("Invalid input");
			}
			// Reading the next token as a boolean value
			boolean v = next().equals("true");
			// Adding the value to the map
			result.put(k, v);
			// If the current token is not a space character, then there is an error in the input
			if (token.charAt(0)!='') {
				throw new RuntimeException("Invalid input");
			}
		}
		// Returning the map
		return result;
	}

	// Pre function preprocesses the input buffer
	void pre() {
		// If the position of the input buffer pointer is at the end of the buffer, then reading the next line from the standard input
		if (p >= buf.length) {
			buf = nextLine().split(" ");
			p = 0;
		}
	}
}

