
import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Main {
    public static final Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    public static final PrintStream out = System.out;
    public static final PrintStream err = System.err;

    public static void main(String[] args) {
        // Read the input string
        String Si = in.next();
        
        // Reverse the input string and convert it to a character array
        char[] S = new StringBuilder(Si).reverse().toString().toCharArray();

        // Initialize the dynamic programming array with size 13, starting with dp[0] = 1
        long[] dp = new long[13];
        dp[0] = 1;

        // Iterate over the characters of the reversed string
        for (int i = 0, d = 1; i < S.length; i++, d = d * 10 % 13) {
            // Create a new array to store the updated dp values
            long[] nd = new long[13];

            // Print debug information about the current state
            err.println("d: " + d + ", i: " + i + ", S[i]: " + S[i]);
            char c = S[i];

            // Check if the current character is a digit
            if (Character.isDigit(c)) {
                int x = (c - '0') * d;

                // Update the new dp array based on the current digit and its position
                for (int j = 0; j < 13; j++) {
                    nd[(j + x) % 13] = dp[j];
                }
            } else {
                // If the current character is not a digit, update the dp array for all possible digits
                for (int xi = 0; xi < 10; xi++) {
                    int x = xi * d;

                    for (int j = 0; j < 13; j++) {
                        int ni = (j + x) % 13;
                        nd[ni] = (nd[ni] + dp[j]) % 1000000007;
                    }
                }
            }

            // Print the updated dp array for debugging purposes
            err.println(Arrays.toString(nd));
            
            // Update the dp array with the new values
            dp = nd;
        }

        // Print the result, which is the value of dp[5]
        out.println(dp[5]);
    }
}

