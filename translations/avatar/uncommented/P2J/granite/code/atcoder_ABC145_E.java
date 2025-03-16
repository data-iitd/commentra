
import java.util.*;
import java.io.*;

class atcoder_ABC145_E {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int T = Integer.parseInt(input[1]);
        int[][] time_value = new int[N+1][2];
        for (int i = 1; i <= N; i++) {
            input = br.readLine().split(" ");
            time_value[i][0] = Integer.parseInt(input[0]);
            time_value[i][1] = Integer.parseInt(input[1]);
        }
        Arrays.sort(time_value, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        int[][] dp = new int[N+1][T+1];
        for (int t = 0; t <= T; t++) {
            dp[0][t] = 0;
        }
        for (int n = 1; n <= N; n++) {
            dp[n][0] = 0;
            for (int t = 1; t <= T; t++) {
                if (time_value[n][0] > t) {
                    dp[n][t] = dp[n-1][t];
                } else {
                    dp[n][t] = Math.max(dp[n-1][t], time_value[n][1] + dp[n-1][t - time_value[n][0]]);
                }
            }
        }
        int val_acum = time_value[N][1];
        int t = T - 1;
        int max_val = val_acum + dp[N-1][t];
        for (int n = N-1; n >= 1; n--) {
            val_acum += time_value[n][1];
            t -= time_value[n+1][0];
            if (t < 0) {
                break;
            } else {
                max_val = Math.max(max_val, val_acum + dp[n-1][t]);
            }
        }
        System.out.println(max_val);
    }
}
