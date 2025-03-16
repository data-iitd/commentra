// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

// bufReader type is a custom reader that reads lines from os.Stdin
class bufReader {
	BufferedReader r;
	String line;
	public bufReader() {
		r = new BufferedReader(new InputStreamReader(System.in));
	}
	public String next() throws IOException {
		while (true) {
			if (line == null)
				line = r.readLine();
			if (line == null)
				return null;
			String ret = line;
			line = null;
			return ret;
		}
	}
	public int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	public String nextLine() throws IOException {
		return r.readLine();
	}
}

// bufWriter type is a custom writer that writes lines to os.Stdout
class bufWriter {
	BufferedWriter w;
	public bufWriter() {
		w = new BufferedWriter(new OutputStreamWriter(System.out));
	}
	public void print(Object... o) throws IOException {
		w.write(String.valueOf(o));
	}
	public void println(Object... o) throws IOException {
		w.write(String.valueOf(o));
		w.write("\n");
	}
	public void flush() throws IOException {
		w.flush();
	}
}

// Function nextInt64 parses an integer from the custom reader and returns it as an int64 type
static long nextInt64() throws IOException {
	return Long.parseLong(reader.next());
}

// Function nextInt parses an integer from the custom reader and returns it as an int type
static int nextInt() throws IOException {
	return Integer.parseInt(reader.next());
}

// Function nextLine reads a line from the custom reader and returns it as a string
static String nextLine() throws IOException {
	return reader.readLine();
}

// Function out is used for printing output to the console
static void out(Object... o) {
	writer.print(o);
}

// Function max64 returns the maximum of two int64 values
static long max64(long x, long y) {
	// If x is greater than y, return x; otherwise, return y
	if (x > y) {
		return x;
	}
	return y;
}

// Function max returns the maximum of two int values
static int max(int x, int y) {
	// Return the maximum of x and y as an int value
	return (int) max64(x, y);
}

// Function min64 returns the minimum of two int64 values
static long min64(long x, long y) {
	// If x is less than y, return x; otherwise, return y
	if (x < y) {
		return x;
	}
	return y;
}

// Function min returns the minimum of two int values
static int min(int x, int y) {
	// Return the minimum of x and y as an int value
	return (int) min64(x, y);
}

// Function abs64 returns the absolute value of an int64 value
static long abs64(long x) {
	// If x is negative, return the negative of x; otherwise, return x
	if (x < 0) {
		return -x;
	}
	return x;
}

// Function abs returns the absolute value of an int value
static int abs(int x) {
	// Return the absolute value of x as an int value
	return (int) abs64(x);
}

// Function joinInt64s joins an array of int64 values with a given separator and returns the resulting string
static String joinInt64s(long[] a, String sep) {
	// Create a StringBuilder
	StringBuilder sb = new StringBuilder();
	// Iterate through the array
	for (int i = 0; i < a.length; i++) {
		// If i is not the first element, append the separator
		if (i > 0) {
			sb.append(sep);
		}
		// Append the current element to the StringBuilder
		sb.append(a[i]);
	}
	// Return the resulting string
	return sb.toString();
}

// Function joinInts joins an array of int values with a given separator and returns the resulting string
static String joinInts(int[] a, String sep) {
	// Create a StringBuilder
	StringBuilder sb = new StringBuilder();
	// Iterate through the array
	for (int i = 0; i < a.length; i++) {
		// If i is not the first element, append the separator
		if (i > 0) {
			sb.append(sep);
		}
		// Append the current element to the StringBuilder
		sb.append(a[i]);
	}
	// Return the resulting string
	return sb.toString();
}

// Function divUp64 returns the smallest integer n such that n*divisor >= dividend
static long divUp64(long dividend, long divisor) {
	// Return the smallest integer n such that n*divisor >= dividend
	return (dividend + divisor - 1) / divisor;
}

// Function divUp returns the smallest integer n such that n*divisor >= dividend
static int divUp(int dividend, int divisor) {
	// Return the smallest integer n such that n*divisor >= dividend
	return (int) divUp64(dividend, divisor);
}

// Function gcd64 returns the greatest common divisor of two int64 values
static long gcd64(long x, long y) {
	// If x is greater than y, swap x and y
	if (x < y) {
		x = x + y;
		y = x - y;
		x = x - y;
	}
	// Iterate through the range of possible divisors
	for (long a = min(x, y); a > 0; a--) {
		// If x is divisible by a, return a
		if (x % a == 0 && y % a == 0) {
			return a;
		}
	}
	// Return 1 as the greatest common divisor
	return 1;
}

// Function gcd returns the greatest common divisor of two int values
static int gcd(int x, int y) {
	// Return the greatest common divisor of x and y as an int value
	return (int) gcd64(x, y);
}

// Function lcm64 returns the least common multiple of two int64 values
static long lcm64(long x, long y) {
	// Calculate the greatest common divisor of x and y
	long gcd = gcd64(x, y);
	// Return the product of x and y divided by their greatest common divisor
	return x * y / gcd;
}

// Function lcm returns the least common multiple of two int values
static int lcm(int x, int y) {
	// Return the least common multiple of x and y as an int value
	return (int) lcm64(x, y);
}

// Function pow64 returns x raised to the power of y as an int64 value
static long pow64(long x, long y) {
	// Return x raised to the power of y as an int64 value using the Math.pow function
	return (long) Math.pow(x, y);
}

// Function pow returns x raised to the power of y as an int value
static int pow(int x, int y) {
	// Return x raised to the power of y as an int value
	return (int) pow64(x, y);
}

// Function main is the entry point of the program
public class Main {
	// bufio.Reader instance
	static BufferedReader reader;
	// bufio.Writer instance
	static BufferedWriter writer;
	// Function main is the entry point of the program
	public static void main(String[] args) throws IOException {
		// Initialize the bufio.Reader and bufio.Writer
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new BufferedWriter(new OutputStreamWriter(System.out));
		// Read two integers N and K from the custom reader
		int N = nextInt();
		int K = nextInt();
		// Initialize an array A of size N
		int[] A = new int[N];
		// Read N integers from the custom reader and store them in the array A
		for (int i = 0; i < N; i++) {
			A[i] = nextInt();
		}
		// Initialize variables maxProfit, maxCnt, and maxA
		int maxProfit = 0;
		int maxCnt = 0;
		int maxA = A[N - 1];
		// Iterate through the array A from the last index to the first index
		for (int i = N - 2; i >= 0; i--) {
			// Calculate the profit of the current transaction
			int profit = max(0, maxA - A[i]);
			// If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
			if (maxProfit < profit) {
				maxProfit = profit;
				maxCnt = 1;
			} else if (maxProfit == profit) {
				maxCnt++;
			}
			// Update maxA with the maximum of the current element and maxA
			maxA = max(maxA, A[i]);
		}
		// Write the output to the console
		out(maxCnt);
		// Flush the bufio.Writer to write the output to the console
		writer.flush();
	}
}

