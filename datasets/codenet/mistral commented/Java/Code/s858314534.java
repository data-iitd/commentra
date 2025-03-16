import java.util.Scanner; // Importing Scanner class for user input

public class Main {
	public static void main(String[] args) {
		// Creating a Scanner object for reading user input from the console
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);

		// Reading the first integer value (A) from the user input
		int A = scanner.nextInt();

		// Reading the second integer value (B) from the user input
		int B = scanner.nextInt();

		// Reading the third integer value (T) from the user input
		int T = scanner.nextInt();

		// Calculate the result and pass it to the log method with a string representation
		log((T / A) * B);

		// Closing the scanner to free system resources
		scanner.close();
	}

	// Logging method that takes a string argument and prints it to the console
	private static void log(String str) {
		System.out.println(str);
	}

	// Logging method that takes an integer argument and prints it to the console
	private static void log(int str) {
		System.out.println(str);
	}
}