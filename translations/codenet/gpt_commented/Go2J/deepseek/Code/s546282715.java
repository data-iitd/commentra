import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.next());
        int m = Integer.parseInt(scanner.next());

        boolean[] blocked = new boolean[n + 1];
        for (int i = 0; i < m; i++) {
            blocked[Integer.parseInt(scanner.next())] = true;
        }

        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
                if (!blocked[i + ii]) {
                    dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007;
                }
            }
        }

        System.out.println(dp[n]);
    }
}
