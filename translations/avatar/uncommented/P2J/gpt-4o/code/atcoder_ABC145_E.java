import java.util.*;
import java.io.*;

public class Main {
    static final int TIME = 0;
    static final int VAL = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        // Initialize time_value array
        int[][] timeValue = new int[N + 1][2];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(input.readLine());
            timeValue[i][TIME] = Integer.parseInt(st.nextToken());
            timeValue[i][VAL] = Integer.parseInt(st.nextToken());
        }

        // Sort timeValue based on VAL
        Arrays.sort(timeValue, 1, N + 1, Comparator.comparingInt(a -> a[VAL]));

        // Initialize dp array
        int[][] dp = new int[N + 1][T];
        for (int t = 0; t < T; t++) {
            dp[0][t] = 0;
        }
        for (int n = 1; n <= N; n++) {
            dp[n][0] = 0;
            for (int t = 1; t < T; t++) {
                if (timeValue[n][TIME] > t) {
                    dp[n][t] = dp[n - 1][t];
                } else {
                    dp[n][t] = Math.max(dp[n - 1][t], timeValue[n][VAL] + dp[n - 1][t - timeValue[n][TIME]]);
                }
            }
        }

        // Calculate max_val
        int valAcum = timeValue[N][VAL];
        int t = T - 1;
        int maxVal = valAcum + dp[N - 1][t];
        for (int n = N - 1; n > 0; n--) {
            valAcum += timeValue[n][VAL];
            t -= timeValue[n + 1][TIME];
            if (t < 0) {
                break;
            } else {
                maxVal = Math.max(maxVal, valAcum + dp[n - 1][t]);
            }
        }

        System.out.println(maxVal);
    }
}
// <END-OF-CODE>
