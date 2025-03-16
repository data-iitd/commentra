import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the input string S
        String S = sc.next();
        
        // Define a constant MOD to be used for modulo operations
        long MOD = 1000000007;
        
        // Initialize a 2D array dp to store the number of ways to form numbers
        // dp[i][j] will represent the number of ways to form a number using the first i characters of S that gives a remainder j when divided by 13
        long dp[][] = new long[S.length() + 1][13];
        
        // Base case: There is one way to form the number 0 with 0 characters
        dp[0][0] = 1;
        
        // Iterate through each character in the string S
        for(int i = 0; i < S.length(); i++) {
            // Check if the current character is a '?', which can represent any digit from 0 to 9
            if(S.substring(i , i + 1).equals("?")) {
                // Loop through all possible digits (0 to 9)
                for(int j = 0; j < 10; j++) {
                    // Loop through all possible remainders (0 to 12)
                    for(int k = 0; k < 13; k++) {
                        // Update the dp array for the next character based on the current character being a digit j
                        dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
                        // Ensure the value stays within the bounds of MOD
                        dp[i + 1][(k * 10 + j) % 13] %= MOD;
                    }
                }
            } else {
                // If the current character is a specific digit, parse it to an integer
                for(int k = 0; k < 13; k++) {
                    int x = Integer.parseInt(S.substring(i, i + 1));
                    // Update the dp array for the next character based on the current character being the digit x
                    dp[i + 1][(k * 10 + x) % 13] += dp[i][k];
                    // Ensure the value stays within the bounds of MOD
                    dp[i + 1][(k * 10 + x) % 13] %= MOD;
                }
            }
        }
        
        // Output the number of ways to form a number that gives a remainder of 5 when divided by 13 using all characters of S
        System.out.println(dp[S.length()][5]);
    }
}
