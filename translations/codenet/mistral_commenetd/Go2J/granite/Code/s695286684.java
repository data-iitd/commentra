
// 2018-07-29T20:36:21+0800
import java.util.Scanner; // Import the Scanner class for input reading.

public class s695286684{ // Define a class named "s695286684" to contain the main method.

	public static void main(String[] args) { // Define the main method.
		Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
		String s = scanner.nextLine(); // Read a string input from the standard input and store it in the variable `s`.

		// Replace all occurrences of the string "2017" in the string `s` with the string "2018".
		s = s.replaceAll("2017", "2018");

		// Print the modified string to the standard output.
		System.out.println("Modified string: " + s);

		scanner.close(); // Close the Scanner object to release system resources.
	}
}

// End of code.
