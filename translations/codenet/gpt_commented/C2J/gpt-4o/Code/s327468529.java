import java.util.*;
import java.io.*;

public class Main {
    // Define constants for large numbers and modular arithmetic
    private static final long BIG = 2000000007;
    private static final long VERYBIG = 20000000000000007L;
    private static final long MOD = 1000000007;
    private static final long FOD = 998244353;

    // Define maximum size for arrays
    private static final int N_MAX = 1048576;

    // Global variables for various parameters
    static long n, m; // Dimensions or counts
    static long[] cnt = new long[3]; // Count of colors
    static long pcnt; // Some parameter
    static String s = ""; // Input string

    // Function to compute the result
    static long solve() {
        long result = 1; // Variable to store the result

        // Process the input string and calculate the result based on color counts
        for (int i = 0; i < n * 3; i++) {
            long v;
            switch (s.charAt(i)) {
                case 'R':
                    v = 0; // Red
                    break;
                case 'G':
                    v = 1; // Green
                    break;
                case 'B':
                    v = 2; // Blue
                    break;
                default:
                    continue; // Skip if not a valid color
            }

            // Check if there are available colors to form combinations
            if (cnt[(int) ((v + 1) % 3)] > 0 && cnt[(int) ((v + 2) % 3)] > 0) {
                result *= pcnt; // Multiply by the count of available combinations
                pcnt--; // Decrease the count of available combinations
                result %= FOD; // Apply modulo
                cnt[(int) ((v + 1) % 3)]--; // Decrease count of the first color
                cnt[(int) ((v + 2) % 3)]--; // Decrease count of the second color
            } else {
                // If there are more of the other two colors than the current color
                if ((cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) > cnt[(int) v]) {
                    result *= (cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) - cnt[(int) v];
                    result %= FOD; // Apply modulo
                    pcnt++; // Increase the count of available combinations
                }
                cnt[(int) v]++; // Increase count of the current color
            }
        }

        // Calculate the factorial of n for final result
        for (long i = 1; i <= n; i++) {
            result = (result * i) % FOD;
        }

        // Output the result
        System.out.println(result);
        return 0;
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextLong(); // Read n
        m = scanner.nextLong(); // Read m
        s = scanner.next(); // Read the string input

        // Call the solve function to compute the result
        solve();

        scanner.close();
    }
}

// <END-OF-CODE>
