import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        // Step 1: Importing Scanner
        // The code starts by importing the Scanner class from the java.util package.
        // This is necessary for reading input from the user.
        Scanner sc = new Scanner(System.in);
        
        // Step 2: Reading Input
        // The program reads a string S from the user.
        String S = sc.next();
        
        // Step 3: Modulo and DP Array
        // It defines a constant MOD for modulo operations and initializes a 2D array dp
        // to store the number of ways to form numbers modulo 13.
        long MOD = 1000000007;
        long dp[][] = new long[S.length() + 1][13];
        
        // Step 4: DP Initialization
        // The base case is set where dp[0][0] = 1, indicating that there is one way to form the number "0" modulo 13.
        dp[0][0] = 1;
        
        // Step 5: Iterating Over Input
        // The program iterates over each character in the string S.
        for (int i = 0; i < S.length(); i++) {
            if (S.substring(i, i + 1).equals("?")) {
                // Step 6: Handling Question Marks
                // If the current character is a question mark (?), it iterates over all possible digits (0-9)
                // and updates the DP table for all possible remainders modulo 13.
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
                        dp[i + 1][(k * 10 + j) % 13] %= MOD;
                    }
                }
            } else {
                // Step 7: Handling Digits
                // If the current character is a digit, it updates the DP table for the corresponding digit
                // and its remainder modulo 13.
                for (int k = 0; k < 13; k++) {
                    int x = Integer.parseInt(S.substring(i, i + 1));
                    dp[i + 1][(k * 10 + x) % 13] += dp[i][k];
                    dp[i + 1][(k * 10 + x) % 13] %= MOD;
                }
            }
        }
        
        // Step 9: Output
        // Finally, the program prints the number of ways to form a number that is congruent to 5 modulo 13.
        System.out.println(dp[S.length()][5]);
    }
}
