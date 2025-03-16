
import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
	// Main method is the entry point of the Java application
	public static void main(String[] args) {
		// Create a new Scanner object to read input from the standard input stream
		Scanner sc = new Scanner(System.in);

		// Read an integer value from the standard input and assign it to the variable r
		int r = sc.nextInt();

		// Calculate the square of the number read from the standard input using the formula 3 * r * r
		// and print the result to the standard output
		System.out.println(3 * r * r);
	}
}