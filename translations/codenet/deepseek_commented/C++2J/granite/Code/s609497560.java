
import java.util.Scanner; // Import the Scanner class from the java.util package for input operations

public class s609497560{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
		int a = scanner.nextInt(); // Read an integer value from the user and store it in 'a'
		System.out.println(a + (a * a) + (a * a * a)); // Calculate and print the sum of 'a', 'a^2', and 'a^3'
		scanner.close(); // Close the Scanner object to release system resources
	}
}
// END-OF-CODE