
import java.util.Scanner; // Import the Scanner class from the java.util package

public class Main { // Define the Main class
	public static void main(String[] args) { // Define the main function with no arguments
		Scanner sc = new Scanner(System.in); // Create a new Scanner object to read from the standard input

		int a = sc.nextInt(); // Read an integer from the standard input and store it in the variable a
		int b = sc.nextInt(); // Read an integer from the standard input and store it in the variable b
		int c = sc.nextInt(); // Read an integer from the standard input and store it in the variable c
		int d = sc.nextInt(); // Read an integer from the standard input and store it in the variable d

		if (a + b > c + d) { // Check if the sum of a and b is greater than the sum of c and d
			System.out.println("Left"); // If true, print "Left" to the standard output
		} else if (a + b < c + d) { // Check if the sum of a and b is less than the sum of c and d
			System.out.println("Right"); // If true, print "Right" to the standard output
		} else { // If neither of the above conditions is true
			System.out.println("Balanced"); // Print "Balanced" to the standard output
		}
	}
}

