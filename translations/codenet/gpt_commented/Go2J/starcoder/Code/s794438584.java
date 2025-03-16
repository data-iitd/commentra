package main;

import java.util.Scanner;

public class Knapsack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of items and the maximum weight from standard input.
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Initialize slices to hold the weights and values of the items.
        int[] values = new int[N];
        int[] weights = new int[N];

        // Read the weights and values of each item from standard input.
        for (int i = 0; i < N; i++) {
            values[i] = sc.nextInt();
            weights[i] = sc.nextInt();
        }

        // Initialize a 2D slice for dynamic programming table.
        int[][] dp = new int[N+1][M+1];

        // Fill the dynamic programming table.
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                // If the current item is not included, carry forward the previous value.
                dp[i][j] = dp[i-1][j];

                // If the current item's weight is less than or equal to the current capacity.
                if (j >= weights[i-1]) {
                    // Calculate the maximum value by including the current item.
                    dp[i][j] = Math.max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]);
                }
            }
        }

        // Output the maximum value that can be obtained with the given weight limit.
        System.out.println(dp[N][M]);
    }
}

