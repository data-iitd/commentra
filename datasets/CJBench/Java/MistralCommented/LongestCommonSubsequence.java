
import java.util.Scanner;
final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }
    
    public static String getLCS(String str1, String str2) {
        if (str1 == null || str2 == null) {
            // Return null if either string is null
            return null;
        }
        if (str1.length() == 0 || str2.length() == 0) {
            // Return empty string if either string is empty
            return "";
        }
        
        String[] arr1 = str1.split("");
        String[] arr2 = str2.split("");
        
        // Initialize a 2D matrix to store the lengths of the longest common subsequences of substrings
        int[][] lcsMatrix = new int[arr1.length + 1][arr2.length + 1];
        
        for (int i = 0; i < arr1.length + 1; i++) {
            lcsMatrix[i][0] = 0;
            // Initialize the first column of the matrix with zeros
        }
        
        for (int j = 1; j < arr2.length + 1; j++) {
            lcsMatrix[0][j] = 0;
            // Initialize the first row of the matrix with zeros
        }
        
        for (int i = 1; i < arr1.length + 1; i++) {
            for (int j = 1; j < arr2.length + 1; j++) {
                if (arr1[i - 1].equals(arr2[j - 1])) {
                    // If the characters at the current positions are the same,
                    // add 1 to the length of the longest common subsequence of the substrings
                    lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1;
                } else {
                    // If the characters are different, take the maximum length of the longest common subsequences of the substrings that don't include the current characters
                    lcsMatrix[i][j] = Math.max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1]);
                }
            }
        }
        
        // Recursively build the longest common subsequence string from the matrix
        return lcsString(str1, str2, lcsMatrix);
    }
    
    public static String lcsString(String str1, String str2, int[][] lcsMatrix) {
        StringBuilder lcs = new StringBuilder();
        int i = str1.length();
        int j = str2.length();
        
        // While there are still characters to process in both strings
        while (i > 0 && j > 0) {
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                // If the characters are the same, add them to the result string and move to the next character in both strings
                lcs.append(str1.charAt(i - 1));
                i--;
                j--;
            } else if (lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]) {
                // If the length of the longest common subsequence of the substring that doesn't include the current character from str1 is greater than the length of the longest common subsequence of the substring that doesn't include the current character from str2,
                // move to the next character in str1
                i--;
            } else {
                // Otherwise, move to the next character in str2
                j--;
            }
        }
        
        // Reverse the result string and return it
        return lcs.reverse().toString();
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();
        
        // Call the getLCS method to find the longest common subsequence and print the result
        String lcs = getLCS(str1, str2);
        System.out.println("The Longest Common Subsequence is: " + lcs);
        
        scanner.close();
    }
}