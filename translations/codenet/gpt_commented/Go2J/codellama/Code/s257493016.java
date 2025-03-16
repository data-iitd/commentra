
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int N = sc.nextInt();
        int[] dp = new int[H + 10001];
        for (int i = 1; i < dp.length; i++) {
            dp[i] = 2100000000;
        }
        int amax = 0;
        for (int i = 0; i < N; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            if (A >= amax) {
                amax = A;
            }
            dp[A] = Math.min(dp[A], B);
            for (int j = A + 1; j <= H + amax + 1; j++) {
                dp[j] = Math.min(dp[j], dp[j - A] + B);
            }
        }
        System.out.println(min(dp, H, amax));
    }

    public static int min(int[] dp, int H, int amax) {
        int min = 2100000000;
        for (int i = H; i <= H + amax; i++) {
            if (dp[i] < min) {
                min = dp[i];
            }
        }
        return min;
    }
}

