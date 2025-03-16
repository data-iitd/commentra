// Import the Scanner class from the java.util package
import java.util.Scanner;

// Define the main method as public static void main(String[] args)
public static void main(String[] args) {
	// Create and initialize a Scanner object for reading input from the standard input stream
	@SuppressWarnings("resource")
	Scanner scan = new Scanner(System.in);

	// Read an integer value from the standard input stream and assign it to the 'n' variable
	int n = scan.nextInt();

	// Initialize a counter variable 'count' to zero
	int count = 0;

	// Use a for loop to iterate from 1 to 'n' and add the current number to the 'count' variable
	for (int i = 1; i <= n; i++) {
		count += i;
	}

	// Print the value of the 'count' variable to the standard output stream
	System.out.println(count);
}