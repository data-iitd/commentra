
import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
	public static void main(String[] args) {
		// Create a new Scanner object named sc to read input from the standard input stream
		Scanner sc = new Scanner(System.in);

		// Read the first integer from the standard input stream
		int num1 = sc.nextInt();

		// Read the second integer from the standard input stream
		int num2 = sc.nextInt();

		// Check if the first integer is less than or equal to the second integer
		boolean condition = num1 <= num2;

		// Print the string "Yes" to the standard output stream if the condition is true, otherwise print "No"
		System.out.println(condition ? "Yes" : "No");

		// Close the Scanner object to free up system resources
		sc.close();
	}
}