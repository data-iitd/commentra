import java.util.*;

public class Main {
    static int mod = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        int n = S.length();
        if (n == 1) {
            if (S.equals("5") || S.equals("?")) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
            return;
        }
        int[][] dp = new int[n][13];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (!S.substring(i, i + 1).equals("?")) {
                    dp[i][Integer.parseInt(S.substring(i, i + 1))]++;
                } else {
                    for (int j = 0; j < 10; j++) {
                        dp[i][j]++;
                    }
                }
            } else {
                if (!S.substring(i, i + 1).equals("?")) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + Integer.parseInt(S.substring(i, i + 1))) % 13] += dp[i - 1][k];
                    }
                } else {
                    for (int j = 0; j < 10; j++) {
                        for (int k = 0; k < 13; k++) {
                            dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        }
                    }
                }
                for (int k = 0; k < 13; k++) {
                    dp[i][k] %= mod;
                }
            }
        }
        System.out.println(dp[n - 1][5]);
    }
}
