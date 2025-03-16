import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Knapsack {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int T = scanner.nextInt();

        List<int[]> timeValue = new ArrayList<>();
        timeValue.add(new int[]{-1, -1});

        for (int i = 1; i <= N; i++) {
            int time = scanner.nextInt();
            int value = scanner.nextInt();
            timeValue.add(new int[]{time, value});
        }

        Collections.sort(timeValue, (a, b) -> Integer.compare(a[1], b[1]));

        int[][] dp = new int[N + 1][T + 1];

        for (int t = 0; t <= T; t++) {
            dp[0][t] = 0;
        }

        for (int n = 1; n <= N; n++) {
            dp[n][0] = 0;
            for (int t = 1; t <= T; t++) {
                if (timeValue.get(n)[0] > t) {
                    dp[n][t] = dp[n - 1][t];
                } else {
                    dp[n][t] = Math.max(dp[n - 1][t], timeValue.get(n)[1] + dp[n - 1][t - timeValue.get(n)[0]]);
                }
            }
        }

        int valAcum = timeValue.get(N)[1];
        int t = T - 1;
        int maxVal = valAcum + dp[N - 1][t];

        for (int n = N - 1; n > 0; n--) {
            valAcum += timeValue.get(n)[1];
            t -= timeValue.get(n + 1)[0];
            if (t < 0) {
                break;
            } else {
                maxVal = Math.max(maxVal, valAcum + dp[n - 1][t]);
            }
        }

        System.out.println(maxVal);
    }
}
