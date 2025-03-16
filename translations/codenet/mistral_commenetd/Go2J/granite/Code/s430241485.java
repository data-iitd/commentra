
import java.util.Scanner; // Import the "Scanner" class from the "java.util" package for input handling

public class s430241485{ // Define the main class, entry point of our program
	public static void main(String[] args) { // Define the main method, entry point of our program
		// Create a new instance of the "Scanner" class to read input from the standard input (keyboard)
		Scanner scanner = new Scanner(System.in);

		// Declare two variables, s and t, both of type String
		String s = scanner.nextLine(); // Read the first input line and store it in variable s
		String t = scanner.nextLine(); // Read the second input line and store it in variable t

		// Print the concatenated string of t and s using the "System.out.println" method
		System.out.println(t + s); // Print the concatenated string of t and s
	}
}
