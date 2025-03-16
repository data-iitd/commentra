import java.util.Scanner;

final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to compute the Longest Common Subsequence (LCS) of two strings
    public static String getLCS(String str1, String str2) {
        // Check for null input strings
        if (str1 == null || str2 == null) {
            return null;
        }
        // Return an empty string if either string is empty
        if (str1.length() == 0 || str2.length() == 0) {
            return "";
        }

        // Split the strings into character arrays
        String[] arr1 = str1.split("");
        String[] arr2 = str2.split("");

        // Create a matrix to store lengths of longest common subsequence
        int[][] lcsMatrix = new int[arr1.length + 1][arr2.length + 1];

        // Initialize the first column of the matrix to 0
        for (int i = 0; i < arr1.length + 1; i++) {
            lcsMatrix[i][0] = 0;
        }

        // Initialize the first row of the matrix to 0
        for (int j = 1; j < arr2.length + 1; j++) {
            lcsMatrix[0][j] = 0;
        }

        // Fill the LCS matrix using dynamic programming
        for (int i = 1; i < arr1.length + 1; i++) {
            for (int j = 1; j < arr2.length + 1; j++) {
                // If characters match, increment the value from the diagonal cell
                if (arr1[i - 1].equals(arr2[j - 1])) {
                    lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1;
                } else {
                    // Otherwise, take the maximum value from the left or above cell
                    lcsMatrix[i][j] = Math.max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1]);
                }
            }
        }

        // Retrieve the longest common subsequence from the matrix
        return lcsString(str1, str2, lcsMatrix);
    }

    // Method to construct the LCS string from the LCS matrix
    public static String lcsString(String str1, String str2, int[][] lcsMatrix) {
        StringBuilder lcs = new StringBuilder();
        int i = str1.length();
        int j = str2.length();

        // Backtrack through the matrix to find the LCS characters
        while (i > 0 && j > 0) {
            // If characters match, add to the LCS and move diagonally
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                lcs.append(str1.charAt(i - 1));
                i--;
                j--;
            } else if (lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]) {
                // Move up if the value above is greater
                i--;
            } else {
                // Move left if the value to the left is greater
                j--;
            }
        }

        // Reverse the LCS string since we constructed it backwards
        return lcs.reverse().toString();
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read two strings from the user
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();
        
        // Compute the LCS of the two strings
        String lcs = getLCS(str1, str2);
        
        // Output the result
        System.out.println("The Longest Common Subsequence is: " + lcs);
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
