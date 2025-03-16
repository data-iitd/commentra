
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		// Read an integer n from the standard input
		int n = nextInt();
		
		// Calculate the square root of n and store it in rt
		int rt = (int) Math.sqrt(n);
		
		// Initialize minf to 100, which will hold the minimum number of digits
		int minf = 100;
		
		// Iterate from 1 to rt + 1 to find divisors of n
		for (int i = 1; i < rt+1; i++) {
			if (n % i == 0) {
				// If i is a divisor of n, calculate the quotient b
				int b = n / i;
				
				// Count the number of digits in b
				int ndigit = 0;
				while (b > 0) {
					b /= 10;
					ndigit++;
				}
				
				// Update minf with the minimum number of digits found
				minf = Math.min(minf, ndigit);
			}
		}
		
		// Print the minimum number of digits
		System.out.println(minf);
	}
	
	// Read a line from the standard input
	private static String nextLine() throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line = "";
		String buffer = "";
		boolean isPrefix = true;
		while (isPrefix) {
			line = reader.readLine();
			buffer += line;
			isPrefix = line.endsWith(" ");
		}
		return buffer;
	}
	
	// Split the input line into a string array
	private static String[] nextStringArray() throws IOException {
		return nextLine().split(" ");
	}
	
	// Read an integer from the standard input
	private static int nextInt() throws IOException {
		return Integer.parseInt(nextLine());
	}
	
	// Read an integer array from the standard input
	private static int[] nextIntArray() throws IOException {
		String[] s = nextStringArray();
		int n = s.length;
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(s[i]);
		}
		return a;
	}
	
	// Return the minimum of two integers
	private static int min(int i, int j) {
		if (i > j) {
			return j;
		}
		return i;
	}
}

