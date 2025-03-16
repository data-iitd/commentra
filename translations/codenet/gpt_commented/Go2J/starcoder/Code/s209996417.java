import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare variables to hold the input values n and k
		double n, k;
		
		// Read input values for n and k from the user
		Scanner sc = new Scanner(System.in);
		n = sc.nextDouble();
		k = sc.nextDouble();
		sc.close();

		// Determine the number of digits when n is represented in base k
		// Example: For n = 10 in base 2, it is represented as 1010 which has 4 digits
		// The number of digits is determined by the highest power of k that is less than or equal to n.
		// In this case, we need to find x such that k^x <= n < k^(x+1)
		// The result will be x + 1, which gives the total number of digits.

		double x = 0.0; // Initialize x to 0, which represents the current power of k being evaluated
		while (true) {
			// Calculate k raised to the power of x (lower bound)
			double under = Math.pow(k, x);
			// Calculate k raised to the power of x + 1 (upper bound)
			double upper = Math.pow(k, x+1);

			// Check if n falls within the range [k^x, k^(x+1))
			if (under <= n && n < upper) {
				// If it does, print the number of digits (which is x + 1) and exit the program
				System.out.println(x + 1);
				return;
			}
			// Increment x to check the next power of k
			x++;
		}
	}
}

