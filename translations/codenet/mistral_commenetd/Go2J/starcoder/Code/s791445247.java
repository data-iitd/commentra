
// by syu
package main;

import java.io.*;
import java.util.*;

public class Main {
	// Initialize a new scanner for reading input
	static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		// Read the first two integers from the standard input
		int n = in.nextInt();
		int k = in.nextInt();

		// Check if n is divisible by k
		if (n % k == 0) {
			// If it is, print 0
			System.out.println(0);
		} else {
			// If not, print 1
			System.out.println(1);
		}
	}
}

// Define a new Scanner type
class Scanner {
	// Initialize a new buffered reader for reading input
	BufferedReader br;
	// Initialize a new string tokenizer for reading input
	StringTokenizer st;

	public Scanner(InputStream s) {
		// Initialize a new buffered reader for reading input
		br = new BufferedReader(new InputStreamReader(s));
	}

	public int nextInt() {
		// Read the next token as a string
		st = new StringTokenizer(br.readLine());
		// Return the integer value
		return Integer.parseInt(st.nextToken());
	}
}

