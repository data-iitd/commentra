
import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		// Initialize scanner to read input from the console
		Scanner scanner = new Scanner(System.in);

		// Read the first integer from the user input
		int n = scanner.nextInt();

		// Initialize answer variable and modulus constant
		long ans = 1;
		int mod = (int) Math.pow(10, 9) + 7;

		// Iterate through all numbers from 2 to n
		for (int i = 2; i <= n; i++) {
			// Iterate through all possible divisors of the current number i
			for (int j = 2; (i % j != 0 && j < i) || j == i; j++) {
				// If the current divisor j equals the number i, calculate the sum of digits in the base 10 representation of all numbers less than or equal to n that are divisible by i
				if (j == i) {
					int s = 0;
					// Iterate through all numbers from 1 to n
					for (int k = 1; k <= n; k++) {
						// Check if the current number k is divisible by i
						if (k % i == 0) {
							// Increment the sum variable s by the number of digits in the base 10 representation of k
							s += countDigits(k, i);
						}
					}

					// Multiply the answer by the sum of digits and take the modulo with the modulus constant
					ans = (ans * (s + 1) ) % mod;

				}
			}
		}

		// Print the final answer
		System.out.println(ans);
	}

	// Helper method to count the number of digits in the base 10 representation of a number
	private static int countDigits(int n, int base) {
		int count = 0;
		// Divide the number by the base and increment the count by 1 for each quotient
		while (n > 0) {
			n /= base;
			count++;
		}
		return count;
	}
}

