// Package declaration for the main Java program
package main;

// Import the java.util.Scanner class for reading from the standard input
import java.util.Scanner;

// Import the java.util.Arrays class for sorting the array
import java.util.Arrays;

// Import the java.util.ArrayList class for creating the array
import java.util.ArrayList;

// Main class
public class Main {
	// Main method
	public static void main(String[] args) {
		// Initialize an integer variable 'n' and read its value from the standard input
		int n = new Scanner(System.in).nextInt();

		// Create an array 'a' of 'n' float64 elements
		double[] a = new double[n];

		// Read 'n' float64 values from the standard input and assign them to the array 'a'
		for (int i = 0; i < n; i++) {
			a[i] = new Scanner(System.in).nextDouble();
		}

		// Iterate through the array 'a' 'n-1' times and sort it using the 'Arrays.sort' function
		for (int i = 0; i+1 < n; i++) {
			Arrays.sort(a);
		}

		// Initialize an empty array list 'na' of float64
		ArrayList<Double> na = new ArrayList<Double>();

		// Iterate through the array 'a' starting from index 2 and append its elements to the array list 'na'
		for (int j = 2; j < a.length; j++) {
			na.add(a[j]);
		}

		// Reassign the value of the array 'a' with the array list 'na' and the first two elements being the average of the first two elements of the original array 'a'
		na.add((a[0]+a[1])/2);
		a = new double[na.size()];
		for (int i = 0; i < na.size(); i++) {
			a[i] = na.get(i);
		}

		// Print the first element of the sorted array 'a' to the standard output
		System.out.println(a[0]);
	}
}

