import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare two integer variables to hold the input values
		int a, b;
		
		// Read two integers from standard input
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();

		// Check if the product of a and b is even or odd
		if (a*b%2 == 0) {
			// If the product is even, print "Even"
			System.out.println("Even");
		} else {
			// If the product is odd, print "Odd"
			System.out.println("Odd");
		}
	}
}
