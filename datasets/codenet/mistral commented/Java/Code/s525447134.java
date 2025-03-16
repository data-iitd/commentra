
import java.util.Scanner; // Import the Scanner class for user input

public class Main {

	public static void main(String[] args) {
		// Create a new Scanner object to read from the standard input stream
		Scanner sc = new Scanner(System.in);

		// Read a string from the user input using the next() method
		String s = sc.next();

		// Check if the string s is equal to the string "Sunny"
		if(s.equals("Sunny")) {
			// If the condition is true, print the string "Cloudy" to the console
			System.out.println("Cloudy");
		} else if(s.equals("Cloudy")) { // Check if the string s is equal to the string "Cloudy"
			// If the condition is true, print the string "Rainy" to the console
			System.out.println("Rainy");
		} else { // If none of the conditions are true, print the string "Sunny" to the console
			// Print the string "Sunny" to the console
			System.out.println("Sunny");
		}
	}

}