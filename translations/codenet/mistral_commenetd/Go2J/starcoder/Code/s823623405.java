
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read the number of integers from the standard input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		// Create an array of size n to store the input integers
		int[] as = new int[n];

		// Read the input integers and calculate their prime factors
		for (int i = 0; i < n; i++) {
			as[i] = sc.nextInt();

			// Calculate the prime factors and their powers of the current integer
			Map<Integer, Integer> ps = primeFactorize(as[i]);

			// Iterate through the map to update the powers of the prime factors
			for (int k : ps.keySet()) {
				ps.put(k, Math.max(ps.get(k), ps.get(k)));
			}

			// Calculate the answer
			int x = 1; // Initialize a variable to store the product of prime factors

			// Iterate through the map to calculate the product of prime factors
			for (int k : ps.keySet()) {
				for (int i = 1; i <= ps.get(k); i++) { // Calculate the power of the prime factor
					x = mul(x, k); // Multiply the current product with the prime factor
				}
			}

			int ans = 0; // Initialize a variable to store the answer

			// Iterate through the array to calculate the answer
			for (int i = 0; i < n; i++) {
				ans = add(ans, div(x, as[i])); // Calculate the difference between the current product and the current integer, and add it to the answer
			}

			System.out.println(ans); // Print the answer
		}
	}

	public static int max(int a, int b) {
		// Return the maximum of two integers
		return Math.max(a, b);
	}

	public static Map<Integer, Integer> primeFactorize(int n) {
		// Calculate the prime factors and their powers of a given integer
		Map<Integer, Integer> res = new HashMap<Integer, Integer>();
		for (int i = 2; i*i <= n; i++) { // Iterate through the possible prime factors
			while (n%i == 0) { // If the current number is divisible by the current prime factor
				n /= i; // Divide the current number by the prime factor
				res.put(i, res.getOrDefault(i, 0) + 1); // Increment the power of the prime factor
			}
		}
		if (n!= 1) { // If the number is not equal to 1, it means that it has a prime factor greater than 1
			res.put(n, res.getOrDefault(n, 0) + 1); // Increment the power of the last prime factor
		}
		return res;
	}

	public static int pow(int n, int k) {
		// Calculate n raised to the power of k modulo mod
		if (k == 0) {
			return 1;
		} else if (k%2 == 1) {
			return pow(n, k-1) * n % mod;
		} else {
			int t = pow(n, k/2);
			return t * t % mod;
		}
	}

	public static int add(int a, int b) {
		// Return the sum of two integers modulo mod
		return (a + b) % mod;
	}

	public static int sub(int a, int b) {
		// Return the difference of two integers modulo mod
		return (a + mod - b) % mod;
	}

	public static int mul(int a, int b) {
		// Return the product of two integers modulo mod
		return a % mod * b % mod % mod;
	}

	public static int div(int a, int b) {
		// Return the quotient of a and b modulo mod
		return mul(a, pow(b, mod-2));
	}

	public static final int mod = 1000000007;
}

