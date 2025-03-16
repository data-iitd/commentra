
import java.util.*; // Import the Scanner class for reading input from the standard input.

public class s422352362{ // Define the main class.
	public static void main(String[] args) { // Define the main method where the execution of the program begins.
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
		int n = sc.nextInt(); // Read the value of n from the standard input.
		long[] a = new long[n + 1]; // Declare an array to store the input values.
		long[] pre = new long[n + 1]; // Declare an array to store the prefix sums.
		long[] last = new long[n + 1]; // Declare an array to store the suffix sums.
		for (int i = 1; i <= n; i++) { // Loop to read n integers into the array a.
			a[i] = sc.nextLong(); // Read the i-th integer and store it in a[i].
		}
		long sumpre = 0, sumlast = 0; // Declare variables to store the cumulative sums of prefix and suffix.
		for (int i = 1; i < n; i++) { // Loop to calculate the prefix sums.
			sumpre = sumpre + a[i]; // Add the current element to the cumulative sum.
			pre[i] = sumpre; // Store the cumulative sum in the pre array.
//			System.out.println(pre[i] + "++"); // Uncommented code to print the prefix sums (for debugging purposes).
		}
		for (int i = n; i > 1; i--) { // Loop to calculate the suffix sums.
			sumlast = sumlast + a[i]; // Add the current element to the cumulative sum.
			last[i] = sumlast; // Store the cumulative sum in the last array.
//			System.out.println(last[i] + "+++"); // Uncommented code to print the suffix sums (for debugging purposes).
		}
		long d = (long) Math.pow(10, 18); // Declare a variable to store the minimum difference and initialize it to a large number.
		for (int i = 1; i < n; i++) { // Loop to find the minimum absolute difference between prefix and suffix sums.
//			System.out.println(pre[i] - last[i + 1]); // Uncommented code to print the difference between prefix and suffix sums (for debugging purposes).
			d = Math.min(d, Math.abs(pre[i] - last[i + 1])); // Update the minimum difference if a smaller one is found.
		}
		System.out.println(d); // Print the minimum difference found.
	}
}
