
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Initializes the scanner and starts the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String src = scanner.nextLine(); // Reads the source string from the user
        String pat = scanner.nextLine(); // Reads the pattern string from the user
        boolean isMatch = regexBU(src, pat); // Calls the regexBU method to check if the source string matches the pattern
        System.out.println("Does the source string match the pattern? " + isMatch); // Prints the result to the console
        scanner.close(); // Closes the scanner
    }

    // The main logic for the regexBU algorithm
    public static boolean regexBU(String src, String pat) {
        boolean[][] strg = new boolean[src.length() + 1][pat.length() + 1]; // Initializes a 2D boolean array for storing the results of subproblems

        // Base case: If the source string and the pattern are both empty, they match
        strg[src.length()][pat.length()] = true;

        // Loops through each character in the source string (from right to left)
        for (int row = src.length(); row >= 0; row--) {
            for (int col = pat.length() - 1; col >= 0; col--) {
                // If we've reached the end of the source string, handle the wildcard character (*) differently
                if (row == src.length()) {
                    if (pat.charAt(col) == '*') {
                        strg[row][col] = strg[row][col + 1]; // If the pattern's current character is a wildcard, the current subproblem is true if the next one is
                    } else {
                        strg[row][col] = false; // If the pattern's current character is not a wildcard, the current subproblem is false
                    }
                } else {
                    // Compares the characters at the current positions in the source and pattern strings
                    char chs = src.charAt(row);
                    char chp = pat.charAt(col);

                    // Determines the answer based on the comparison result and the wildcard character (*)
                    boolean ans;
                    if (chs == chp || chp == '?') {
                        ans = strg[row + 1][col + 1]; // If the characters match or the pattern's current character is a question mark, the current subproblem is true if the next one is
                    } else if (chp == '*') {
                        boolean blank = strg[row][col + 1]; // If the pattern's current character is a wildcard, the current subproblem is true if the next one in the pattern is or if the current character in the source string matches the next character in the pattern
                        boolean multiple = strg[row + 1][col]; // If the pattern's current character is a wildcard, the current subproblem is true if the previous one in the source string and the current one match the pattern's current character and the next one
                        ans = blank || multiple;
                    } else {
                        ans = false; // If the characters don't match and there's no wildcard character, the current subproblem is false
                    }
                    strg[row][col] = ans; // Stores the result of the current subproblem in the 2D array
                }
            }
        }

        // Returns the result of the first subproblem (source string is empty and pattern string is empty)
        return strg[0][0];
    }
}