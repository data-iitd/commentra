import java.util.*;
import java.io.*;

public class Main {
    static final int MOD = 1000000007;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine().trim();
        int n = S.length();

        if (n == 1) {
            if (S.equals("5") || S.equals("?")) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
            return;
        }

        dp = new int[n][13];

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (S.charAt(i) != '?') {
                    dp[i][Character.getNumericValue(S.charAt(i))]++;
                } else {
                    for (int j = 0; j < 10; j++) {
                        dp[i][j]++;
                    }
                }
            } else {
                if (S.charAt(i) != '?') {
                    int digit = Character.getNumericValue(S.charAt(i));
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + digit) % 13] = (dp[i][(k * 10 + digit) % 13] + dp[i - 1][k]) % MOD;
                    }
                } else {
                    for (int j = 0; j < 10; j++) {
                        for (int k = 0; k < 13; k++) {
                            dp[i][(k * 10 + j) % 13] = (dp[i][(k * 10 + j) % 13] + dp[i - 1][k]) % MOD;
                        }
                    }
                }
            }
        }

        System.out.println(dp[n - 1][5]);
    }
}
//<END-OF-CODE>
