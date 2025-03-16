import java.io.*;
import java.util.*;

public class Main {

	// Initialize scanner and printer objects
	private static Scanner sc;
	private static Printer pr;

	// Function to solve the problem
	private static void solve() {
		// Read input: number of elements 'n' and limit 'k'
		int n = sc.nextInt();
		int k = sc.nextInt();

		// Initialize an integer array 'a' to store input elements
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			// Read each element of array 'a'
			a[i] = sc.nextInt();
		}

		// Calculate cumulative sum of array 'a' and store it in 'cumsum' array
		long[] cumsum = new long[n + 1];
		for (int i = 0; i < n; i++) {
			cumsum[i + 1] = cumsum[i] + a[i];
		}

		// Initialize an ArrayList 'b' to store differences between cumulative sums
		List<Long> b = new ArrayList<>(n * (n + 1) / 2);
		long max = 0;
		// Calculate differences between cumulative sums and add them to 'b' list
		// Also find the maximum difference
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				b.add(cumsum[j + 1] - cumsum[i]);
				max = Math.max(max, cumsum[j + 1] - cumsum[i]);
			}
		}

		// Filter 'b' list based on the mask
		long mask = Long.highestOneBit(max);
		while (mask > 0) {
			List<Long> tmp = new ArrayList<>();
			// Filter elements in 'b' list based on the current mask
			for (long e : b) {
				if ((e & mask) != 0) {
					tmp.add(e);
				}
			}

			// If the filtered list 'tmp' has size greater than or equal to 'k', update 'b' list
			if (tmp.size() >= k) {
				b = tmp;
			}

			// Update the mask
			mask >>= 1;
		}

		// Check if the size of filtered list 'b' is less than 'k'
		if (b.size() < k) {
			// Print 0 if the condition is true
			pr.println(0);
		} else {
			// Calculate the answer by performing bitwise AND on all elements in 'b' list
			long ans = -1L;
			for (long e : b) {
				ans &= e;
			}

			// Print the answer
			pr.println(ans);
		}
	}

	// Main method to start the program
	public static void main(String[] args) {
		// Initialize scanner and printer objects
		sc = new Scanner(System.in);
		pr = new Printer(System.out);

		// Call the 'solve' function to solve the problem
		solve();

		// Close the scanner and printer objects
		pr.close();
		sc.close();
	}

	// Printer class to handle printing
	static class Printer extends PrintWriter {
		Printer(OutputStream out) {
			super(out);
		}
	}
}
