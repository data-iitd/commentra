import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to calculate the minimum edit distance between two words
    public static int minDistance(String word1, String word2) {
        // Get the lengths of both words
        int len1 = word1.length();
        int len2 = word2.length();
        
        // Create a 2D array to store the edit distances
        int[][] dp = new int[len1 + 1][len2 + 1];

        // Initialize the first column of the dp array
        // The distance from an empty word to word1[0..i] is i (deleting all characters)
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }

        // Initialize the first row of the dp array
        // The distance from an empty word to word2[0..j] is j (inserting all characters)
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }

        // Fill the dp array using the edit distance dynamic programming approach
        for (int i = 0; i < len1; i++) {
            char c1 = word1.charAt(i);
            for (int j = 0; j < len2; j++) {
                char c2 = word2.charAt(j);
                
                // If the characters match, no new edit is needed
                if (c1 == c2) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    // Calculate costs for replace, insert, and delete operations
                    int replace = dp[i][j] + 1; // Cost of replacing a character
                    int insert = dp[i][j + 1] + 1; // Cost of inserting a character
                    int delete = dp[i + 1][j] + 1; // Cost of deleting a character
                    
                    // Take the minimum of the three operations
                    dp[i + 1][j + 1] = Math.min(replace, Math.min(insert, delete));
                }
            }
        }
        
        // Return the minimum edit distance found in the last cell of the dp array
        return dp[len1][len2];
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the first word from the user
        String word1 = scanner.nextLine();
        
        // Read the second word from the user
        String word2 = scanner.nextLine();
        
        // Calculate the minimum edit distance between the two words
        int result = minDistance(word1, word2);
        
        // Output the result to the console
        System.out.println("The minimum edit distance is: " + result);
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
