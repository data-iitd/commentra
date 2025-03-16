
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] A = new int[sc.nextInt()];
        for (int i = 0; i < A.length; i++) {
            A[i] = sc.nextInt();
        }
        int N = A.length;
        int[] dp = new int[N + 1];
        dp[0] = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] <= dp[i - 1]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = A[i];
            }
        }
        int lo = 0, hi = N;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (isPossible(A, dp, mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        System.out.println(lo);
    }

    public static boolean isPossible(int[] A, int[] dp, int K) {
        for (int i = 1; i < A.length; i++) {
            if (A[i] <= dp[i - 1]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = A[i];
            }
        }
        for (int i = 0; i < A.length; i++) {
            if (dp[i] < K - 1) {
                return false;
            }
        }
        return true;
    }
}

