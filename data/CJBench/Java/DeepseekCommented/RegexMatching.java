import java.util.Scanner;
public final class Main {
    private Main() {
    }
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        // Read the source string from the user
        String src = scanner.nextLine();
        // Read the pattern from the user
        String pat = scanner.nextLine();
        // Call the regexBU method to check if the source string matches the pattern
        boolean isMatch = regexBU(src, pat);
        // Print the result
        System.out.println("Does the source string match the pattern? " + isMatch);
        // Close the Scanner to free up resources
        scanner.close();
    }
    // Method to check if the source string matches the pattern using dynamic programming
    public static boolean regexBU(String src, String pat) {
        // Create a 2D boolean array to store the results of subproblems
        boolean[][] strg = new boolean[src.length() + 1][pat.length() + 1];
        // Base case: an empty pattern matches an empty source string
        strg[src.length()][pat.length()] = true;
        // Fill the table in reverse order
        for (int row = src.length(); row >= 0; row--) {
            for (int col = pat.length() - 1; col >= 0; col--) {
                // If we are at the last row, handle the '*' character
                if (row == src.length()) {
                    if (pat.charAt(col) == '*') {
                        strg[row][col] = strg[row][col + 1];
                    } else {
                        strg[row][col] = false;
                    }
                } else {
                    // Get the current characters from the source and pattern
                    char chs = src.charAt(row);
                    char chp = pat.charAt(col);
                    boolean ans;
                    // Check if the characters match or if the pattern character is '?'
                    if (chs == chp || chp == '?') {
                        ans = strg[row + 1][col + 1];
                    } else if (chp == '*') {
                        // Handle the '*' character: it can match zero, one, or multiple characters
                        boolean blank = strg[row][col + 1];
                        boolean multiple = strg[row + 1][col];
                        ans = blank || multiple;
                    } else {
                        ans = false;
                    }
                    strg[row][col] = ans;
                }
            }
        }
        // The result for the entire source and pattern is stored in the top-left cell
        return strg[0][0];
    }
}
