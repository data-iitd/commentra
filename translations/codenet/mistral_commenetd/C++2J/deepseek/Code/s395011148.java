import java.util.Scanner;

public class Main {
    static long N;
    static long[] A = new long[1 << 18];
    static long[][][] dp = new long[1 << 18][2][20];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextLong();
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        // Initialize dp array with minimum values
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < 20; j++) {
                dp[i][0][j] = -(1L << 60);
                dp[i][1][j] = -(1L << 60);
            }
        }

        // Base case: dp[0][0][10] = 0
        dp[0][0][10] = 0;

        // Iterate through all the elements of the array A
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

        // Calculate the value of T1 and T2
        long V = 10L + (N / 2) - (N - (N / 2));
        long T1 = dp[N][0][V];
        long T2 = dp[N][1][V];

        // Print the maximum value of T1 and T2
        System.out.println(Math.max(T1, T2));
    }
}
