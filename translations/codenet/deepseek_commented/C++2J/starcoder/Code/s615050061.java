import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Uncomment the following lines if you want to read from a file and write to a file
		// BufferedReader br = new BufferedReader(new FileReader("code.in"));
		// BufferedWriter bw = new BufferedWriter(new FileWriter("code.out"));

		int n = Integer.parseInt(br.readLine()); // Read the input values for n and the string s
		char[] s = br.readLine().toCharArray();
		long[] f = new long[n + 1]; // Declare an array of long to store the hash values
		int[] g = new int[n + 1]; // Declare an array of integers to store position-dependent values
		Map<Long, Long> map = new TreeMap<>(); // Declare a map to store the frequency of hash values
		long cnt = 0; // Declare a long to count the number of valid substrings

		for (int i = 1; i <= n; ++i) { // Iterate through the string
			if (s[i] == '+' || s[i] == '-') { // Check if the character is '+' or '-'
				f[i] = f[i - 1] + (s[i] == '+'? 1 : -1) * pow(B, g[i] = g[i - 1]); // Compute the hash value
			} else {
				f[i] = f[i - 1];
				g[i] = g[i - 1] + (s[i] == '<'? -1 : 1); // Update the position-dependent values
			}
		}
		for (int i = n; i; --i) { // Iterate through the string in reverse
			map.put(f[i], map.getOrDefault(f[i], 0L) + 1); // Update the frequency of hash values
			cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L); // Count the valid substrings
		}
		bw.write(cnt + "\n"); // Print the count of valid substrings

		// br.close();
		// bw.close();
	}

	// Define the pow function to calculate a^k using binary exponentiation
	static long pow(long a, long k) {
		if (k < 0) k += (1L << 63) - 1; // Handle negative exponents
		long t = 1; // Initialize the result to 1
		for (; k; a = a * a, k >>= 1) // Square and halve the exponent
			if (k & 1) t = t * a; // If the exponent is odd, multiply the result
		return t; // Return the result
	}
}

