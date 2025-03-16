import java.util.Scanner;

public class Main {
    static final int INF = 1 << 30;

    public static void main(String[] args) {
        // Initialization of the dp array
        int[] dp = new int[101000];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;

        // Input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt();
        }

        // Dynamic Programming Loop
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= K; j++) {
                if (i + j < N) {
                    dp[i + j] = Math.min(dp[i + j], dp[i] + Math.abs(h[i] - h[i + j]));
                }
            }
        }

        // Output
        System.out.println(dp[N - 1]);
        scanner.close();
    }
}
// <END-OF-CODE>
