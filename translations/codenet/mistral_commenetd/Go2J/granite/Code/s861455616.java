

import java.util.Scanner; // Import the "Scanner" class from the "java.util" package

public class s861455616{
	public static void main(String[] args) {
		// Create a new instance of the "Scanner" class to read input from the standard input
		Scanner scanner = new Scanner(System.in);

		// Use the "next" method of the "Scanner" class to read a string input
		String s = scanner.next();

		// Check if the length of the string "s" is greater than or equal to 4
		// and if its first four characters are "YAKI"
		if (s.length() >= 4 && s.substring(0, 4).equals("YAKI")) {
			// If the condition is true, print the word "Yes" to the standard output
			System.out.println("Yes");
		} else {
			// If the condition is false, print the word "No" to the standard output
			System.out.println("No");
		}

		// Close the "Scanner" object to release system resources
		scanner.close();
	}
}
