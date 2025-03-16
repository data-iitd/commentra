
//--- pB ---//
// Import necessary packages
import java.util.*;
import java.lang.*;
import java.io.*;

// Define the main class
public class Main {
	// Initialize an instance of Solution class when program starts
	public static void main (String[] args) throws java.lang.Exception {
		new Solution();
	}
}

// Define the Solution class
class Solution {
	// Initialize a Scanner object for reading input
	Scanner scanner;

	// Constructor for Solution class
	public Solution() {
		scanner = new Scanner(System.in);

		// Read input lines until there is no more input
		while (scanner.hasNext()) {
			run_case();
		}
	}

	// Method to run a single case
	private void run_case() {
		// Read the first line of input
		String line = scanner.nextLine();

		// Parse the first line of input to get N and K
		int N = Integer.parseInt(line.split("\\s+")[0]);
		int K = Integer.parseInt(line.split("\\s+")[1]);

		// Calculate the length of the longest sequence of K that can be formed from N
		int len = 0;
		while (N > 0) {
			N /= K;
			len ++;
		}

		// Print the result
		System.out.println(len);
	}

	// Helper method to convert a string to an integer array
	private int[] strToIntArray(String str) {
		// Split the string by whitespace and convert each part to an integer
		String[] vals = str.split("\\s+");
		int sz = vals.length;
		int[] res = new int[sz];
		for (int i=0; i<sz; i++) {
			res[i] = Integer.parseInt(vals[i]);
		}
		return res;
	}
}

// Define a separate class LCS for Longest Common Subsequence problem
class LCS {
	// Initialize a 2D array dp for storing lengths of LCS of substrings
	int[][] dp;

	// Method to find the length of LCS of two strings A and B
	public int lcs(String A, String B) {
		// Get the lengths of strings A and B
		int sz_a = A.length(), sz_b = B.length();

		// Initialize dp array with zeros
		dp = new int[sz_a+1][sz_b+1];

		// Base cases: empty strings have no LCS
		for (int i=0; i<=sz_a; i++) dp[i][0] = 0;
		for (int j=0; j<=sz_b; j++) dp[0][j] = 0;

		// Fill dp array by comparing characters of A and B
		for (int i=1; i<=sz_a; i++) {
			for (int j=1; j<=sz_b; j++) {
				// If characters are same, add 1 to previous LCS length
				if (A.charAt(i-1) == B.charAt(j-1)) {
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				// If characters are not same, take maximum of previous LCS lengths
				else {
					dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}

		// Return the length of LCS
		return dp[sz_a][sz_b];
	}

	// Method to find the actual LCS string
	public String getLCS(String X, String Y) {
		// Get the lengths of strings X and Y
		int m = X.length(), n = Y.length();

		// Initialize dp array and LCS string
		int[][] dp = new int[m+1][n+1];
		char[] lcs = new char[m+1];

		// Fill dp array and extract LCS string
		int index = dp[m][n];
		int temp = index;
		int i = m, j = n;
		while (i > 0 && j > 0) {
			// If characters are same, add to LCS string and move diagonally
			if (X.charAt(i-1) == Y.charAt(j-1)) {
				lcs[index-1] = X.charAt(i-1);
				i--;
				j--;
				index--;
			}
			// If characters are not same, move to the direction with maximum previous LCS length
			else if (dp[i-1][j] > dp[i][j-1]) i--;
			else j--;
		}

		// Return the LCS string
		return new String(lcs, 0, temp+1);
	}
}