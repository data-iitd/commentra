
import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		// Read an integer n from the user
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		
		// Initialize ans to 1 and set the modulo constant
		long ans = 1;
		int mod = (int) Math.pow(10, 9) + 7;
		
		// Loop through numbers from 2 to n
		for (int i = 2; i <= n; i++) {
			// Check if i is a prime number
			for (int j = 2; (i % j != 0 && j < i) || j == i; j++) {
				if (j == i) {
					// i is a prime number, calculate s
					int s = 0;
					// Sum the values returned by findS for each number k from 1 to n
					for (int k = 1; k <= n; k++) {
						s += findS(k, i);
					}
					// Update ans by multiplying it with (s + 1) and taking modulo mod
					ans = (ans * (s + 1) ) % mod;
				}
			}
		}
		// Print the final value of ans
		System.out.println(ans);
	}

	// Helper method to find the power of a prime i in k
	private static int findS(int k, int i) {
		int s = 0;
		for (int j = k; j % i == 0; j /= i) {
			s++;
		}
		return s;
	}
}

