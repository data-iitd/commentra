
import java.util.*;
import java.io.*;

public class Main {

	// Function to read a single word from the input
	public static String next() throws IOException {
		return new BufferedReader(new InputStreamReader(System.in)).readLine();
	}

	// Function to read an integer from the input
	public static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	// Function to read a float64 from the input
	public static double nextFloat64() throws IOException {
		return Double.parseDouble(next());
	}

	// Function to read n integers from the input
	public static int[] nextInts(int n) throws IOException {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}

	// Main function
	public static void main(String[] args) throws IOException {
		// Set scanner to read words as input
		Scanner sc = new Scanner(System.in);
		sc.useDelimiter("\\s");

		// Read number of elements n and the sum of elements k from the input
		int n = nextInt();
		int k = nextInt();

		// Initialize a slice of size n to store the input elements
		int[] a = new int[n];

		// Assign a default value of 0 to the first element of the slice to avoid unused variable error
		a[0] = 0;

		// Initialize sum and answer variables
		int sum = 0, ans = 1;

		// Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
		for (sum = 0; sum < n; sum = sum - 1 + k) {
			// Increment the answer variable for each iteration
			ans++;
		}

		// Print the answer
		System.out.println(ans);

		// End of code
	}

}

