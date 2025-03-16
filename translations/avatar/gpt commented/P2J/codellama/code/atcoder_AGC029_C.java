
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }
        in.close();

        int[][] dp = new int[N][2];
        dp[0][0] = A[0];
        dp[0][1] = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] <= dp[i - 1][0]) {
                dp[i][0] = A[i];
                dp[i][1] = dp[i - 1][1];
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            }
        }

        int K = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (dp[i][1] < K) {
                K = dp[i][1];
            }
            if (dp[i][0] < A[i]) {
                K++;
            }
        }

        System.out.println(K);
    }
}

