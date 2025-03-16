import java.util.Scanner; // Step 1: Import the Scanner class from the Java standard input/output library.

public class Main {
	public static void main(String[] args) { // Step 2: Define the main function where the execution of the program begins.
		Scanner input = new Scanner(System.in); // Step 3: Create a Scanner object to read input from the standard input.
		int a, b, c, d; // Step 4: Declare four integer variables a, b, c, and d to store the input values.

		a = input.nextInt(); // Step 5: Read an integer from the user and store it in variable a.
		b = input.nextInt(); // Step 6: Read an integer from the user and store it in variable b.
		c = input.nextInt(); // Step 7: Read an integer from the user and store it in variable c.
		d = input.nextInt(); // Step 8: Read an integer from the user and store it in variable d.

		if (a + b > c + d) // Step 9: Compare the sum of a and b with the sum of c and d.
			System.out.println("Left"); // Step 10: If the sum of a and b is greater than the sum of c and d, print "Left".
		else if (a + b < c + d) // Step 11: If the sum of a and b is less than the sum of c and d, print "Right".
			System.out.println("Right");
		else // Step 12: If the sums are equal, print "Balanced".
			System.out.println("Balanced");

		input.close(); // Step 13: Close the Scanner object.
	}
}
