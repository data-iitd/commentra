/*
 * 2415.java: Sashimi
 */

import java.io.*;
import java.util.*;

public class Main {
  /* constant */
  public static final int MAX_N = 4000; // Maximum number of items

  public static final long LINF = 1L << 60; // Define a large constant for initialization

  /* typedef */

  /* global variables */
  public static long[] wis = new long[MAX_N]; // Arrays for weights, prefix sums, and dynamic programming table
  public static long[] wsums = new long[MAX_N + 1];
  public static long[][] dp = new long[MAX_N][MAX_N + 1];
  public static int[][] ks = new int[MAX_N][MAX_N + 1];

  /* subroutines */

  /* main */
  public static void main(String[] args) {
    int n; // Number of items
    Scanner sc = new Scanner(System.in); // Create a Scanner object
    n = sc.nextInt(); // Read the number of items

    // Initialize prefix sums
    wsums[0] = 0; // Base case for prefix sums
    for (int i = 0; i < n; i++) {
      wis[i] = sc.nextLong(); // Read the weight of each item
      wsums[i + 1] = wsums[i] + wis[i]; // Calculate prefix sums
    }

    // Initialize the dynamic programming and split point tables
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) dp[i][j] = LINF, ks[i][j] = -1; // Set initial values to LINF and -1
      dp[i][i + 1] = 0; // Base case: no cost to combine a single item
      ks[i][i + 1] = i; // Base case: the split point is the item itself
    }

    // Fill the dynamic programming table
    for (int l = 2; l <= n; l++) // Iterate over lengths of segments
      for (int i = 0, j = l; j <= n; i++, j++) { // Iterate over starting index i and ending index j
        long mind = LINF; // Initialize minimum cost for this segment
        long wsum = wsums[j] - wsums[i]; // Calculate the total weight of the segment
        int mink = -1; // Initialize the best split point
        for (int k = ks[i][j - 1]; k <= ks[i + 1][j]; k++) { // Iterate over possible split points
          long d = dp[i][k] + dp[k][j] + wsum; // Calculate the cost of this split
          if (mind > d) mind = d, mink = k; // Update minimum cost and best split point
        }
        dp[i][j] = mind; // Store the minimum cost for segment (i, j)
        ks[i][j] = mink; // Store the best split point for segment (i, j)
      }

    // Output the minimum cost to combine all items
    System.out.println(dp[0][n]); // Print the result
  }
}

