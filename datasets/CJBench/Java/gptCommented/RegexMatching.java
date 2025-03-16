import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the source string from the user
        String src = scanner.nextLine();
        
        // Read the pattern string from the user
        String pat = scanner.nextLine();
        
        // Call the regexBU method to check if the source matches the pattern
        boolean isMatch = regexBU(src, pat);
        
        // Output the result of the match
        System.out.println("Does the source string match the pattern? " + isMatch);
        
        // Close the scanner to free up resources
        scanner.close();
    }

    public static boolean regexBU(String src, String pat) {
        // Create a 2D boolean array to store the matching results
        boolean[][] strg = new boolean[src.length() + 1][pat.length() + 1];
        
        // Initialize the bottom-right cell to true (empty string matches empty pattern)
        strg[src.length()][pat.length()] = true;

        // Iterate over the source string in reverse order
        for (int row = src.length(); row >= 0; row--) {
            // Iterate over the pattern string in reverse order
            for (int col = pat.length() - 1; col >= 0; col--) {
                // Handle the case when the source string is empty
                if (row == src.length()) {
                    // If the current pattern character is '*', check if the next pattern character can match
                    if (pat.charAt(col) == '*') {
                        strg[row][col] = strg[row][col + 1];
                    } else {
                        // If not, set the current cell to false
                        strg[row][col] = false;
                    }
                } else {
                    // Get the current characters from the source and pattern
                    char chs = src.charAt(row);
                    char chp = pat.charAt(col);
                    boolean ans;

                    // Check for character match or '?' wildcard
                    if (chs == chp || chp == '?') {
                        ans = strg[row + 1][col + 1];
                    } 
                    // Handle '*' wildcard which can match zero or more characters
                    else if (chp == '*') {
                        boolean blank = strg[row][col + 1]; // Match '*' with zero characters
                        boolean multiple = strg[row + 1][col]; // Match '*' with one or more characters
                        ans = blank || multiple;
                    } else {
                        // If characters do not match, set answer to false
                        ans = false;
                    }
                    // Store the result in the current cell
                    strg[row][col] = ans;
                }
            }
        }
        // Return the result of the match for the entire source and pattern
        return strg[0][0];
    }
}
