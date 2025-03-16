import java.util.Scanner;

public class Main {
    static long[] key = new long[1005];
    static long[] cost = new long[1005];
    static long[][] dp = new long[(1 << 12) + 5][1005];
    static final long INF = 123456789012L;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();

        // Initialize dp array with INF
        for (int i = 0; i < (1 << 12) + 5; i++) {
            for (int j = 0; j < 1005; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;

        for (int i = 1; i <= m; i++) {
            long b = scanner.nextLong();
            cost[i] = scanner.nextLong();
            for (int j = 0; j < b; j++) {
                long c = scanner.nextLong();
                key[i] += (1 << (c - 1));
            }
        }

        for (long i = 0; i < (1 << n); i++) {
            for (int j = 0; j < m; j++) {
                dp[(int) i][j + 1] = Math.min(dp[(int) i][j], dp[(int) i][j + 1]);
                dp[(int) (i | key[j + 1])][j + 1] = Math.min(dp[(int) (i | key[j + 1])][j + 1], dp[(int) i][j] + cost[j + 1]);
            }
        }

        if (dp[(1 << n) - 1][m] == INF) {
            System.out.println(-1);
        } else {
            System.out.println(dp[(1 << n) - 1][m]);
        }

        scanner.close();
    }
}
// <END-OF-CODE>
