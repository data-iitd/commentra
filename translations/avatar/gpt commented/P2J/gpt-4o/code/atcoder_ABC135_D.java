import java.util.*;
import java.io.*;

public class Main {
    // Define the modulo constant
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        int n = S.length();

        // Handle the case where the input string length is 1
        if (n == 1) {
            if (S.equals("5") || S.equals("?")) {
                System.out.println(1);  // Output 1 if the single character is '5' or '?'
            } else {
                System.out.println(0);  // Output 0 for any other single character
            }
            return;
        }

        // Initialize a 2D list for dynamic programming
        long[][] dp = new long[n][13];

        // Fill the dp table based on the characters in S
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                // Handle the first character
                if (S.charAt(i) != '?') {
                    dp[i][Character.getNumericValue(S.charAt(i))] += 1;  // Increment the count for the specific digit
                } else {
                    // If the character is '?', increment counts for all digits (0-9)
                    for (int j = 0; j < 10; j++) {
                        dp[i][j] += 1;
                    }
                }
            } else {
                // Process subsequent characters
                if (S.charAt(i) != '?') {
                    // If the character is a specific digit
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + Character.getNumericValue(S.charAt(i))) % 13] += dp[i - 1][k];
                    }
                } else {
                    // If the character is '?', consider all digits (0-9)
                    for (int j = 0; j < 10; j++) {
                        for (int k = 0; k < 13; k++) {
                            dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        }
                    }
                }

                // Apply modulo to keep the values manageable
                for (int k = 0; k < 13; k++) {
                    dp[i][k] %= MOD;
                }
            }
        }

        // Output the count of valid numbers that are divisible by 13 and end with digit 5
        System.out.println(dp[n - 1][5]);
    }
}
// <END-OF-CODE>
