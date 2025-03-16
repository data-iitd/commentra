
import java.util.Scanner;

public class s257493016{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int N = scanner.nextInt();
        int[] dp = new int[H + 10001];
        int amax = 0;
        for (int i = 0; i < N; i++) {
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            if (A >= amax) {
                amax = A;
            }
            dp[A] = Math.min(dp[A], B);
            for (int j = A + 1; j <= H + amax + 1; j++) {
                dp[j] = Math.min(dp[j], dp[j - A] + B);
            }
        }
        int minCost = Integer.MAX_VALUE;
        for (int i = H; i <= H + amax; i++) {
            minCost = Math.min(minCost, dp[i]);
        }
        System.out.println(minCost);
    }
}
