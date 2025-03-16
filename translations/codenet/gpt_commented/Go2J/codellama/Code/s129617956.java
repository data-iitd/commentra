
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		// Read an integer input from the user
		int n = nextInt();
		
		// Calculate the integer square root of n
		int rt = (int) Math.sqrt(n);
		
		// Initialize a variable to keep track of the minimum number of digits found
		int minf = 100;
		
		// Loop through all integers from 1 to the square root of n
		for (int i = 1; i < rt+1; i++) {
			// Check if i is a divisor of n
			if (n % i == 0) {
				// Calculate the corresponding divisor b
				int b = n / i;
				
				// Initialize a counter for the number of digits in b
				int ndigit = 0;
				
				// Count the number of digits in b
				while (b > 0) {
					b /= 10;
					ndigit++;
				}
				
				// Update minf with the minimum number of digits found
				minf = Math.min(minf, ndigit);
			}
		}
		
		// Print the minimum number of digits found among the divisors
		System.out.println(minf);
	}
	
	// Function to read a full line of input
	public static String nextLine() {
		String line = "";
		
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			line = reader.readLine();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return line;
	}
	
	// Function to read a line of input and split it into a string array
	public static String[] nextStringArray() {
		return nextLine().split(" ");
	}
	
	// Function to read an integer from input
	public static int nextInt() {
		return Integer.parseInt(nextLine());
	}
	
	// Function to read a line of input and convert it into an array of integers
	public static int[] nextIntArray() {
		String[] s = nextStringArray();
		int n = s.length;
		int[] a = new int[n];
		
		// Convert each string in the array to an integer
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(s[i]);
		}
		return a;
	}
	
	// Function to return the minimum of two integers
	public static int min(int i, int j) {
		if (i > j) {
			return j;
		}
		return i;
	}
}

