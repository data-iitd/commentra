import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare variables for the number of elements (n) and the number of comparisons (m)
		int n, m;
		
		// Read the values of n and m from standard input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		// Create a slice to hold the heights of n elements
		int[] h = new int[n];
		
		// Read the heights of the n elements from standard input
		for (int i = 0; i < n; i++) {
			h[i] = sc.nextInt();
		}
		
		// Declare variables for the two elements to compare (a and b)
		int a, b;
		
		// Create a map to keep track of unique elements that are involved in comparisons
		Map<Integer, Integer> counter = new HashMap<Integer, Integer>();
		
		// Loop through m comparisons
		for (int i = 0; i < m; i++) {
			// Read the indices of the two elements to compare
			a = sc.nextInt();
			b = sc.nextInt();
			
			// Compare the heights of the two elements
			if (h[a-1] < h[b-1]) {
				// If height of a is less than height of b, add a to the counter
				counter.put(a, 1);
			} else if (h[a-1] > h[b-1]) {
				// If height of a is greater than height of b, add b to the counter
				counter.put(b, 1);
			} else if (h[a-1] == h[b-1]) {
				// If heights are equal, add both a and b to the counter
				counter.put(a, 1);
				counter.put(b, 1);
			}
		}
		
		// Print the number of elements that were not involved in any comparisons
		System.out.println(n - counter.size());
	}
}

