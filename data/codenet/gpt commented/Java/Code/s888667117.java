import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Main {
    // Initialize scanner for input and print streams for output and error
    public static final Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    public static final PrintStream out = System.out;
    public static final PrintStream err = System.err;

    public static void main(String[] args) {
        // Read the input string and reverse it
        String Si = in.next();
        char[] S = new StringBuilder(Si).reverse().toString().toCharArray();

        // Initialize a dynamic programming array to store counts for modulo 13
        long[] dp = new long[13];
        dp[0] = 1; // Base case: there's one way to achieve a sum of 0

        // Iterate over each character in the reversed string
        for (int i = 0, d = 1; i < S.length; i++, d = d * 10 % 13) {
            // Create a new array to hold the updated counts for this iteration
            long[] nd = new long[13];

            // Debug output to track the current digit and its position
            err.println("d: " + d + ", i: " + i + ", S[i]: " + S[i]);
            char c = S[i];

            // Check if the character is a digit
            if (Character.isDigit(c)) {
                // Calculate the contribution of the digit to the current modulo
                int x = (c - '0') * d;

                // Update the new dp array based on the current digit
                for (int j = 0; j < 13; j++) {
                    nd[(j + x) % 13] = dp[j];
                }
            } else {
                // If the character is not a digit, consider all digits from 0 to 9
                for (int xi = 0; xi < 10; xi++) {
                    int x = xi * d;

                    // Update the new dp array for each possible digit
                    for (int j = 0; j < 13; j++) {
                        int ni = (j + x) % 13;
                        nd[ni] = (nd[ni] + dp[j]) % 1000000007; // Ensure we stay within bounds
                    }
                }
            }

            // Debug output to show the updated counts for this iteration
            err.println(Arrays.toString(nd));
            // Move to the next iteration with the updated counts
            dp = nd;
        }

        // Output the final result: the count of ways to achieve a sum that is congruent to 5 modulo 13
        out.println(dp[5]);
    }
}
