import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    static final long B = 13131; // Define a constant base for hashing
    static final int N = 500000 + 7; // Define the maximum length of the string + 7 for safety

    static long[] f = new long[N]; // Declare an array of long to store the hash values
    static int[] g = new int[N]; // Declare an array of integers to store position-dependent values
    static Map<Long, Long> map = new HashMap<>(); // Declare a map to store the frequency of hash values
    static long cnt; // Declare a long to count the number of valid substrings

    // Define the pow function to calculate a^k using binary exponentiation
    static long pow(long a, long k) {
        if (k < 0) k += (1L << 63) - 1; // Handle negative exponents
        long t = 1; // Initialize the result to 1
        while (k > 0) { // Square and halve the exponent
            if ((k & 1) == 1) t *= a; // If the exponent is odd, multiply the result
            a *= a; // Square the base
            k >>= 1; // Halve the exponent
        }
        return t; // Return the result
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the input value for n
        char[] s = new char[N]; // Declare a character array to store the input string
        scanner.next(); // Consume the newline
        String input = scanner.next(); // Read the input string
        for (int i = 1; i <= n; ++i) {
            s[i] = input.charAt(i - 1); // Store the characters in the array
        }

        for (int i = 1; i <= n; ++i) { // Iterate through the string
            if (s[i] == '+' || s[i] == '-') { // Check if the character is '+' or '-'
                f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]); // Compute the hash value
            } else {
                f[i] = f[i - 1];
                g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1); // Update the position-dependent values
            }
        }

        for (int i = n; i > 0; --i) { // Iterate through the string in reverse
            map.put(f[i], map.getOrDefault(f[i], 0L) + 1); // Increment the frequency of the hash value
            cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L); // Count the valid substrings
        }

        System.out.println(cnt); // Print the count of valid substrings
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
