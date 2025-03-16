
import java.util.*;
import java.io.*;

public class Main {

	// Set scanner to scan words
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.useDelimiter("\\s");

		// Read an integer n from standard input
		int n = sc.nextInt();

		// Read n integers c from standard input and store them in a slice
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
		}

		// Initialize answer variable to 0
		int ans = 0;

		// Sort slice c in ascending order
		Arrays.sort(c);

		// Iterate through slice c and calculate answer
		for (int i = 0; i < n; i++) {
			// Calculate contribution of current integer to answer
			ans = (ans + (n+1-i)*c[i]%mod)%mod;
		}

		// Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
		System.out.println(ans*modpow(4,n-1)%mod);
	}

	// Constants
	public static final int mod = 1000000007;

	// Function to calculate modular exponentiation
	public static int modpow(int a, int n) {
		// Initialize result to 1
		int res = 1;

		// If n is 0, return result
		if (n == 0) { return res; }

		// If n is 1, return a
		if (n == 1) { return a; }

		// If n is odd, multiply result with a multiplied by itself recursively
		if ((n&1) == 1) {
			res = res*a%mod;
			a = a*a%mod;
			n = n>>1;
			res = res*modpow(a,n)%mod;
		}

		// If n is even, square result and recursively call function for n/2
		else {
			a = a*a%mod;
			n = n>>1;
			res = modpow(a,n)%mod;
		}

		// Return result
		return res;
	}

}

