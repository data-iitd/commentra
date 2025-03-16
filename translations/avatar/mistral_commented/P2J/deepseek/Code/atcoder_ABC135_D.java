import java.util.*;

public class Main {
    static int mod = (int) (1e9 + 7);

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
                if (S.charAt(i) != '?') {
                    dp[i][Integer.parseInt(String.valueOf(S.charAt(i)))]++;
                } else {
                    for (int j = 0; j < 10; j++) {
                        dp[i][j]++;
                    }
                }
            } else {
                if (S.charAt(i) != '?') {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + Integer.parseInt(String.valueOf(S.charAt(i)))) % 13] += dp[i - 1][k];
                        dp[i][(k * 10 + Integer.parseInt(String.valueOf(S.charAt(i)))) % 13] %= mod;
                    }
                } else {
                    for (int j = 0; j < 10; j++) {
                        for (int k = 0; k < 13; k++) {
                            dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                            dp[i][(k * 10 + j) % 13] %= mod;
                        }
                    }
                }
            }
        }

        System.out.println(dp[n - 1][5]);
    }
}
