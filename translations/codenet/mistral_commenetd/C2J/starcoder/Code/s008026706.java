
import java.util.Scanner; // Import the Scanner class from the Java standard library

public class Main{ // Start of the Main class

	public static void main(String[] args){ // Start of the main method

		Scanner input = new Scanner(System.in); // Create a Scanner object named input and associate it with the standard input

		int a, b, x, y; // Declare four integer variables: a, b, x, and y

		a = input.nextInt(); // Read an integer from the standard input and store it in variable a
		b = input.nextInt(); // Read an integer from the standard input and store it in variable b

		x = 2*a + 2*b; // Multiply variables a and b by 2, and then add the results together and store the result in variable x

		y = a*b; // Multiply variables a and b and store the result in variable y

		System.out.println(y + " " + x); // Print the values of variables y and x to the standard output, separated by a space

		input.close(); // Close the input Scanner object

	} // End of the main method

} // End of the Main class

