
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Initialize a Scanner object to read input from the user
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);

		// Read three integers from the user: A, B, and T
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int T = scanner.nextInt();

		// Calculate the value (T / A) * B
		int result = (T / A) * B;

		// Log the result to the console
		log(result);
	}

	// Private method to log a String to the console
	private static void log(String str) {
		System.out.println(str);
	}

	// Private method to log an integer to the console
	private static void log(int str) {
		System.out.println(str);
	}
}

