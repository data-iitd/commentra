
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int H = in.nextInt();
        int N = in.nextInt();
        int[] dp = new int[H + 10001];
        for (int l = 1; l < H + 10001; l++) {
            dp[l] = 2100000000;
        }
        int amax = 0;
        for (int i = 0; i < N; i++) {
            int A = in.nextInt();
            int B = in.nextInt();
            if (A >= amax) {
                amax = A;
            }
            dp[A] = Math.min(dp[A], B);
            for (int j = A + 1; j <= H + A + 1; j++) {
                dp[j] = Math.min(dp[j], dp[j - A] + B);
            }
        }
        System.out.println(min(dp, H, amax));
    }

    public static int min(int[] dp, int H, int amax) {
        int min = 2100000000;
        for (int i = H; i >= 0; i--) {
            if (i <= H - amax) {
                break;
            }
            if (dp[i] < min) {
                min = dp[i];
            }
        }
        return min;
    }
}

