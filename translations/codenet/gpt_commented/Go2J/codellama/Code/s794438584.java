
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        int[] values = new int[N];
        int[] weights = new int[N];

        for (int i = 0; i < N; i++) {
            weights[i] = scanner.nextInt();
            values[i] = scanner.nextInt();
        }

        int[][] dp = new int[N + 1][M + 1];

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j >= weights[i - 1]) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
                }
            }
        }

        System.out.println(dp[N][M]);
    }
}

