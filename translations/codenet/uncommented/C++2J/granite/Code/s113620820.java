
/*
 * 2415.java: Sashimi
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s113620820{

  public static void main(String[] args) throws IOException {
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      int n = Integer.parseInt(br.readLine());
      String[] lines = br.readLine().split(" ");
      long[] wis = new long[n];
      for (int i = 0; i < n; i++)
        wis[i] = Long.parseLong(lines[i]);

      long[] wsums = new long[n + 1];
      for (int i = 0; i < n; i++)
        wsums[i + 1] = wsums[i] + wis[i];

      long[][] dp = new long[n][n + 1];
      int[][] ks = new int[n][n + 1];
      for (int i = 0; i < n; i++) {
        Arrays.fill(dp[i], Long.MAX_VALUE);
        dp[i][i + 1] = 0;
        ks[i][i + 1] = i;
      }

      for (int l = 2; l <= n; l++)
        for (int i = 0, j = l; j <= n; i++, j++) {
          long mind = Long.MAX_VALUE;
          long wsum = wsums[j] - wsums[i];
          int mink = -1;
          for (int k = ks[i][j - 1]; k <= ks[i + 1][j]; k++) {
            long d = dp[i][k] + dp[k][j] + wsum;
            if (mind > d) {
              mind = d;
              mink = k;
            }
          }
          dp[i][j] = mind;
          ks[i][j] = mink;
        }

      System.out.println(dp[0][n]);
    }
  }
}

