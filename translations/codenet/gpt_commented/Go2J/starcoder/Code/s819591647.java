// problem_b.java

import java.io.*;
import java.util.*;

public class problem_b {

	// Define a constant for modulus operation
	public static final int constMod = (int)(1e9) + 7;

	// Main method
	public static void main(String[] args) throws Exception {
		// Read input from stdin
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// Read n and m from input
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		// Read n integers into slice a
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(br.readLine());
		}
		// Calculate the sum of all elements in a
		int sum = 0;
		for (int v : a) {
			sum += v;
		}
		// Count how many elements in a meet the required rate
		int count = 0;
		for (int v : a) {
			double rate = (double)sum / (4.0 * m);
			if (v >= rate) {
				count++;
			}
		}
		// Output "Yes" if count is greater than or equal to m, otherwise "No"
		if (count >= m) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}

