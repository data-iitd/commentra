
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare three integer variables: a, b, and c
		int a, b, c;

		// Use the Scanner class to create a Scanner object named 'input'
		Scanner input = new Scanner(System.in);

		// Read three integers from the standard input and store them in variables a, b, and c
		a = input.nextInt();
		b = input.nextInt();
		c = input.nextInt();

		// Check if the condition a < b and b < c is true. If it is, print "Yes" to the standard output. Otherwise, print "No"
		if (a < b && b < c) {
			System.out.println("Yes"); // If the condition is true, print "Yes"
		} else {
			System.out.println("No"); // If the condition is false, print "No"
		}

		// Close the Scanner object
		input.close();
	}
}

