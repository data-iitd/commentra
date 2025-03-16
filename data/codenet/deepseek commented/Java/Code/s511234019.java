/* package whatever; // don't place package name! */

import java.util.*; // Importing necessary utilities for input/output operations
import java.lang.*; // Importing java.lang package for basic Java classes
import java.io.*; // Importing java.io package for input/output classes

/* Name of the class has to be "Main" only if the class is public. */
public class Main { // Defining the Main class which is the entry point of the Java application
	public static void main (String[] args) throws java.lang.Exception { // Main method is the entry point of the program
		Scanner in = new Scanner(System.in); // Creating a Scanner object to read input from the standard input stream
		int a, b; // Declaring two integer variables
		a = in.nextInt(); // Reading the value of a from the standard input
		b = in.nextInt(); // Reading the value of b from the standard input
		if (a % 2 == 0 || b % 2 == 0) // Checking if either a or b is even
			System.out.println("No"); // Printing "No" if either a or b is even
		else // If neither a nor b is even
			System.out.println("Yes"); // Printing "Yes" if both a and b are odd
	}
}
