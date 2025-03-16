
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Step 1: Declare variables to store the input values
		int a, b, c;

		// Step 2: Create a Scanner object to read input from the command line
		Scanner scanner = new Scanner(System.in);

		// Step 3: Read input values from the user
		a = scanner.nextInt();
		b = scanner.nextInt();
		c = scanner.nextInt();

		// Step 4: Calculate the number formed by the digits a, b, and c
		int number = 100*a + 10*b + c;

		// Step 5: Check if the number is divisible by 4
		if (number % 4 == 0) {
			// Output the result if the number is divisible by 4
			System.out.println("YES");
		}
		else {
			// Output the result if the number is not divisible by 4
			System.out.println("NO");
		}
	}
}

