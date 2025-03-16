
// Package declaration, this file is the entry point of the program
package main;

// Import statements, importing the java.util.Scanner and java.io.PrintWriter packages
import java.util.Scanner;
import java.io.PrintWriter;

// Entry point of the program
public class s494300734{
	// s494300734 method of the program
	public static void main(String[] args) {
		// Create a new instance of the Scanner class to read input from the standard input
		Scanner scanner = new Scanner(System.in);

		// Create a new instance of the PrintWriter class to write output to the standard output
		PrintWriter out = new PrintWriter(System.out);

		// Initialize a variable s of type String and read a string input from the standard input
		String s = scanner.next();

		// Initialize a variable ans with the string value "No"
		String ans = "No";

		// Check if the index of the substring "C" in the string s is less than the index of the substring "F"
		if (s.indexOf("C") < s.lastIndexOf("F")) {
			// If it is, then change the value of ans to "Yes"
			ans = "Yes";
		}

		// Check if the index of the substring "C" in the string s is less than 0
		if (s.indexOf("C") < 0) {
			// If it is, then do not change the value of ans
		}

		// Print the value of ans to the standard output
		out.println(ans);

		// Close the PrintWriter object to flush the output
		out.close();
	}
}

// End of the code