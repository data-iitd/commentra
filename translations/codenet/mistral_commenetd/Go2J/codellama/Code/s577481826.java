// Importing required packages
import java.util.Scanner;

// Creating a scanner for reading input from stdin
Scanner sc = new Scanner(System.in);

// Function to read a single line from stdin
String read() {
	return sc.next(); // Return the text of the scanned token
}

// Main function
public static void main(String[] args) {
	// Reading the first integer 'a' from stdin
	int a = Integer.parseInt(read()); // Converting the read string to integer 'a'

	// Reading the second integer 'b' from stdin
	int b = Integer.parseInt(read()); // Converting the read string to integer 'b'

	// Calculating the sum of 'a' and 'b'
	int ret = a + b;

	// Checking if the sum is less than the difference of 'a' and 'b'
	if (ret < (a - b)) {
		// If true, then update the value of 'ret'
		ret = a - b;
	}

	// Checking if the sum is less than the product of 'a' and 'b'
	if (ret < (a * b)) {
		// If true, then update the value of 'ret'
		ret = a * b;
	}

	// Printing the final value of 'ret'
	System.out.println(ret);

	// End of the code
}


Translate the above Java code to C++ and end with comment "