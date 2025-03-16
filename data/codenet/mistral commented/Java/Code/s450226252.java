
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		// Create a new instance of the Scanner class to read input from the standard input stream
		Scanner stdIn = new Scanner(System.in);

		// Read a short integer value from the standard input and assign it to the variable r
		short r = stdIn.nextShort();

		// Check if the value of r is less than 1200
		if (r < 1200) {
			// If it is, print the string "ABC" to the standard output and return from the main method
			System.out.println("ABC");
			return;
		}

		// Check if the value of r is less than 2800
		if (r < 2800) {
			// If it is, print the string "ARC" to the standard output and return from the main method
			System.out.println("ARC");
			return;
		}

		// If neither of the previous conditions are met, print the string "AGC" to the standard output
		System.out.println("AGC");
	}

}