import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] dp = new int[n];
		int[] h = new int[n];
		for (int i = 0; i < n; ++i)
			dp[i] = 10000;

		for (int i = 0; i < n; ++i)
			h[i] = sc.nextInt();

		dp[0] = 0;
		for (int i = 1; i < n; ++i) {
			if (i == 1) dp[1] = Math.abs(h[1] - h[0]);
			else dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]), dp[i - 2] + Math.abs(h[i] - h[i - 2]));
		}
		System.out.println(dp[n - 1]);
	}
}

