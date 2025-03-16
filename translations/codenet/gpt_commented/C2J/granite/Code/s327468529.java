
import java.io.*;
import java.util.*;

public class s327468529{
    public static void main(String[] args) throws Exception {
        // Read input values
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        long n = Long.parseLong(input[0]);
        long m = Long.parseLong(input[1]);
        String s = br.readLine();

        // Process the input string and calculate the result based on color counts
        long result = 1; // Variable to store the result
        long pcnt = 0; // Variable for potential calculations
        long sum = 0; // Variable for summation
        long item; // Temporary variable
        long[] cnt = new long[3]; // Array for color counts
        Arrays.fill(cnt, 0); // Initialize color counts to 0

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
                    v = -1; // Invalid color
                    break;
            }

            // Check if there are available colors to form combinations
            if (cnt[(int) ((v + 1) % 3)] > 0 && cnt[(int) ((v + 2) % 3)] > 0) {
                result *= pcnt; // Multiply by the count of available combinations
                pcnt--; // Decrease the count of available combinations
                result %= 100000007; // Apply modulo
                cnt[(int) ((v + 1) % 3)]--; // Decrease count of the first color
                cnt[(int) ((v + 2) % 3)]--; // Decrease count of the second color
            } else {
                // If there are more of the other two colors than the current color
                if ((cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) > cnt[(int) v]) {
                    result *= (cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) - cnt[(int) v];
                    result %= 100000007; // Apply modulo
                    pcnt++; // Increase the count of available combinations
                }
                cnt[(int) v]++; // Increase count of the current color
            }
        }

        // Calculate the factorial of n for final result
        for (int i = 1; i <= n; i++) {
            result = (result * i) % 100000007;
        }

        // Output the result
        System.out.println(result);
    }
}

// Translate the above Java code to C# and end with comment "