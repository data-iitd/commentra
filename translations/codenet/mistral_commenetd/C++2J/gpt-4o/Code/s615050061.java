import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    static final long B = 13131; // Base number for exponentiation
    static final int N = 500000 + 7; // Maximum size of input string

    static long[] f = new long[N]; // Intermediate result array
    static int[] g = new int[N]; // Exponent array
    static Map<Long, Long> map = new HashMap<>(); // Map to store intermediate results for faster calculation
    static long cnt; // Final result

    // Function to calculate B raised to the power of k
    static long pow(long a, long k) {
        if (k < 0) k += (1L << 63) - 1; // Handle negative exponents by converting them to positive
        long t = 1; // Initialize result to 1
        while (k > 0) { // Calculate exponentiation using bitwise right shift and multiplication
            if ((k & 1) == 1) t *= a; // If the current bit is 1, add the current base to the result
            a *= a; // Square the base
            k >>= 1; // Right shift k
        }
        return t; // Return the result
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Read the number of symbols
        String s = scanner.next(); // Read the input string

        // Initialize the first element of f and g arrays
        f[0] = 0;
        g[0] = 0;

        // Process each symbol in the input string
        for (int i = 1; i <= n; ++i) {
            // Update the current element of f array based on the current symbol
            if (s.charAt(i - 1) == '+' || s.charAt(i - 1) == '-') {
                f[i] = f[i - 1] + (s.charAt(i - 1) == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]);
            } else {
                f[i] = f[i - 1];
                g[i] = g[i - 1] + (s.charAt(i - 1) == '<' ? -1 : 1);
            }
        }

        // Calculate the final result
        for (int i = n; i > 0; --i) {
            map.put(f[i], map.getOrDefault(f[i], 0L) + 1); // Increment the count of the intermediate result in the map
            cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L); // Add the contribution of the current symbol to the final result
        }

        System.out.println(cnt); // Print the final result to standard output

        scanner.close();
    }
}
// <END-OF-CODE>
