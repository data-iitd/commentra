
import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC145_E{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int T = scanner.nextInt();
        int[][] timeValue = new int[N][2];
        for (int i = 0; i < N; i++) {
            timeValue[i][0] = scanner.nextInt();
            timeValue[i][1] = scanner.nextInt();
        }
        Arrays.sort(timeValue, (a, b) -> Integer.compare(a[1], b[1]));
        int[][] dp = new int[N + 1][T + 1];
        for (int n = 1; n <= N; n++) {
            for (int t = 1; t <= T; t++) {
                if (timeValue[n - 1][0] > t) {
                    dp[n][t] = dp[n - 1][t];
                } else {
                    dp[n][t] = Math.max(dp[n - 1][t], timeValue[n - 1][1] + dp[n - 1][t - timeValue[n - 1][0]]);
                }
            }
        }
        int valAcum = timeValue[N - 1][1];
        int t = T - timeValue[N - 1][0];
        int maxVal = valAcum + dp[N - 1][t];
        for (int n = N - 2; n >= 0; n--) {
            valAcum += timeValue[n][1];
            t -= timeValue[n][0];
            if (t < 0) {
                break;
            } else {
                maxVal = Math.max(maxVal, valAcum + dp[n][t]);
            }
        }
        System.out.println(maxVal);
    }
}
