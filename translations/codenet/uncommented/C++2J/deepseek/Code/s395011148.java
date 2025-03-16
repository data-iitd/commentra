import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long[] A = new long[1 << 18];
        long[][][] dp = new long[1 << 18][2][20];

        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < 20; j++) {
                dp[i][0][j] = -(1L << 60);
                dp[i][1][j] = -(1L << 60);
            }
        }
        dp[0][0][10] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 6; j <= 14; j++) {
                if (dp[i - 1][0][j] != (1L << 60)) {
                    dp[i][1][j + 1] = Math.max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
                    dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][0][j]);
                }
                if (dp[i - 1][1][j] != (1L << 60)) {
                    dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][1][j]);
                }
            }
        }

        long V = 10L + (N / 2) - (N - (N / 2));
        long T1 = dp[N][0][(int) V];
        long T2 = dp[N][1][(int) V];
        System.out.println(Math.max(T1, T2));
    }
}
