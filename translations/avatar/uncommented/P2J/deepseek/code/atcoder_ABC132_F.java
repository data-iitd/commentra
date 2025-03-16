import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final long mod = 1000000007;
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        ArrayList<Integer> coef = new ArrayList<>();
        
        for (int i = 1; i <= Math.sqrt(n); i++) {
            coef.add((n / i) - (n / (i + 1)));
        }
        
        for (int i = (int) Math.sqrt(n) + 1; i <= n; i++) {
            coef.add(1);
        }
        
        coef.sort((a, b) -> b - a);
        
        int nn = coef.size();
        long[][] dp = new long[k + 1][nn];
        dp[0][0] = 1;
        
        for (int i = 1; i <= k; i++) {
            long tmp = 0;
            for (int j = nn - 1; j >= 0; j--) {
                tmp += dp[i - 1][nn - 1 - j];
                tmp %= mod;
                dp[i][j] = coef.get(j) * tmp % mod;
            }
        }
        
        long result = 0;
        for (int j = 0; j < nn; j++) {
            result += dp[k][j];
            result %= mod;
        }
        
        System.out.println(result);
    }
}
