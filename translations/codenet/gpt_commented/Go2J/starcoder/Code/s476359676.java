import java.util.*;

public class Main {
	public static void main(String[] args) {
		// Initialize the scanner to read from standard input
		Scanner sc = new Scanner(System.in);
		// Set the buffer size for the scanner
		sc.useDelimiter("\\s");

		// Read the number of integers to process
		int n = sc.nextInt();

		// Initialize variables for the answer and the previous integer
		int ans = 0;
		int aPrev = 0;

		// Loop through each integer input
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt(); // Read the next integer

			// Check conditions based on the current and previous integers
			if (a > i || a > aPrev + 1) { // If the current integer is greater than the index or previous integer + 1
				System.out.println(-1); // Print -1 and exit if the condition is met
				return;
			} else if (a == aPrev + 1) { // If the current integer is exactly one more than the previous integer
				ans++; // Increment the answer
			} else { // For all other cases
				ans += a; // Add the current integer to the answer
			}
			aPrev = a; // Update the previous integer to the current one
		}

		// Print the final answer
		System.out.println(ans);
	}
}

