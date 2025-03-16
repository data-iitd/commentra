
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read input
        int N = sc.nextInt();
        int T = sc.nextInt();
        int[][] time_value = new int[N+1][2];
        for (int i = 1; i <= N; i++) {
            time_value[i][0] = sc.nextInt();
            time_value[i][1] = sc.nextInt();
        }

        // Sort time_value based on their VAL (end time)
        Arrays.sort(time_value, (a, b) -> a[1] - b[1]);

        // Initialize dp matrix
        int[][] dp = new int[N+1][T+1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= T; j++) {
                dp[i][j] = -1;
            }
        }

        // Initialize first row and column of dp matrix
        for (int t = 0; t <= T; t++) {
            dp[0][t] = 0;
        }
        dp[0][0] = 0;
        for (int n = 1; n <= N; n++) {
            dp[n][0] = 0;
        }

        // Fill dp matrix
        for (int n = 1; n <= N; n++) {
            for (int t = 1; t <= T; t++) {
                // If current activity's start time is greater than t, then we cannot include it in the solution
                if (time_value[n][0] > t) {
                    dp[n][t] = dp[n-1][t];
                }
                // If current activity's start time is less than or equal to t, then we can include it in the solution
                else {
                    dp[n][t] = Math.max(dp[n-1][t], time_value[n][1] + dp[n-1][t-time_value[n][0]]);
                }
            }
        }

        // Calculate maximum value that can be obtained
        int val_acum = time_value[N][1];
        int t = T - 1;
        int max_val = val_acum + dp[N-1][t];

        // Calculate maximum value by considering all activities
        for (int n = N-1; n > 0; n--) {
            val_acum += time_value[n][1];
            t -= time_value[n+1][0];
            if (t < 0) {
                break;
            } else {
                max_val = Math.max(max_val, val_acum + dp[n-1][t]);
            }
        }

        // Print the maximum value
        System.out.println(max_val);
    }
}

