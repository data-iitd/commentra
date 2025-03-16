// Importing required packages
import java.util.*;
import java.io.*;

// Creating a buffer scanner for reading input from stdin
Scanner sc = new Scanner(System.in);

// Main function
public class Main {

	// Function to read a single line from stdin
	public static String read() {
		return sc.next();
	}

	// Main function
	public static void main(String[] args) {
		// Reading the first integer 'a' from stdin
		int a = Integer.parseInt(read());

		// Reading the second integer 'b' from stdin
		int b = Integer.parseInt(read());

		// Calculating the sum of 'a' and 'b'
		int ret = a + b;

		// Checking if the sum is less than the difference of 'a' and 'b'
		if (ret < (a - b)) {
			// If true, then update the value of'ret'
			ret = a - b;
		}

		// Checking if the sum is less than the product of 'a' and 'b'
		if (ret < (a * b)) {
			// If true, then update the value of'ret'
			ret = a * b;
		}

		// Printing the final value of'ret'
		System.out.println(ret);
	}
}

