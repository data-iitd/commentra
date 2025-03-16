
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		// Read the number of elements in the array 'a'
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		// Create a slice 'a' of length 'n' to store the input elements
		int[] a = new int[n];

		// Read 'n' elements from the standard input and store them in slice 'a'
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		// Initialize an empty slice 'b' to store the unique elements
		int[] b = new int[0];

		// Iterate through each element 'v' in slice 'a'
		for (int v : a) {
			// Use 'Arrays.binarySearch' function to find the index 'x' where 'v' should be inserted in slice 'b'
			int x = Arrays.binarySearch(b, v);

			// If 'x' is equal to the length of slice 'b', it means 'v' is not present in the slice, so append it
			if (x < 0) {
				b = Arrays.copyOf(b, b.length + 1);
				b[b.length - 1] = v;
			} else {
				// Otherwise, replace the element at index 'x' in slice 'b' with 'v'
				b[x] = v;
			}
		}

		// Print the length of slice 'b' as the output
		System.out.println(b.length);

		// End of the code
	}

}

