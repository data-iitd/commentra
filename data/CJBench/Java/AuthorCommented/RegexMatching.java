

import java.util.Scanner;

/**
 * Given a text and wildcard pattern implement a wildcard pattern matching
 * algorithm that finds if wildcard is matched with text. The matching should
 * cover the entire text ?-> matches single characters *-> match the sequence of
 * characters
 *
 * For calculation of Time and Space Complexity. Let N be length of src and M be length of pat
 *
 * Memoization vs Tabulation : https://www.geeksforgeeks.org/tabulation-vs-memoization/
 * Question Link : https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
 */
public final class RegexMatching {
    private RegexMatching() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the source string
        String src = scanner.nextLine();

        // Input the pattern string
        String pat = scanner.nextLine();

        // Choose a method (for demonstration, we're using regexBU)
        boolean isMatch = regexBU(src, pat);

        // Output the result
        System.out.println("Does the source string match the pattern? " + isMatch);

        scanner.close();
    }

    /**
     * Method 4: Determines if the given source string matches the given pattern using bottom-up dynamic programming (tabulation).
     * This method builds a solution iteratively by filling out a table, where each cell represents whether a substring
     * of the source string matches a substring of the pattern.
     *
     * Time Complexity: O(N * M), where N is the length of the source string and M is the length of the pattern.
     * Space Complexity: O(N * M) for the table used in the tabulation process.
     *
     * @param src The source string to be matched against the pattern.
     * @param pat The pattern containing wildcards ('*' matches a sequence of characters, '?' matches a single character).
     * @return {@code true} if the source string matches the pattern, {@code false} otherwise.
     */
    public static boolean regexBU(String src, String pat) {
        boolean[][] strg = new boolean[src.length() + 1][pat.length() + 1];
        strg[src.length()][pat.length()] = true;
        for (int row = src.length(); row >= 0; row--) {
            for (int col = pat.length() - 1; col >= 0; col--) {
                if (row == src.length()) {
                    if (pat.charAt(col) == '*') {
                        strg[row][col] = strg[row][col + 1];
                    } else {
                        strg[row][col] = false;
                    }
                } else {
                    char chs = src.charAt(row);
                    char chp = pat.charAt(col);

                    boolean ans;
                    if (chs == chp || chp == '?') {
                        ans = strg[row + 1][col + 1];
                    } else if (chp == '*') {
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
        return strg[0][0];
    }
}
