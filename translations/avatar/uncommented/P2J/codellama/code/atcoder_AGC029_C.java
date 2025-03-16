import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[][] dp = new int[n][2];
        dp[0][0] = a[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] <= dp[i - 1][0]) {
                dp[i][0] = a[i];
                dp[i][1] = 0;
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i][1] == 0) {
                ans = Math.max(ans, dp[i][0]);
            }
        }
        System.out.println(ans);
    }
}

