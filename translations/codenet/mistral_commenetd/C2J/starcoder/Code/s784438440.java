import java.util.Scanner; // Include the standard input/output library

public class Main
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in); // Create a new standard input/output object

		int a, b; // Declare two integer variables 'a' and 'b'

		a = input.nextInt(); // Read an integer from the standard input and store it in variable 'a'
		b = input.nextInt(); // Read an integer from the standard input and store it in variable 'b'

		System.out.println((b-1)+(a-2)/(a-1)); // Print the result of the expression ((b-1)+(a-2))/(a-1) to the standard output
	}
}
