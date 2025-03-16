import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		// Read the number of elements
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		// Initialize a slice to hold the input integers
		int[] a = new int[n];
		// Read n integers from input
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		// Create a prefix sum array to store cumulative sums
		int[] s = new int[n+1];
		for (int i = 0; i < n; i++) {
			s[i+1] = s[i] + a[i]; // Calculate cumulative sum
		}

		// Sort the prefix sum array
		Arrays.sort(s);

		// Initialize variables to count pairs of equal sums
		int ans = 0;
		int count = 0;
		// Iterate through the sorted prefix sums to find duplicates
		for (int i = 0; i < n; i++) {
			if (s[i] == s[i+1]) {
				count++; // Increment count if current and next sums are equal
			} else if (count > 0) {
				// If we found duplicates, calculate combinations and reset count
				ans += combi(count+1, 2);
				count = 0; // Reset count for the next unique sum
			}
		}
		// Handle the case where the last sums were duplicates
		if (count > 0) {
			ans += combi(count+1, 2);
		}

		// Output the total number of pairs of equal sums
		System.out.println(ans);
	}

	// Function to calculate combinations C(n, r)
	public static int combi(int n, int r) {
		int c = 1;
		// Calculate the combination using the formula C(n, r) = n! / (r! * (n - r)!)
		for (int i = 1; i <= r; i++) {
			c = c * (n - i + 1) / i;
		}
		return c; // Return the calculated combination
	}
}

