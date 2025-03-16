
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        String S = sc.next();
        int[][] dp = new int[N][K + 1];
        for (int i = 0; i < N; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= K; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= K; j++) {
                if (S.charAt(i) == '0') {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        System.out.println(dp[N - 1][K]);
    }
}

