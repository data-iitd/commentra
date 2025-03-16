import java.util.Scanner;

public class Sashimi {
    /* constant */
    static final int MAX_N = 4000;
    static final long LINF = 1L << 60;

    /* global variables */
    static long[] wis = new long[MAX_N];
    static long[] wsums = new long[MAX_N + 1];
    static long[][] dp = new long[MAX_N][MAX_N + 1];
    static int[][] ks = new int[MAX_N][MAX_N + 1];

    /* main */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        wsums[0] = 0;
        for (int i = 0; i < n; i++) {
            wis[i] = scanner.nextLong();
            wsums[i + 1] = wsums[i] + wis[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = LINF;
                ks[i][j] = -1;
            }
            dp[i][i + 1] = 0;
            ks[i][i + 1] = i;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 0, j = l; j <= n; i++, j++) {
                long mind = LINF;
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
        }

        System.out.println(dp[0][n]);
        scanner.close();
    }
}

/* <END-OF-CODE> */
