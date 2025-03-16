
import java.util.Scanner; // Import the Scanner class

public class Main
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in); // Create a Scanner object

		int a, b, h; // Declare three integer variables: a, b, and h

		System.out.print("Enter the values of a, b, and h: "); // Print a message asking for user input
		a = input.nextInt(); // Read an integer from the user and store it in variable a
		b = input.nextInt(); // Read an integer from the user and store it in variable b
		h = input.nextInt(); // Read an integer from the user and store it in variable h

		// Calculate the area of the rectangle using the formula: area = length * width
		System.out.println((a+b)*h/2); // Print the result, which is the area of the rectangle
	}
}

