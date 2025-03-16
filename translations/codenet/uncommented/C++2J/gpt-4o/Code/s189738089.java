import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int INF = 1 << 30;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // input
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt();
        }

        // dp
        int[] dp = new int[101000];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= K; j++) {
                if (i + j < N) {
                    dp[i + j] = Math.min(dp[i + j], dp[i] + Math.abs(h[i] - h[i + j]));
                }
            }
        }

        // output
        System.out.println(dp[N - 1]);
        scanner.close();
    }
}
// <END-OF-CODE>
