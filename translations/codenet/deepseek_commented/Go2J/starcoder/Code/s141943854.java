
import java.util.Scanner;

public class HelloWorld {
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		stdin.useDelimiter("\n");
		String sage = stdin.next();

		switch (sage) {
		case "1":
			System.out.println("Hello World"); // Print "Hello World" if input is "1"
			break;
		case "2":
			int sum = 0; // Declare sum variable to store the sum of two integers
			for (int i = 0; i < 2; i++) {
				stdin.next(); // Read input from standard input
				sum += Integer.parseInt(stdin.next()); // Add the integer to the sum
			}
			System.out.println(sum); // Print the sum of the two integers
			break;
		}
	}
}

