
import java.util.Scanner;

public class s762058481{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] dp = new int[n];
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
        }
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (i == 1) {
                dp[1] = Math.abs(h[1] - h[0]);
            } else {
                dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]), dp[i - 2] + Math.abs(h[i] - h[i - 2]));
            }
        }
        System.out.println(dp[n - 1]);
    }
}
