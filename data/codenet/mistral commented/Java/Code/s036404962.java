// Import the Scanner class from the java.util package
import java.util.Scanner;

// Define the Main class with a main method as its entry point
public class Main {

	// Define the main method as public static void main(String[] args)
	public static void main(String[] args) {

		// Create a new Scanner object to read input from the standard input stream
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);

		// Read the first integer X from the standard input
		int X = scan.nextInt();

		// Read the second integer t from the standard input
		int t = scan.nextInt();

		// Check if X is greater than or equal to t
		if(X >= t){
			// If so, print the difference between X and t
			System.out.println(X - t);
		} else if (X < t){
			// If X is less than t, print 0 to the standard output
			System.out.print(0);
		}

		// End of the main method
	}

	// End of the Main class definition
}