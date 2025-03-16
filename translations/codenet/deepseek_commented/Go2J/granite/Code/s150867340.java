
import java.util.Scanner; // Importing the Scanner class for reading input from the console

public class s150867340{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input from the console
		int a = scanner.nextInt(); // Reading the first integer from the console
		int b = scanner.nextInt(); // Reading the second integer from the console
		int product = a * b; // Calculating the product of `a` and `b`
		if (product % 2 == 0) { // Checking if the product is even
			System.out.println("Even"); // Printing "Even" if the product is even
		} else {
			System.out.println("Odd"); // Printing "Odd" if the product is odd
		}
		scanner.close(); // Closing the Scanner object to release system resources
	}
}
