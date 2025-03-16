// Package declaration
package main;

// Importing the 'Scanner' class for input/output operations
import java.util.Scanner;

// Function declaration for finding the minimum number among given integers
public static int min(int... nums) {
	// Initializing the minimum value with the first integer
	int min = nums[0];

	// Iterating through the array 'nums' to find the minimum value
	for (int v : nums) {
		// If the current value is less than the minimum value, update the minimum value
		if (v < min) {
			min = v;
		}
	}

	// Returning the minimum value
	return min;
}

// Main function declaration
public static void main(String[] args) {
	// Declaring three integer variables for reading input values
	int n, a, b;

	// Reading input values from the standard input using 'Scanner' class
	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	a = sc.nextInt();
	b = sc.nextInt();

	// Printing the minimum value between 'n*a' and 'b' using 'System.out.println' function
	System.out.println(min(n*a, b));
}

// End of the code
