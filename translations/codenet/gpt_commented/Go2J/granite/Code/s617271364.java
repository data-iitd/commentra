
import java.util.*;

public class s617271364{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        int ans = 100000;
        int[] dp = new int[N];
        dfs(dp, 0, arr, A, B, C, 0);
        System.out.println(ans);
    }

    public static void dfs(int[] dp, int times, int[] arr, int A, int B, int C, int cost) {
        if (times >= N) {
            ans = Math.min(ans, calc(dp, arr, A, B, C));
            return;
        }
        for (int i = 0; i < 4; i++) {
            dp[times] = i;
            dfs(dp, times + 1, arr, A, B, C, cost);
        }
    }

    public static int calc(int[] dp, int[] arr, int A, int B, int C, int cost) {
        int[] memo = new int[4];
        int AA = 0;
        int BB = 0;
        int CC = 0;
        for (int i = 0; i < dp.length; i++) {
            memo[dp[i]]++;
            if (dp[i] == 1) {
                AA += arr[i];
            } else if (dp[i] == 2) {
                BB += arr[i];
            } else if (dp[i] == 3) {
                CC += arr[i];
            }
        }
        cost += Math.abs(A - AA) + Math.abs(B - BB) + Math.abs(C - CC);
        for (int i = 1; i < 4; i++) {
            int a = memo[i];
            if (a < 1) {
                cost += 10000;
            } else {
                cost += (a - 1) * 10;
            }
        }
        return cost;
    }
}

