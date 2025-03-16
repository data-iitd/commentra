
import java.util.Scanner; // Importing the Scanner class for input operations

public class s506882149{ // s506882149 class declaration

	// comp function compares two integers x and a.
	// It returns 0 if x is less than a, otherwise it returns 10.
	public static int comp(int x, int a) {
		// Check if x is less than a
		if (x < a) {
			return 0; // Return 0 if the condition is true
		} 
		return 10; // Return 10 if x is not less than a
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); // Create a Scanner object for input operations
		int x, a; // Declare two integer variables x and a
		// Read input values for x and a from the user
		x = scanner.nextInt();
		a = scanner.nextInt();
		
		// Call the comp function with x and a, and print the result
		System.out.println(comp(x, a));
	}
}
