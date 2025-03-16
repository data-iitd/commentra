//--- pB ---//
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main (String[] args) throws java.lang.Exception {
        // Create a new instance of the Solution class to start the program
        new Solution();
    }
}

class Solution {
    Scanner scanner;

    // Constructor for the Solution class
    public Solution() {
        // Initialize the scanner to read input from the console
        scanner = new Scanner(System.in);

        // Continuously read input until there are no more lines
        while (scanner.hasNext()) {
            run_case(); // Process each case
        }
    }

    private void run_case() {
        // Read a line of input
        String line = scanner.nextLine();
        
        // Parse the first two integers from the input line
        int N = Integer.parseInt(line.split("\\s+")[0]);
        int K = Integer.parseInt(line.split("\\s+")[1]);

        int len = 0; // Initialize length counter

        // Calculate the number of times N can be divided by K until it becomes 0
        while (N > 0) {
            N /= K; // Divide N by K
            len++; // Increment the length counter
        }

        // Output the calculated length
        System.out.println(len);
        return; // Exit the method
    }

    // Helper method to convert a space-separated string to an integer array
    private int[] strToIntArray(String str) {
        String[] vals = str.split("\\s+"); // Split the string by whitespace
        int sz = vals.length; // Get the size of the resulting array
        int[] res = new int[sz]; // Create an integer array of the same size
        
        // Convert each string value to an integer
        for (int i = 0; i < sz; i++) {
            res[i] = Integer.parseInt(vals[i]);
        }
        return res; // Return the integer array
    }
}

class LCS {
    int[][] dp; // 2D array to store lengths of longest common subsequence

    // Method to compute the length of the longest common subsequence (LCS) of two strings
    public int lcs(String A, String B) {
        int sz_a = A.length(), sz_b = B.length(); // Get lengths of both strings
        dp = new int[sz_a + 1][sz_b + 1]; // Initialize the dp array

        // Initialize the first row and first column of the dp array to 0
        for (int i = 0; i <= sz_a; i++) dp[i][0] = 0;
        for (int j = 0; j <= sz_b; j++) dp[0][j] = 0;

        // Fill the dp array using dynamic programming approach
        for (int i = 1; i <= sz_a; i++) {
            for (int j = 1; j <= sz_b; j++) {
                // If characters match, increment the count from the previous indices
                if (A.charAt(i - 1) == B.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // Otherwise, take the maximum value from the left or above
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Return the length of the longest common subsequence
        return dp[sz_a][sz_b];
    }

    // Method to reconstruct and return the longest common subsequence (LCS) string
    public String getLCS(String X, String Y) {
        int m = X.length();
        int n = Y.length();
        // Get the length of LCS from the dp array
        int index = dp[m][n];
        int temp = index; // Store the length for later use

        // Create a character array to store the LCS string
        char[] lcs = new char[index + 1];
        lcs[index] = '\0'; // Set the terminating character

        // Start from the bottom-right corner of the dp array
        int i = m;
        int j = n;
        while (i > 0 && j > 0) {
            // If characters match, add to LCS and move diagonally
            if (X.charAt(i - 1) == Y.charAt(j - 1)) {
                lcs[index - 1] = X.charAt(i - 1); // Store the character in LCS
                i--; // Move up in the string X
                j--; // Move left in the string Y
                index--; // Decrease the index for LCS
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // Move up if the value above is greater
                i--;
            } else {
                // Move left if the value to the left is greater
                j--;
            }
        }

        // Return the LCS as a string
        return String.valueOf(lcs).substring(0, temp + 2);
    }
}
