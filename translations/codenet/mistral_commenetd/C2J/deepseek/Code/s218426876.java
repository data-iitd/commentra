import java.util.Scanner; // Import Scanner class for reading input from standard input stream

public class SumOfDigits { // Define public class SumOfDigits

	public static void main(String[] args) { // Define main method
		Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
		int sum = 0; // Initialize integer variable 'sum' to zero

		while (true) { // Begin a while loop that runs indefinitely
			System.out.println("Enter a string of digits separated by spaces or newline:"); // Prompt user for input
			String input = scanner.nextLine(); // Read the entire line of input

			for (int i = 0; i < input.length(); i++) { // Process each character in the input string
				char c = input.charAt(i); // Get the character at position 'i'
				if (c == '0' && i == 0 && input.trim().isEmpty()) { // Check if the first character is '0' and the string is empty after trimming
					break; // Exit the loop if the input is just '0'
				}
				if (Character.isDigit(c)) { // Check if the character is a digit
					sum += Character.getNumericValue(c); // Add the numeric value of the digit to the sum
				}
			}

			System.out.println("Sum of digits in previous string: " + sum); // Print the sum of digits in the previous string
			sum = 0; // Reset the sum for the next iteration
		}
	}
}
