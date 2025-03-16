import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int mod = 1000000007;
        int[] coef = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            coef[i] = (n / i) - (n / (i + 1));
        }
        int[][] dp = new int[k + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            int tmp = 0;
            for (int j = n - 1; j >= 0; j--) {
                tmp += dp[i - 1][j];
                tmp %= mod;
                dp[i][j] = coef[j] * tmp;
                dp[i][j] %= mod;
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += dp[k][i];
            ans %= mod;
        }
        System.out.println(ans);
    }
}

