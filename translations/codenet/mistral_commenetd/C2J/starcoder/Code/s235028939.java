import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare two integer variables n and m
		int n, m;

		// Use the Scanner class to read two integers from the standard input and store them in n and m variables
		Scanner input = new Scanner(System.in);
		n = input.nextInt();
		m = input.nextInt();

		// Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
		int result = (n - 1) * (m - 1);

		// Use the System.out.println function to print the result to the standard output
		System.out.println(result);

		// Indicate that the program has run successfully and terminate it
		return;
	}
}
