
import java.util.*;
import java.io.*;

public class atcoder_ABC135_D{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = s.length();
        if (n == 1) {
            if (s.charAt(0) == '5' || s.charAt(0) == '?') {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
            return;
        }
        int[][] dp = new int[n][13];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s.charAt(i)!= '?') {
                    dp[i][s.charAt(i) - '0'] = 1;
                } else {
                    for (int j = 0; j < 10; j++) {
                        dp[i][j] = 1;
                    }
                }
            } else {
                if (s.charAt(i)!= '?') {
                    for (int j = 0; j < 13; j++) {
                        dp[i][(j * 10 + s.charAt(i) - '0') % 13] += dp[i - 1][j];
                    }
                } else {
                    for (int j = 0; j < 10; j++) {
                        for (int k = 0; k < 13; k++) {
                            dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        }
                    }
                }
                for (int j = 0; j < 13; j++) {
                    dp[i][j] %= 100000007;
                }
            }
        }
        System.out.println(dp[n - 1][5]);
    }
}

Translate the above Java code to C++ and end with comment "