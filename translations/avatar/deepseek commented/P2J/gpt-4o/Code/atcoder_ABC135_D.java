import java.util.*;
import java.io.*;

public class Main {
    static final int MOD = 1000000007;  // Define modulo constant
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();  // Read input string
        int n = S.length();  // Get length of the string

        if (n == 1) {  // Check if the string length is 1
            if (S.equals("5") || S.equals("?")) {  // Check if the string is '5' or '?'
                System.out.println(1);  // Print 1 if true
            } else {
                System.out.println(0);  // Print 0 otherwise
            }
            return;  // Exit the program
        }

        dp = new int[n][13];  // Initialize dp array
        for (int i = 0; i < n; i++) {  // Iterate over the length of the string
            if (i == 0) {  // Base case for the first character
                if (S.charAt(i) != '?') {  // Check if the character is not '?'
                    dp[i][Character.getNumericValue(S.charAt(i))] += 1;  // Update dp value directly
                } else {
                    for (int j = 0; j < 10; j++) {  // Iterate over all possible digits
                        dp[i][j] += 1;  // Increment dp value
                    }
                }
            } else {  // General case for subsequent characters
                if (S.charAt(i) != '?') {  // Check if the character is not '?'
                    for (int k = 0; k < 13; k++) {  // Iterate over all possible remainders
                        dp[i][(k * 10 + Character.getNumericValue(S.charAt(i))) % 13] += dp[i - 1][k];  // Update dp value
                    }
                } else {
                    for (int j = 0; j < 10; j++) {  // Iterate over all possible digits
                        for (int k = 0; k < 13; k++) {  // Iterate over all possible remainders
                            dp[i][(k * 10 + j) % 13] += dp[i - 1][k];  // Update dp value
                        }
                    }
                }
                for (int k = 0; k < 13; k++) {  // Apply modulo to prevent overflow
                    dp[i][k] %= MOD;
                }
            }
        }
        System.out.println(dp[n - 1][5]);  // Print the result
    }
}
