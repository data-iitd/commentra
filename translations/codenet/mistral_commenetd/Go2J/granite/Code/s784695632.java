

import java.util.Scanner; // Import the "Scanner" class from the "java.util" package for reading input from the standard input.

public class s784695632{
	public static void main(String[] args) {
		// Define the method "main" as the entry point of our program.
		Scanner scanner = new Scanner(System.in); // Create a new instance of the "Scanner" class to read input from the standard input.
		int x = scanner.nextInt(); // Read the value of variable "x" from the standard input.
		int y = scanner.nextInt(); // Read the value of variable "y" from the standard input.
		scanner.close(); // Close the "Scanner" instance to release system resources.

		// Print the result of the expression "x + y/2" to the standard output.
		System.out.println(x + y/2);

		// End of code.
	}
}

