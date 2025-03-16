
// Package declaration for the main Java program
package main;

// Import the java.util package for utility classes and functions
import java.util.*;

// Create a class named 's030204253'
public class s030204253{
	// s030204253 method to execute the program
	public static void main(String[] args) {
		// Initialize an integer variable 'n' and read its value from the standard input
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();

		// Create an array 'a' of 'n' double elements
		double[] a = new double[n];

		// Read 'n' double values from the standard input and assign them to the array 'a'
		for (int i = 0; i < n; i++) {
			a[i] = scanner.nextDouble();
		}

		// Iterate through the array 'a' 'n-1' times and sort it using the 'Arrays.sort' function
		for (int i = 0; i < n - 1; i++) {
			Arrays.sort(a);
		}

		// Initialize an empty list 'na' of double
		List<Double> na = new ArrayList<>();

		// Iterate through the array 'a' starting from index 2 and add its elements to the list 'na'
		for (int j = 2; j < a.length; j++) {
			na.add(a[j]);
		}

		// Reassign the value of the array 'a' with the list 'na' and the first two elements being the average of the first two elements of the original array 'a'
		na.add((a[0] + a[1]) / 2);
		a = na.stream().mapToDouble(Double::doubleValue).toArray();

		// Print the first element of the sorted array 'a' to the standard output
		System.out.println(a[0]);
	}
}

