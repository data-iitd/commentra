import java.util.Scanner; // Import Scanner class for reading input

public class Main {
	public static void main(String[] args) {
		// Define the entry point of the program
		Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input
		int n; // Define an integer variable to store the number of intervals
		int[] l; // Define an integer array `l` of size `n` to store the left endpoints of the intervals
		int[] r; // Define an integer array `r` of size `n` to store the right endpoints of the intervals
		int sum = 0; // Define an integer variable `sum` to store the sum of the lengths of the intervals

		// Read the number of intervals from the standard input stream
		n = sc.nextInt();

		// Allocate memory for the arrays `l` and `r`
		l = new int[n];
		r = new int[n];

		// Read the left and right endpoints of each interval from the standard input stream
		for (int i = 0; i < n; i++) {
			l[i] = sc.nextInt(); // Read the left endpoint of the `i`-th interval
			r[i] = sc.nextInt(); // Read the right endpoint of the `i`-th interval
		}

		// Calculate the sum of the lengths of all intervals
		for (int i = 0; i < n; i++) {
			sum += r[i] - l[i] + 1; // Add the number of elements in the `i`-th interval to the sum
		}

		// Print the sum of the lengths of all intervals to the standard output stream
		System.out.println(sum);

		// Close the Scanner object to free up system resources
		sc.close();
	}
}
