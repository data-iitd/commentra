package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = sc.nextInt();
        int[][] mm = new int[n][2];
        for (int i = 0; i < n; i++) {
            mm[i][0] = sc.nextInt();
            mm[i][1] = sc.nextInt();
        }

        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k <= j - 1; k++) {
                    int d = dp[i][k] + dp[k + 1][j] + mm[i - 1][0] * mm[k][0] * mm[j][1];
                    if (dp[i][j] == 0 || dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        bw.write(String.valueOf(dp[1][n]));
        bw.newLine();

        bw.close();
        sc.close();
    }
}

