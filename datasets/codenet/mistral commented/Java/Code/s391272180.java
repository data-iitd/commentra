
import java.util.Scanner; // Importing Scanner class for user input
public class Main {
	public static void main(String[] args) {
		// Creating Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);

		StringBuilder s, t; // Declaring two StringBuilder objects

		s = new StringBuilder(sc.next()); // Reading the first string from user and initializing StringBuilder 's'
		t = new StringBuilder(sc.next()); // Reading the second string from user and initializing StringBuilder 't'

		boolean flag = false; // Initializing flag variable to false

		// Iterating through each character in StringBuilder 's'
		for (int i = 0; i < s.length(); i++) {
			// Rotating StringBuilder 's' by one character
			s = new StringBuilder(Rotate(s));

			// Checking if the rotated StringBuilder 's' is equal to StringBuilder 't'
			if (t.toString().equals(s.toString())) {
				flag = true; // Setting flag to true if they are equal
				break; // Exiting the loop if they are equal
			}
		}

		// Printing the output based on the flag value
		if (flag == true)
			System.out.println("Yes");
		else
			System.out.println("No");
	}

	// Function to rotate StringBuilder by one character
	public static StringBuilder Rotate(StringBuilder str) {
		int len = str.length(); // Getting the length of StringBuilder
		char temp = str.charAt(0); // Storing the first character of StringBuilder in a temporary variable

		// Rotating StringBuilder by one character
		for (int i = 0; i < len - 1; i++) {
			str.setCharAt(i, str.charAt(i + 1)); // Swapping each character with the next one
		}

		// Setting the last character of StringBuilder to the first character
		str.setCharAt(len - 1, temp);

		// Returning the rotated StringBuilder
		return str;
	}
}