
// Include the standard input/output library
import java.util.Scanner;

// Declare variables
public class Main {
	public static void main(String[] args) {
		// Declare variables a, b, mawari, and menseki as integers
		int a, b, mawari, menseki;

		// Read input values for variables a and b from the user
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();

		// Assign the variable mawari the sum of the squares of a and b
		mawari = a + a + b + b;
		// Assign the variable menseki the product of a and b
		menseki = a * b;
		// Print the values of menseki and mawari to the console
		System.out.println(menseki + " " + mawari);
	}
}

