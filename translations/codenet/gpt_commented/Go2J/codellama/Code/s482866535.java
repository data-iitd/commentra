
package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int[] mm = new int[n+1];
        int[][] dp = new int[n+1][n+1];

        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            mm[i] = Integer.parseInt(tokenizer.nextToken());
            mm[i+1] = Integer.parseInt(tokenizer.nextToken());
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n-l+1; i++) {
                int j = i + l - 1;
                for (int k = i; k <= j-1; k++) {
                    int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
                    if (dp[i][j] == 0 || dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        System.out.println(dp[1][n]);
    }
}

