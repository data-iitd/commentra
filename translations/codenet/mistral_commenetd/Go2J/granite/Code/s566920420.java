

import java.util.Scanner; // Import the "Scanner" class from the "java.util" package for reading input from the standard input

public class s566920420{
	public static void main(String[] args) {
		// Create a new instance of the "Scanner" class to read input from the standard input
		Scanner scanner = new Scanner(System.in);

		// Read a value of type int from the standard input and store it in the variable "a"
		int a = scanner.nextInt();

		// Calculate the result of the expression "a + a*a + a*a*a"
		int result = a + a*a + a*a*a;

		// Print the result to the standard output
		System.out.println(result);

		// End of code
		scanner.close();
	}
}

