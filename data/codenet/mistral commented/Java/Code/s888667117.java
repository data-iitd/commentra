
import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Main {
    // Initialize scanner and print streams
    public static final Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    public static final PrintStream out = System.out;
    public static final PrintStream err = System.err;

    public static void main(String[] args) {
        String Si = in.next(); // Read the first input string from the standard input

        // Reverse the input string and convert it to a character array
        char[] S = new StringBuilder(Si).reverse().toString().toCharArray();

        long[] dp = new long[13]; // Initialize a long array dp of size 13 for dynamic programming
        dp[0] = 1; // Set the base case dp[0] = 1

        for (int i = 0, d = 1; i < S.length; i++, d = d * 10 % 13) { // Iterate through the character array S
            long[] nd = new long[13]; // Initialize a new long array nd of size 13 for the next iteration

            // Print some debugging information
            err.println("d: " + d + ", i: " + i + ", S[i]: " + S[i]);

            char c = S[i]; // Assign the current character from the character array S to the variable c

            if (Character.isDigit(c)) { // Check if the current character is a digit
                int x = (c - '0') * d; // Calculate the value x = (current digit * d)

                // Update the new dynamic programming array nd for the current digit
                for (int j = 0; j < 13; j++) {
                    nd[(j + x) % 13] = dp[j]; // Set nd[j + x] = dp[j]
                }
            } else { // Else, the current character is not a digit
                for (int xi = 0; xi < 10; xi++) { // Iterate through the digits 0 to 9
                    int x = xi * d; // Calculate the value x = (digit * d)

                    // Update the new dynamic programming array nd for the current character and digit combination
                    for (int j = 0; j < 13; j++) {
                        int ni = (j + x) % 13; // Calculate the index ni = (j + x) % 13
                        nd[ni] = (nd[ni] + dp[j]) % 1000000007; // Set nd[ni] = (nd[ni] + dp[j]) % 1000000007
                    }
                }
            }

            // Print the new dynamic programming array nd for debugging purposes
            err.println(Arrays.toString(nd));

            // Update the dynamic programming array dp with the new dynamic programming array nd
            dp = nd;
        }

        // Print the result, which is dp[5]
        out.println(dp[5]);
    }
}

