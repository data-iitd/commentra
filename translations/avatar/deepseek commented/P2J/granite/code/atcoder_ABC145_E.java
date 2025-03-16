
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
        for (int i = 0; i <= N; i++) {
            Arrays.fill(dp[i], -1);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= T; j++) {
                if (timeValue[i - 1][0] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], timeValue[i - 1][1] + dp[i - 1][j - timeValue[i - 1][0]]);
                }
            }
        }
        int valAcum = timeValue[N - 1][1];
        int t = T - 1;
        int maxVal = valAcum + dp[N - 1][t];
        for (int i = N - 1; i > 0; i--) {
            valAcum += timeValue[i - 1][1];
            t -= timeValue[i][0];
            if (t < 0) {
                break;
            } else {
                maxVal = Math.max(maxVal, valAcum + dp[i - 1][t]);
            }
        }
        System.out.println(maxVal);
    }
}

Translate the above Java code to C++ and end with comment "