
import java.util.Scanner; // Import the Scanner class for input/output operations

public class Main { // Begin the Main class
	public static void main(String[] args) { // Begin the main function
		Scanner sc = new Scanner(System.in); // Create a new Scanner object for input/output operations
		int a = sc.nextInt(); // Read the value of a from the standard input using sc.nextInt()
		int b = sc.nextInt(); // Read the value of b from the standard input using sc.nextInt()

		// Check if both a and b are less than or equal to 8
		if (a <= 8 && b <= 8) {
			System.out.println("Yay!"); // If the condition is true, print "Yay!" to the standard output using System.out.println()
		}
		else {
			System.out.println(":("); // If the condition is false, print ":(" to the standard output using System.out.println()
		}

		// End the main function and return 0 to the operating system
		return 0;
	}
}

