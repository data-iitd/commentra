
import java.util.Scanner; // Import Scanner class for user input

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a new Scanner object to read user input
		
		// Read the first integer input from the user
		int X = sc.nextInt();
		
		// Read the second integer input from the user
		int t = sc.nextInt();
		
		// Check if the difference between X and t is greater than or equal to zero
		if(X - t >= 0) {
			// If the condition is true, print the difference between X and t
			System.out.println(X - t);
		} else {
			// If the condition is false, print zero instead
			System.out.println(0);
		}
	}
}