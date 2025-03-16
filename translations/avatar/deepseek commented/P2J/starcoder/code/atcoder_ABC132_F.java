import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int mod = 1000000007;
        int[] coef = new int[n];
        int[] dp = new int[k + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            coef[i - 1] = (n / i) - (n / (i + 1));
        }
        for (int i = 1; i <= k; i++) {
            for (int j = n - 1; j >= 0; j--) {
                dp[i] = (dp[i] + dp[i - 1] * coef[j]) % mod;
            }
        }
        System.out.println(dp[k]);
    }
}

