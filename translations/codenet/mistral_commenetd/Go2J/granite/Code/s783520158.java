
import java.util.Scanner; // Import the "Scanner" class from the "java.util" package for input/output operations

public class s783520158{
	public static void main(String[] args) {
		// Create a new instance of the "Scanner" class to read input from the standard input
		Scanner scanner = new Scanner(System.in);

		// Declare three integer variables "a", "b", and "c"
		int a, b, c;

		// Read three integers from the standard input and assign them to the variables
		a = scanner.nextInt();
		b = scanner.nextInt();
		c = scanner.nextInt();

		// Check if the difference between "b" and "a" is equal to the difference between "c" and "b"
		if (b - a == c - b) {
			// If the condition is true, print "YES" to the standard output
			System.out.println("YES");
		} else {
			// If the condition is false, print "NO" to the standard output
			System.out.println("NO");
		}

		// Close the "Scanner" object to release system resources
		scanner.close();

		// End of the code
	}
}

