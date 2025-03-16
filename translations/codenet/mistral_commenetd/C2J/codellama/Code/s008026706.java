
import java.util.Scanner; // Import the Scanner class from the java.util package

public class Main { // Start of the Main class
	public static void main(String[] args) { // Start of the main function
		Scanner sc = new Scanner(System.in); // Create a new Scanner object to read from the standard input
		int a, b, x, y; // Declare four integer variables: a, b, x, and y

		a = sc.nextInt(); // Read an integer from the standard input and store it in variable a
		b = sc.nextInt(); // Read an integer from the standard input and store it in variable b

		x = 2*a + 2*b; // Multiply variables a and b by 2, and then add the results together and store the result in variable x

		y = a*b; // Multiply variables a and b and store the result in variable y

		System.out.println(y + " " + x); // Print the values of variables y and x to the standard output, separated by a space and followed by a newline character
	}
}
