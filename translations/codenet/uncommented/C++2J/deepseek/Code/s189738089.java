public class Main {
    public static void main(String[] args) {
        int[] dp = new int[101000];
        final int INF = 1 << 30;
        java.util.Arrays.fill(dp, INF);
        dp[0] = 0;

        // input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt();
        }

        // dp
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= K; j++) {
                if (i + j < N) {
                    dp[i + j] = Math.min(dp[i + j], dp[i] + Math.abs(h[i] - h[i + j]));
                }
            }
        }

        // output
        System.out.println(dp[N - 1]);
    }
}
