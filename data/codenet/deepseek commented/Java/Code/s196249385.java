import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		// Read the number of elements (n) and the number of largest sums to consider (k)
		int n = sc.nextInt();
		int k = sc.nextInt();

		// Initialize an array to store the input values
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		
		// Calculate the cumulative sum of the array a
		long[] cumsum = new long[n + 1];
		for (int i = 0; i < n; i++) {
			cumsum[i + 1] = cumsum[i] + a[i];
		}

		// Generate all possible subarray sums and store them in a list b
		List<Long> b = new ArrayList<>(n * (n + 1) / 2);
		long max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				b.add(cumsum[j + 1] - cumsum[i]);
				max = Math.max(max, cumsum[j + 1] - cumsum[i]);
			}
		}

		// Find the maximum subarray sum from the list b
		long mask = Long.highestOneBit(max);
		while (mask > 0) {
			List<Long> tmp = new ArrayList<>();
			for (long e : b) {
				if ((e & mask) != 0) {
					tmp.add(e);
				}
			}
			
			// Filter the list b to keep only the largest k subarray sums
			if (tmp.size() >= k) {
				b = tmp;
			}
			
			mask >>= 1;
		}
		
		// Check if the filtered list b has fewer than k elements
		if (b.size() < k) {
			pr.println(0);
		} else {
			// Find the minimum AND value of the k largest subarray sums
			long ans = -1L;
			for (long e : b) {
				ans &= e;
			}
			
			pr.println(ans);
		}
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);
			
		solve();
			
		pr.close();
		sc.close();
	}

	static class Printer extends PrintWriter {
		Printer(OutputStream out) {
			super(out);
		}
	}
}
