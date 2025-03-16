// Package main is the entry point of the program

import (
	// Importing required packages
	"bufio"
	"fmt"
	"os"
)

// Main function
public class Main {

	// Main function
	public static void main(String[] args) {
		// Initialize two empty strings S and T
		String S, T = ReadString(), ReadString();

		// Initialize max as 0
		int max = 0;

		// Loop through all possible substrings of S with length equal to T
		for (int i = 0; i <= S.length() - T.length(); i++) {
			// Initialize a counter c for the number of matching characters between S[i:i+len(T)] and T
			int c = 0;

			// Check character by character for matching characters
			for (int j = 0; j < T.length(); j++) {
				// If current characters match, increment counter c
				if (S.charAt(i + j) == T.charAt(j)) {
					c++;
				}
			}

			// If current substring has more matching characters than the current max, update max
			if (max < c) {
				max = c;
			}
		}

		// Print the length of the shortest substring of S that matches T with all characters
		System.out.println(T.length() - max);
	}

	// Helper functions to read input from stdin
	private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

	private static String readLine() throws IOException {
		return reader.readLine();
	}

	private static String[] readLines() throws IOException {
		String line = reader.readLine();
		if (line == null) {
			return null;
		}
		return line.split(" ");
	}

	private static String readString() throws IOException {
		return readLine();
	}

	private static String[] readStrings() throws IOException {
		return readLines();
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	private static int[] readInts() throws IOException {
		String[] strings = readStrings();
		if (strings == null) {
			return null;
		}
		int[] ints = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {
			ints[i] = Integer.parseInt(strings[i]);
		}
		return ints;
	}
}

// 