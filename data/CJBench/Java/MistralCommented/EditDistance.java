
import java.util.Scanner;

// Final class to prevent instantiation
public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to find minimum edit distance between two strings
    public static int minDistance(String word1, String word2) {
        int len1 = word1.length(); // Length of first string
        int len2 = word2.length(); // Length of second string

        // 2D array to store the minimum edit distance between substrings
        int[][] dp = new int[len1 + 1][len2 + 1];

        // Initialize first row and column with their respective indices
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i; // i operations to delete all characters of word2
        }
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j; // j operations to delete all characters of word1
        }

        // Fill in the rest of the dp array
        for (int i = 0; i < len1; i++) {
            char c1 = word1.charAt(i); // Get character at current index of word1
            for (int j = 0; j < len2; j++) {
                char c2 = word2.charAt(j); // Get character at current index of word2
                if (c1 == c2) {
                    dp[i + 1][j + 1] = dp[i][j]; // No operation needed if characters are same
                } else {
                    int replace = dp[i][j] + 1; // Replace current character of word1 with current character of word2 and increment by 1
                    int insert = dp[i][j + 1] + 1; // Insert current character of word2 after current character of word1 and increment by 1
                    int delete = dp[i + 1][j] + 1; // Delete current character of word1 and increment by 1
                    dp[i + 1][j + 1] = Math.min(replace, Math.min(insert, delete)); // Choose the minimum of three operations
                }
            }
        }

        // Return the minimum edit distance between the two strings
        return dp[len1][len2];
    }

    // Main method to read input and print output
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String word1 = scanner.nextLine(); // Read the first string from the user
        String word2 = scanner.nextLine(); // Read the second string from the user
        int result = minDistance(word1, word2); // Find the minimum edit distance between the two strings
        System.out.println("The minimum edit distance is: " + result); // Print the minimum edit distance to the console
        scanner.close(); // Close the Scanner object
    }
}