
import java.io.*;
import java.util.*;

public class s615050061{
	public static void main(String[] args) throws IOException {
		// Uncomment the following lines if you want to read from a file and write to a file
		// BufferedReader br = new BufferedReader(new FileReader("code.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("code.out"));

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine()); // Read the input value for n
		char[] s = br.readLine().toCharArray(); // Read the input string s
		long[] f = new long[n + 1]; // Initialize an array of long to store the hash values
		int[] g = new int[n + 1]; // Initialize an array of int to store the position-dependent values
		long B = 13131; // Define a constant base for hashing
		long cnt = 0; // Initialize a long to count the number of valid substrings
		Map<Long, Long> map = new HashMap<>(); // Initialize a map to store the frequency of hash values

		for (int i = 1; i <= n; ++i) { // Iterate through the string
			if (s[i - 1] == '+' || s[i - 1] == '-') { // Check if the character is '+' or '-'
				f[i] = f[i - 1] + (s[i - 1] == '+'? 1 : -1) * pow(B, g[i] = g[i - 1]); // Compute the hash value
			} else {
				f[i] = f[i - 1];
				g[i] = g[i - 1] + (s[i - 1] == '<'? -1 : 1); // Update the position-dependent values
			}
		}

		for (int i = n; i > 0; --i) { // Iterate through the string in reverse
			map.put(f[i], map.getOrDefault(f[i], 0L) + 1); // Count the frequency of hash values
			cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L); // Count the valid substrings
		}

		pw.println(cnt); // Print the count of valid substrings

		pw.close(); // Close the output stream
	}

	// Define the pow function to calculate a^k using binary exponentiation
	public static long pow(long a, long k) {
		if (k < 0) k += (1L << 63) - 1; // Handle negative exponents
		long t = 1; // Initialize the result to 1
		for (; k > 0; a = a * a, k >>= 1) { // Square and halve the exponent
			if ((k & 1) == 1) t = t * a; // If the exponent is odd, multiply the result
		}
		return t; // Return the result
	}
}

Translate the above Java code to Python and end with comment "