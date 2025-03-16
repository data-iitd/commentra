import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Define constants for base and maximum size
    static final long B = 13131;
    static final int N = 500000 + 7;

    // Declare global variables
    static int n; // Length of the input string
    static char[] s = new char[N]; // Input string
    static long[] f = new long[N]; // Array to store computed values based on the input string
    static int[] g = new int[N]; // Array to store the shift values
    static Map<Long, Long> map = new HashMap<>(); // Map to count occurrences of computed values
    static long cnt; // Counter for the final result

    // Function to compute power of a number with a given exponent
    static long pow(long a, long k) {
        // Adjust exponent if negative
        if (k < 0) k += (1L << 63) - 1;
        long t = 1; // Initialize result
        // Exponentiation by squaring
        while (k > 0) {
            if ((k & 1) == 1) t *= a; // Multiply result if current bit is set
            a *= a; // Square the base
            k >>= 1; // Divide exponent by 2
        }
        return t; // Return computed power
    }

    public static void main(String[] args) {
        // Read input values: number of operations and the operations string
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        s = scanner.next().toCharArray();

        // Process each character in the input string
        for (int i = 1; i <= n; ++i) {
            // If the character is '+' or '-', update f and g arrays
            if (s[i - 1] == '+' || s[i - 1] == '-') {
                f[i] = f[i - 1] + (s[i - 1] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]);
            } else {
                // If the character is '<' or '>', update f and g arrays accordingly
                f[i] = f[i - 1]; // No change in f
                g[i] = g[i - 1] + (s[i - 1] == '<' ? -1 : 1); // Update g based on direction
            }
        }

        // Iterate backwards through the string to count valid combinations
        for (int i = n; i > 0; --i) {
            map.put(f[i], map.getOrDefault(f[i], 0L) + 1); // Increment the count of the current f value
            // Update the counter with the number of valid combinations found
            cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L);
        }

        // Output the final count of valid combinations
        System.out.println(cnt);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
