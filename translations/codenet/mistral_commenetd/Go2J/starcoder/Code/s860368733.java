
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read input from standard input
		Scanner sc = new Scanner(System.in);
		// Initialize variables
		int n = sc.nextInt();
		int m = sc.nextInt();
		// Allocate memory for h array
		int[] h = new int[n];
		// Read h array elements from standard input
		for (int i = 0; i < n; i++) {
			h[i] = sc.nextInt();
			// Comment for the loop that reads h array elements
			// from standard input
			// and stores them in the h array
		}
		// Initialize counter map
		Map<Integer, Integer> counter = new HashMap<Integer, Integer>();
		// Read m query pairs from standard input
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			// Check the condition for a and b
			if (h[a-1] < h[b-1]) {
				// Add a to the counter map if h[a-1] is smaller than h[b-1]
				counter.put(a, 1);
			} else if (h[a-1] > h[b-1]) {
				// Add b to the counter map if h[a-1] is greater than h[b-1]
				counter.put(b, 1);
			} else if (h[a-1] == h[b-1]) {
				// Add both a and b to the counter map if h[a-1] is equal to h[b-1]
				counter.put(a, 1);
				counter.put(b, 1);
			}
			// Comment for the loop that processes m query pairs
		}
		// Print the result
		System.out.println(n - counter.size());
		// Comment for the final print statement
	}
}

