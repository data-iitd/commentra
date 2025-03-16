import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int T = sc.nextInt();
        int[][] time_value = new int[N + 1][2];
        for (int i = 1; i <= N; i++) {
            time_value[i][0] = sc.nextInt();
            time_value[i][1] = sc.nextInt();
        }
        Arrays.sort(time_value, (a, b) -> a[1] - b[1]);
        int[][] dp = new int[N + 1][T + 1];
        for (int i = 0; i <= N; i++) {
            Arrays.fill(dp[i], -1);
        }
        for (int i = 0; i <= T; i++) {
            dp[0][i] = 0;
        }
        for (int n = 1; n <= N; n++) {
            dp[n][0] = 0;
            for (int t = 1; t <= T; t++) {
                if (time_value[n][0] > t) {
                    dp[n][t] = dp[n - 1][t];
                } else {
                    dp[n][t] = Math.max(dp[n - 1][t], time_value[n][1] + dp[n - 1][t - time_value[n][0]]);
                }
            }
        }
        int val_acum = time_value[N][1];
        int t = T - 1;
        int max_val = val_acum + dp[N - 1][t];
        for (int n = N - 1; n >= 1; n--) {
            val_acum += time_value[n][1];
            t -= time_value[n + 1][0];
            if (t < 0) {
                break;
            } else {
                max_val = Math.max(max_val, val_acum + dp[n - 1][t]);
            }
        }
        System.out.println(max_val);
    }
}
