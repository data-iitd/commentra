import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Read the number of elements from standard input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		// Initialize a slice to hold the input integers
		int[] a = new int[n];
		// Read n integers from standard input into the slice a
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		// Initialize a slice b to hold the longest increasing subsequence
		int[] b = new int[n];
		// Iterate over each value in the input slice a
		for (int v : a) {
			// Use binary search to find the index where v can be placed in b
			int x = Arrays.binarySearch(b, 0, b.length, v);
			// If v is greater than all elements in b, append it to b
			if (x < 0) {
				x = -(x + 1);
			}
			// Otherwise, replace the existing value at index x with v
			b[x] = v;
		}

		// Output the length of the longest increasing subsequence
		System.out.println(b.length);
	}
}
