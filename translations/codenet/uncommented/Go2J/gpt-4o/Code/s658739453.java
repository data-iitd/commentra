import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int p = scanner.nextInt();

        Map<Long, Long> mdans = new HashMap<>();
        for (int index = 0; index < p; index++) {
            long n1 = scanner.nextLong();
            mdans.put(n1, n1);
        }

        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        if (mdans.containsKey(1L)) {
            dp[1] = 0;
        }

        for (int i = 2; i <= n; i++) {
            if (mdans.containsKey((long) i)) {
                continue;
            }
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        System.out.println(dp[n]);
    }
}
// <END-OF-CODE>
