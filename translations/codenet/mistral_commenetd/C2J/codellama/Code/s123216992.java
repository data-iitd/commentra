
import java.util.Scanner;
// Import the Scanner class to read input from the user

public class Main {
	// Declare a class named 'Main'

	public static void swap(int a , int b) {
		// Declare a static function named 'swap' to swap two integers

		int tmp;
		// Declare a temporary variable to store the value of 'a'

		tmp = a;
		// Assign the value of 'b' to 'a'

		a = b;
		// Assign the value of 'a' to 'b'

		b = tmp;
		// Assign the value of the temporary variable 'tmp' back to 'b'
	}

	public static void main(String[] args) {
		// Declare a function named 'main' to read two integers from the user

		Scanner sc = new Scanner(System.in);
		// Declare a Scanner object to read input from the user

		int a , b;
		// Declare two integer variables 'a' and 'b'

		while(true) {
			// Infinite loop to read two integers from the user

			a = sc.nextInt();
			// Read an integer from the user and store it in 'a'

			b = sc.nextInt();
			// Read an integer from the user and store it in 'b'

			if (a == 0 && b == 0) break;
			// If both 'a' and 'b' are zero, break out of the loop

			if (b < a) swap(a , b);
			// If 'b' is less than 'a', swap their values

			System.out.println(a + " " + b);
			// Print the swapped values of 'a' and 'b'
		}
		// Return 0 to indicate successful execution of the program

		sc.close();
		// Close the Scanner object
	}
}

