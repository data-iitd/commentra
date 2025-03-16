import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to calculate the minimal number of partitions for a given string
    public static int minimalPartitions(String word) {
        int len = word.length(); // Get the length of the input string
        int[] minCuts = new int[len]; // Array to store the minimum cuts for each substring
        boolean[][] isPalindrome = new boolean[len][len]; // 2D array to check if substrings are palindromes

        // Initialize the isPalindrome array for single character substrings
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true; // A single character is always a palindrome
        }

        // Fill the isPalindrome table for substrings of length 2 and greater
        for (int subLen = 2; subLen <= len; subLen++) {
            for (int i = 0; i < len - subLen + 1; i++) {
                int j = i + subLen - 1; // Ending index of the substring
                // Check if the substring from i to j is a palindrome
                if (subLen == 2) {
                    isPalindrome[i][j] = (word.charAt(i) == word.charAt(j)); // Two characters case
                } else {
                    isPalindrome[i][j] = (word.charAt(i) == word.charAt(j)) && isPalindrome[i + 1][j - 1]; // General case
                }
            }
        }

        // Calculate the minimum cuts required for each substring
        for (int i = 0; i < len; i++) {
            if (isPalindrome[0][i]) {
                minCuts[i] = 0; // No cuts needed if the whole substring is a palindrome
            } else {
                minCuts[i] = Integer.MAX_VALUE; // Initialize to maximum value
                // Check for possible cuts
                for (int j = 0; j < i; j++) {
                    // If the substring from j+1 to i is a palindrome
                    if (isPalindrome[j + 1][i] && 1 + minCuts[j] < minCuts[i]) {
                        minCuts[i] = 1 + minCuts[j]; // Update the minimum cuts
                    }
                }
            }
        }
        return minCuts[len - 1]; // Return the minimum cuts for the entire string
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner to read input
        String inputString = scanner.nextLine(); // Read the input string
        int result = minimalPartitions(inputString); // Calculate the minimum partitions
        System.out.println("Minimum number of partitions required: " + result); // Output the result
    }
}
