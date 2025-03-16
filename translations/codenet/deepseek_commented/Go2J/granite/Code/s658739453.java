

import java.util.Scanner;

public class s658739453{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int p = scanner.nextInt();
        long[] mdans = new long[p];
        for (int i = 0; i < p; i++) {
            mdans[i] = scanner.nextLong();
        }
        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (Arrays.binarySearch(mdans, i) >= 0) {
                continue;
            }
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        System.out.println(dp[n]);
    }
}

