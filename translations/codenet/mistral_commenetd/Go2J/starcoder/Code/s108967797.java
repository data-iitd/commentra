
import java.util.*;
import java.io.*;

public class Main {

	// Function to read an integer from standard input
	public static int ri() {
		try {
			// Read a line of input from stdin
			String s = br.readLine();
			// Return the integer that was read
			return Integer.parseInt(s);
		} catch (IOException e) {
			// Print an error message to stderr
			System.err.println("Error reading input.");
			// Exit with a non-zero exit code
			System.exit(1);
		}
	}

	// Function to calculate the average of a slice of float64 numbers
	public static double ave(double[] s) {
		double sum = 0.0; // Initialize a variable to store the sum of numbers in the slice
		for (double v : s) { // Iterate through each number in the slice
			sum += v; // Add the current number to the sum
		}
		return sum / s.length; // Calculate and return the average
	}

	// Function to calculate the difference between two float64 numbers
	public static double diff(double a, double b) {
		if (a > b) { // Check if the first number is greater than the second number
			return a - b; // If so, return the difference
		}
		return b - a; // If not, return the negative difference
	}

	// Main function
	public static void main(String[] args) {
		// Initialize the scanner to read words instead of lines
		br.split(new String[] {" "});

		// Read the number of elements in the array from standard input
		int n = ri();

		// Allocate memory for an array of float64 numbers with the given size
		double[] a = new double[n];

		// Read each element of the array from standard input and store it in the corresponding index
		for (int i = 0; i < n; i++) {
			a[i] = (double) ri(); // Read an integer from standard input and convert it to a float64 number
		}
		// Print the array for debugging purposes (uncomment this line if needed)
		// System.out.println(Arrays.toString(a));

		// Calculate the average of the array elements
		double ave = ave(a);

		// Initialize variables to store the minimum difference and the index of the element with the minimum difference
		double minDiff = 999999.9;
		int ansIndex = -1;

		// Iterate through each element of the array and find the one with the minimum difference from the average
		for (int i = 0; i < n; i++) {
			double diff = diff(a[i], ave); // Calculate the difference between the current element and the average
			if (diff < minDiff) { // Check if the difference is smaller than the current minimum difference
				minDiff = diff; // If so, update the minimum difference
				ansIndex = i; // and the index of the answer
			}
		}

		// Print the index of the element with the minimum difference from the average
		System.out.println(ansIndex);

	}

}

