
// Importing necessary packages
import java.util.*;

// s525290130 class
public class s525290130{
	// Function to read next integer from the standard input
	public static int nextInt(Scanner sc) {
		return sc.nextInt();
	}

	// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
	public static void reva(int[] a, int b, int e) {
		// Reverse the subarray using a simple method of swapping elements
		for (int i = 0; i < (e - b + 1) / 2; i++) {
			int temp = a[b + i];
			a[b + i] = a[e - i];
			a[e - i] = temp;
		}
	}

	// s525290130 function
	public static void main(String[] args) {
		// Initialize a scanner to read input from standard input
		Scanner sc = new Scanner(System.in);

		// Read the number of elements in the array 'a'
		int n = nextInt(sc);
		// Allocate memory for the array 'a' of size 'n'
		int[] a = new int[n];

		// Read 'n' integers from the standard input and store them in the array 'a'
		for (int i = 0; i < n; i++) {
			a[i] = nextInt(sc);
		}

		// Read the number of queries 'q'
		int q = nextInt(sc);

		// Process each query by reversing the subarray of 'a'
		for (int i = 0; i < q; i++) {
			// Read the starting and ending indices of the subarray to be reversed
			int b = nextInt(sc);
			int e = nextInt(sc);

			// Reverse the subarray 'a[b:e]'
			reva(a, b, e);
		}

		// Write the reversed array 'a' to the standard output
		for (int i = 0; i < n; i++) {
			// Write each element of the array 'a' to the standard output with a space in between (except for the first element)
			if (i > 0) {
				System.out.print(" ");
			}
			System.out.print(a[i]);
		}

		// End of the code
	}
}

