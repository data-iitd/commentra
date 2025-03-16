import java.util.Scanner; // This line imports the Scanner class from the java.util package.

public class Main { // The Main class is the entry point of the program. It initializes the program and calls the function main().
	public static void main(String[] args) { // The main function is the entry point of the program. It initializes the program and calls the function main().
		Scanner sc = new Scanner(System.in); // Create a new Scanner object named sc that reads from the standard input.
		int a = sc.nextInt(); // Read an integer from the standard input and assign it to the variable a.
		int b = sc.nextInt(); // Read an integer from the standard input and assign it to the variable b.
		int c = sc.nextInt(); // Read an integer from the standard input and assign it to the variable c.
		// The following if statement checks if any of the following conditions are true:
		// (a + b) == c // If the sum of a and b is equal to c
		// (b + c) == a // If the sum of b and c is equal to a
		// (a + c) == b // If the sum of a and c is equal to b
		if ((a + b == c) || (b + c == a) || (a + c == b)) { // If any of the above conditions are true, the following code is executed.
			System.out.println("Yes"); // Output the string "Yes" to the standard output.
		}
		else { // If none of the above conditions are true, the following code is executed.
			System.out.println("No"); // Output the string "No" to the standard output.
		}
	}
}
