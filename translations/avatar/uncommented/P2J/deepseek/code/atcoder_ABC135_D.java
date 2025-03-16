import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String S = input.readLine();
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
            Arrays.fill(dp[i], 0);
        }

        if (S.charAt(0) != '?') {
            dp[0][Integer.parseInt(S.charAt(0) + "")] += 1;
        } else {
            for (int j = 0; j < 10; j++) {
                dp[0][j] += 1;
            }
        }

        for (int i = 1; i < n; i++) {
            if (S.charAt(i) != '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + Integer.parseInt(S.charAt(i) + "")) % 13] += dp[i - 1][k];
                }
            } else {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
            }
            for (int k = 0; k < 13; k++) {
                dp[i][k] %= MOD;
            }
        }

        System.out.println(dp[n - 1][5]);
    }
}
