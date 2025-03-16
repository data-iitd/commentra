
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a new scanner for reading input from stdin
		Scanner sc = new Scanner(System.in);
		// Read the number of elements n and the number of queries m from standard input
		int n = sc.nextInt();
		int m = sc.nextInt();
		// Allocate an array a of size n
		int[] a = new int[n];
		// Initialize a variable sum to keep track of the sum of elements in the array
		int sum = 0;
		// Process each query
		for (int i = 0; i < m; i++) {
			// Read an integer from standard input and add it to the array a
			a[i] = sc.nextInt();
			// Add the current element to the sum
			sum += a[i];
			// Check if the sum is greater than the size of the array
			if (sum > n) {
				// If so, print -1 and exit the program
				System.out.println("-1");
				return;
			}
		}
		// Print the result, which is the difference between the size of the array and the sum of its elements
		System.out.println(n - sum);
	}

}

