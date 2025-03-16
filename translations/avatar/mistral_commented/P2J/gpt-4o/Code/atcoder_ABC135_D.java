import java.util.*;
import java.io.*;

public class Main {
    // Define the modulus value
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        // Set up input reading
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        int n = S.length();

        // Base case: if the length of the string is 1
        if (n == 1) {
            if (S.equals("5") || S.equals("?")) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
            return;
        }

        // Initialize a 2D array dp of size (n, 13) with all elements initialized to 0
        long[][] dp = new long[n][13];

        // Iterate through each index i from 0 to n-1
        for (int i = 0; i < n; i++) {
            // If i is the first index, process it differently
            if (i == 0) {
                // If the character at index i is not '?', update the dp array accordingly
                if (S.charAt(i) != '?') {
                    dp[i][Character.getNumericValue(S.charAt(i))] += 1;
                } else {
                    // If the character at index i is '?', update all elements in the dp array accordingly
                    for (int j = 0; j < 10; j++) {
                        dp[i][j] += 1;
                    }
                }
            } else {
                // If the character at index i is not '?', update the dp array accordingly
                if (S.charAt(i) != '?') {
                    int digit = Character.getNumericValue(S.charAt(i));
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + digit) % 13] += dp[i - 1][k];
                        dp[i][(k * 10 + digit) % 13] %= MOD; // Ensure we take mod at each step
                    }
                } else {
                    // If the character at index i is '?', update all elements in the dp array accordingly
                    for (int j = 0; j < 10; j++) {
                        for (int k = 0; k < 13; k++) {
                            dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                            dp[i][(k * 10 + j) % 13] %= MOD; // Ensure we take mod at each step
                        }
                    }
                }
            }
        }

        // Print the final answer, which is dp[n-1][5]
        System.out.println(dp[n - 1][5]);
    }
}
// <END-OF-CODE>
