
import java.util.*; // Import the Scanner and other utility classes
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a Scanner object for reading the standard input
		int a = sc.nextInt(); // Read the value of a from the standard input using the Scanner object
		int b = sc.nextInt(); // Read the value of b from the standard input using the Scanner object

		// Check if both a and b are less than or equal to 8
		if (a <= 8 && b <= 8) {
			System.out.println("Yay!"); // If the condition is true, print "Yay!" to the standard output
		}
		else {
			System.out.println(":("); // If the condition is false, print ":(" to the standard output
		}
	}
}

