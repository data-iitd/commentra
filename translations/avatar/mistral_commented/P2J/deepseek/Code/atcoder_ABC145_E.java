import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int T = scanner.nextInt();
        
        int[][] timeValue = new int[N+1][2];
        timeValue[0][0] = -1;
        timeValue[0][1] = -1;
        
        for (int i = 1; i <= N; i++) {
            timeValue[i][0] = scanner.nextInt();
            timeValue[i][1] = scanner.nextInt();
        }
        
        Arrays.sort(timeValue, (a, b) -> Integer.compare(a[1], b[1]));
        
        int[][] dp = new int[N+1][T];
        
        for (int t = 0; t < T; t++) {
            dp[0][t] = 0;
        }
        dp[0][0] = 0;
        for (int n = 1; n <= N; n++) {
            dp[n][0] = 0;
        }
        
        for (int n = 1; n <= N; n++) {
            for (int t = 1; t < T; t++) {
                if (timeValue[n][0] > t) {
                    dp[n][t] = dp[n-1][t];
                } else {
                    dp[n][t] = Math.max(dp[n-1][t], timeValue[n][1] + dp[n-1][t-timeValue[n][0]]);
                }
            }
        }
        
        int valAcum = timeValue[N][1];
        int t = T - 1;
        int maxVal = valAcum + dp[N-1][t];
        
        for (int n = N-1; n > 0; n--) {
            valAcum += timeValue[n][1];
            t -= timeValue[n+1][0];
            if (t < 0) {
                break;
            } else {
                maxVal = Math.max(maxVal, valAcum + dp[n-1][t]);
            }
        }
        
        System.out.println(maxVal);
    }
}
