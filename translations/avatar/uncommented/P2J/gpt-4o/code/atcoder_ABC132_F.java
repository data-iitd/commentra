import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int MOD = 1000000007;
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        long[] coef = new long[n + 1];
        for (int i = 1; i <= Math.sqrt(n); i++) {
            coef[i] = (n / i) - (n / (i + 1));
        }
        
        long total = 0;
        for (long c : coef) {
            total += c;
        }
        for (int i = 1; i <= n - total; i++) {
            coef[i] = 1;
        }
        
        long[] reversedCoef = new long[n + 1];
        for (int i = 0; i < coef.length; i++) {
            reversedCoef[coef.length - 1 - i] = coef[i];
        }
        
        int nn = reversedCoef.length;
        long[][] dp = new long[k + 1][nn];
        dp[0][0] = 1;
        
        for (int i = 1; i <= k; i++) {
            long tmp = 0;
            for (int j = nn - 1; j >= 0; j--) {
                tmp += dp[i - 1][nn - 1 - j];
                tmp %= MOD;
                dp[i][j] = (reversedCoef[j] * tmp) % MOD;
            }
        }
        
        long result = 0;
        for (long value : dp[k]) {
            result = (result + value) % MOD;
        }
        
        System.out.println(result);
        scanner.close();
    }
}
// <END-OF-CODE>
