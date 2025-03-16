
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner();

		// Read the first string from the standard input
		String S = sc.next();

		// Check if the string starts with "YAKI"
		if (S.startsWith("YAKI")) {
			System.out.println("Yes"); // Print "Yes" if the condition is true
		} else {
			System.out.println("No"); // Print "No" if the condition is false
		}
	}

	// Minimum function
	public static int min(int a, int b) {
		// Determine the minimum of two integers
		if (a > b) {
			return b;
		}
		return a;
	}

	// Maximum function
	public static int max(int a, int b) {
		// Determine the maximum of two integers
		if (a > b) {
			return a;
		}
		return b;
	}

	// Scanner structure definition
	public static class Scanner {

		// Initialize a new scanner instance
		public Scanner() {
			this.r = new BufferedReader(new InputStreamReader(System.in));
		}

		// Next function to read the next token as a string
		public String next() {
			pre();
			int start = this.p;
			for (; this.p < this.buf.length; this.p++) {
				if (this.buf[this.p] == ' ') {
					break;
				}
			}
			String result = new String(this.buf, start, this.p - start);
			this.p++;
			return result;
		}

		// NextLine function to read the next line as a string
		public String nextLine() {
			pre();
			int start = this.p;
			this.p = this.buf.length;
			return new String(this.buf, start, this.p - start);
		}

		// NextInt function to read the next integer from the standard input
		public int nextInt() {
			return Integer.parseInt(next());
		}

		// NextIntArray function to read an array of integers from the standard input
		public int[] nextIntArray() {
			pre();
			int start = this.p;
			int[] result = new int[0];
			for (; this.p < this.buf.length + 1; this.p++) {
				if (this.p == this.buf.length || this.buf[this.p] == ' ') {
					String v = new String(this.buf, start, this.p - start);
					result = append(result, Integer.parseInt(v));
					start = this.p + 1;
				}
			}
			return result;
		}

		// Pre function to prepare the scanner for reading the next token
		public void pre() {
			if (this.p >= this.buf.length) {
				this.readLine();
				this.p = 0;
			}
		}

		// ReadLine function to read a line from the standard input
		public void readLine() {
			this.buf = new char[0];
			for (; ; ) {
				int[] l = new int[1];
				boolean[] p = new boolean[1];
				try {
					l[0] = this.r.read(this.buf, this.buf.length, 1000 - this.buf.length);
					p[0] = l[0] < 1000 - this.buf.length;
				} catch (Exception e) {
					throw new RuntimeException(e);
				}
				if (p[0]) {
					break;
				}
			}
		}

		// Append function to append an integer to an array of integers
		public static int[] append(int[] a, int v) {
			int[] result = new int[a.length + 1];
			for (int i = 0; i < a.length; i++) {
				result[i] = a[i];
			}
			result[a.length] = v;
			return result;
		}

		// BufferedReader instance
		private BufferedReader r;

		// Input buffer
		private char[] buf;

		// Current position
		private int p;
	}

	// END-OF-CODE
}



Translate the above Java code to C++ and end with comment "