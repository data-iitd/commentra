import java.util.Scanner;

public class Main {
    static long N;
    static long[] A = new long[1 << 18];
    static long[][][] dp = new long[1 << 18][2][20];

    public static void main(String[] args) {
        // Step 1: Input Reading
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextLong();
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        // Step 2: Initialization
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < 20; j++) {
                dp[i][0][j] = Long.MIN_VALUE;
                dp[i][1][j] = Long.MIN_VALUE;
            }
        }
        dp[0][0][10] = 0;

        // Step 3: Dynamic Programming Transition
        for (int i = 1; i <= N; i++) {
            for (int j = 6; j <= 14; j++) {
                if (dp[i - 1][0][j] != Long.MIN_VALUE) {
                    dp[i][1][j + 1] = Math.max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
                    dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][0][j]);
                }
                if (dp[i - 1][1][j] != Long.MIN_VALUE) {
                    dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][1][j]);
                }
            }
        }

        // Step 4: Calculating the Result
        long V = 10 + (N / 2) - (N - (N / 2));
        long T1 = dp[(int) N][0][(int) V];
        long T2 = dp[(int) N][1][(int) V];
        System.out.println(Math.max(T1, T2));
    }
}
// <END-OF-CODE>
