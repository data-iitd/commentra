
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Step 1: Declare an integer variable x.
		int x;

		// Step 2: Create a Scanner object.
		Scanner input = new Scanner(System.in);

		// Step 3: Read an integer value from the user and store it in x.
		x = input.nextInt();

		// Step 4: Calculate the cube of the value stored in x.
		x = x * x * x;

		// Step 5: Print the result.
		System.out.println(x);

		// Step 6: End the main function and return 0.
		return 0;
	}
}

