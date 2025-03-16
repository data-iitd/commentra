import java.util.Scanner;

final class Main {
    private Main() {
    }

    // Method to find the Longest Common Subsequence (LCS) of two strings
    public static String getLCS(String str1, String str2) {
        // Check if either string is null or empty
        if (str1 == null || str2 == null) {
            return null;
        }
        if (str1.length() == 0 || str2.length() == 0) {
            return "";
        }

        // Split the strings into arrays of characters
        String[] arr1 = str1.split("");
        String[] arr2 = str2.split("");

        // Initialize a matrix to store LCS lengths
        int[][] lcsMatrix = new int[arr1.length + 1][arr2.length + 1];

        // Populate the matrix
        for (int i = 0; i < arr1.length + 1; i++) {
            lcsMatrix[i][0] = 0;
        }
        for (int j = 1; j < arr2.length + 1; j++) {
            lcsMatrix[0][j] = 0;
        }
        for (int i = 1; i < arr1.length + 1; i++) {
            for (int j = 1; j < arr2.length + 1; j++) {
                if (arr1[i - 1].equals(arr2[j - 1])) {
                    lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1;
                } else {
                    lcsMatrix[i][j] = Math.max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1]);
                }
            }
        }

        // Reconstruct the LCS string
        return lcsString(str1, str2, lcsMatrix);
    }

    // Helper method to build the LCS string from the matrix
    public static String lcsString(String str1, String str2, int[][] lcsMatrix) {
        StringBuilder lcs = new StringBuilder();
        int i = str1.length();
        int j = str2.length();
        while (i > 0 && j > 0) {
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                lcs.append(str1.charAt(i - 1));
                i--;
                j--;
            } else if (lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return lcs.reverse().toString();
    }

    // Main method to read input strings and print the LCS
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();
        String lcs = getLCS(str1, str2);
        System.out.println("The Longest Common Subsequence is: " + lcs);
        scanner.close();
    }
}
