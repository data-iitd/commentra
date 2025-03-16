
import java.util.Scanner;
public final class RegexMatching {
    private RegexMatching() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String src = scanner.nextLine();
        String pat = scanner.nextLine();
        boolean isMatch = regexBU(src, pat);
        System.out.println("Does the source string match the pattern? " + isMatch);
        scanner.close();
    }
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
