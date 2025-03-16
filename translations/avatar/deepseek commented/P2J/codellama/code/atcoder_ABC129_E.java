import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String l = sc.next();
        int n = l.length();
        int mod = 1000000007;
        int[][] dp = new int[n + 1][2];
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            if (l.charAt(i) == '0') {
                dp[i + 1][0] = (dp[i][0] + dp[i][1] * 3) % mod;
                dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
            } else {
                dp[i + 1][0] = (dp[i][0] * 2 + dp[i][1] * 3) % mod;
                dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
            }
        }
        int result = (dp[n][0] + dp[n][1]) % mod;
        System.out.println(result);
    }
}
