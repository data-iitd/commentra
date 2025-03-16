
// Include the standard input/output library
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare two integer variables n and m
		int n, m;

		// Use the scanf function to read two integers from the standard input and store them in n and m variables
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		m = scanner.nextInt();

		// Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
		int result = (n - 1) * (m - 1);

		// Use the printf function to print the result to the standard output
		System.out.println(result);

		// Flush the output buffer to ensure that all the data is written to the standard output before the program terminates
		System.out.flush();

		// Indicate that the program has run successfully and terminate it
		System.exit(0);
	}
}

