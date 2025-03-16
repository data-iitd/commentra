
import java.util.Scanner;

public class s658739453{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int p = scanner.nextInt();
        int[] mdans = new int[p];
        for (int i = 0; i < p; i++) {
            mdans[i] = scanner.nextInt();
        }
        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        if (mdans[0] == 1) {
            dp[1] = 0;
        }
        for (int i = 2; i <= n; i++) {
            if (mdans[i - 1] == i) {
                continue;
            }
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        System.out.println(dp[n]);
    }
}

