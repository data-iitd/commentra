
import java.io.*;
import java.util.*;

public class atcoder_ABC135_D{
    static final int MOD = 100000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] s = br.readLine().toCharArray();
        int n = s.length;

        if (n == 1) {
            if (s[0] == '5' || s[0] == '?') {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
            return;
        }

        int[][] dp = new int[n][13];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i]!= '?') {
                    dp[i][s[i] - '0']++;
                } else {
                    for (int j = 0; j < 10; j++) {
                        dp[i][j]++;
                    }
                }
            } else {
                if (s[i]!= '?') {
                    for (int j = 0; j < 13; j++) {
                        dp[i][(j * 10 + s[i] - '0') % 13] += dp[i - 1][j];
                    }
                } else {
                    for (int j = 0; j < 10; j++) {
                        for (int k = 0; k < 13; k++) {
                            dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        }
                    }
                }
                for (int j = 0; j < 13; j++) {
                    dp[i][j] %= MOD;
                }
            }
        }

        System.out.println(dp[n - 1][5]);
    }
}

Translate the above Java code to C++ and end with comment "