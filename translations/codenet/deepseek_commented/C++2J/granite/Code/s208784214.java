
import java.util.Scanner;

public class s208784214{
	public static void main(String[] args) {
		// Step 1: Include necessary libraries and declare variables
		// We import the Scanner class from the java.util package to read input values.
		// We declare two integer variables, N and A, to store user input.

		int N, A;

		// Step 2: Read input values
		// We create a Scanner object to read input values from the standard input.
		// We read two integer values and store them in variables N and A.
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		A = scanner.nextInt();

		// Step 3: Perform the required operation
		// We check if the remainder of N divided by 500 is less than or equal to A.
		// If the condition is true, we print "Yes"; otherwise, we print "No".
		System.out.println(N % 500 <= A? "Yes" : "No");

		// Step 4: Return from the main function
		// We return from the main function.
		return;
	}
}
