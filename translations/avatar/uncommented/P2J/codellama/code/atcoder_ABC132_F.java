import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int mod = 1000000007;
		int[] coef = new int[n];
		for (int i = 1; i <= n; i++) {
			coef[i] = (n / i) - (n / (i + 1));
		}
		int nn = coef.length;
		int[][] dp = new int[k + 1][nn];
		dp[0][0] = 1;
		for (int i = 1; i <= k; i++) {
			int tmp = 0;
			for (int j = nn - 1; j >= 0; j--) {
				tmp += dp[i - 1][(nn - 1) - j];
				tmp %= mod;
				dp[i][j] = coef[j] * tmp;
				dp[i][j] %= mod;
			}
		}
		int ans = 0;
		for (int i = 0; i < nn; i++) {
			ans += dp[k][i];
			ans %= mod;
		}
		System.out.println(ans);
	}
}

