
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    // Calculates the minimum edit distance between two words using dynamic programming
    public static int minDistance(String word1, String word2) {
        int len1 = word1.length(); // Get the length of the first word
        int len2 = word2.length(); // Get the length of the second word
        int[][] dp = new int[len1 + 1][len2 + 1]; // Create a 2D array to store distances
        // Initialize the first row and column of the array
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i; // Initialize the distance for deleting characters
        }
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j; // Initialize the distance for inserting characters
        }
        // Fill the rest of the array using dynamic programming
        for (int i = 0; i < len1; i++) {
            char c1 = word1.charAt(i); // Get the i-th character of the first word
            for (int j = 0; j < len2; j++) {
                char c2 = word2.charAt(j); // Get the j-th character of the second word
                if (c1 == c2) {
                    dp[i + 1][j + 1] = dp[i][j]; // No operation needed if characters are the same
                } else {
                    int replace = dp[i][j] + 1; // Cost of replacing a character
                    int insert = dp[i][j + 1] + 1; // Cost of inserting a character
                    int delete = dp[i + 1][j] + 1; // Cost of deleting a character
                    dp[i + 1][j + 1] = Math.min(replace, Math.min(insert, delete)); // Choose the minimum cost operation
                }
            }
        }
        return dp[len1][len2]; // Return the minimum edit distance
    }
    // Main method to read input words and calculate their minimum edit distance
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String word1 = scanner.nextLine(); // Read the first word
        String word2 = scanner.nextLine(); // Read the second word
        int result = minDistance(word1, word2); // Calculate the minimum edit distance
        System.out.println("The minimum edit distance is: " + result); // Print the result
        scanner.close(); // Close the Scanner
    }
}