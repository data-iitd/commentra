
import java.util.Scanner;
public final class EditDistance {
    private EditDistance() {
    }
    public static int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i < len1; i++) {
            char c1 = word1.charAt(i);
            for (int j = 0; j < len2; j++) {
                char c2 = word2.charAt(j);
                if (c1 == c2) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    int replace = dp[i][j] + 1;
                    int insert = dp[i][j + 1] + 1;
                    int delete = dp[i + 1][j] + 1;
                    dp[i + 1][j + 1] = Math.min(replace, Math.min(insert, delete));
                }
            }
        }
        return dp[len1][len2];
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word1 = scanner.nextLine();
        String word2 = scanner.nextLine();
        int result = minDistance(word1, word2);
        System.out.println("The minimum edit distance is: " + result);
        scanner.close();
    }
}
