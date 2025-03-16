
import java.util.Scanner; // Importing Scanner class for input

public class s693332680{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input from standard input
		
		// Declare variables to hold input values
		int x, a, b;
		
		// Read three integer values from standard input
		x = scanner.nextInt();
		a = scanner.nextInt();
		b = scanner.nextInt();
		
		// Evaluate the difference between b and a to determine the output
		if (b - a <= 0) {
			System.out.println("delicious"); // Output "delicious" if b is less than or equal to a
		} else if (b - a <= x) {
			System.out.println("safe"); // Output "safe" if the difference is within the limit x
		} else {
			System.out.println("dangerous"); // Output "dangerous" if the difference exceeds x
		}
		
		scanner.close(); // Close the Scanner object to release system resources
	}
}
