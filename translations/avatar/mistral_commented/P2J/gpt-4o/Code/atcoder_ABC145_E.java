import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static final int TIME = 0;
    static final int VAL = 1;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Read N and T
        int N = input.nextInt();
        int T = input.nextInt();

        // Initialize time_value array
        int[][] time_value = new int[N + 1][2];
        for (int i = 1; i <= N; i++) {
            time_value[i][TIME] = input.nextInt();
            time_value[i][VAL] = input.nextInt();
        }

        // Sort time_value based on their VAL (end time)
        Arrays.sort(time_value, 1, N + 1, Comparator.comparingInt(a -> a[VAL]));

        // Initialize dp matrix
        int[][] dp = new int[N + 1][T];
        for (int t = 0; t < T; t++) {
            dp[0][t] = 0;
        }
        dp[0][0] = 0;
        for (int n = 1; n <= N; n++) {
            dp[n][0] = 0;
        }

        // Fill dp matrix
        for (int n = 1; n <= N; n++) {
            for (int t = 1; t < T; t++) {
                // If current activity's start time is greater than t, then we cannot include it in the solution
                if (time_value[n][TIME] > t) {
                    dp[n][t] = dp[n - 1][t];
                } else {
                    // If current activity's start time is less than or equal to t, then we can include it in the solution
                    dp[n][t] = Math.max(dp[n - 1][t], time_value[n][VAL] + dp[n - 1][t - time_value[n][TIME]]);
                }
            }
        }

        // Calculate maximum value that can be obtained
        int val_acum = time_value[N][VAL];
        int t = T - 1;
        int max_val = val_acum + dp[N - 1][t];

        // Calculate maximum value by considering all activities
        for (int n = N - 1; n > 0; n--) {
            val_acum += time_value[n][VAL];
            t -= time_value[n + 1][TIME];
            if (t < 0) {
                break;
            } else {
                max_val = Math.max(max_val, val_acum + dp[n - 1][t]);
            }
        }

        // Print the maximum value
        System.out.println(max_val);
    }
}
// <END-OF-CODE>
