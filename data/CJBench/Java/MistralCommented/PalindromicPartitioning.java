
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static int minimalPartitions(String word) {
        int len = word.length(); // length of the given word
        int[] minCuts = new int[len]; // array to store the minimum number of cuts required for each substring

        boolean[][] isPalindrome = new boolean[len][len]; // 2D boolean array to check if a substring is a palindrome or not

        // Initialize the first row and column of the isPalindrome matrix with true values
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
        }

        // Fill the rest of the isPalindrome matrix
        for (int subLen = 2; subLen <= len; subLen++) {
            for (int i = 0; i < len - subLen + 1; i++) {
                int j = i + subLen - 1;

                // Base case for substring of length 2
                if (subLen == 2) {
                    isPalindrome[i][j] = (word.charAt(i) == word.charAt(j));
                } else {
                    // Recursive case for substrings of length greater than 2
                    isPalindrome[i][j] = (word.charAt(i) == word.charAt(j)) && isPalindrome[i + 1][j - 1];
                }
            }
        }

        // Calculate the minimum number of cuts required for each substring
        for (int i = 0; i < len; i++) {
            if (isPalindrome[0][i]) {
                minCuts[i] = 0; // If the substring is a palindrome, no cuts are required
            } else {
                minCuts[i] = Integer.MAX_VALUE; // If the substring is not a palindrome, initialize the minimum number of cuts as maximum value
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i] && 1 + minCuts[j] < minCuts[i]) {
                        minCuts[i] = 1 + minCuts[j]; // Update the minimum number of cuts if a palindrome substring is found before the current substring
                    }
                }
            }
        }

        // Return the minimum number of cuts required for the entire word
        return minCuts[len - 1];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console
        String inputString = scanner.nextLine(); // Read a line of input from the console
        int result = minimalPartitions(inputString); // Calculate the minimum number of partitions required for the input string
        System.out.println("Minimum number of partitions required: " + result); // Print the result to the console
    }
}