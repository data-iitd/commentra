
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
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < Math.pow(4, N); i++) {
            int[] dp = new int[N];
            int cost = 0;
            int[] memo = new int[4];
            for (int j = 0; j < N; j++) {
                dp[j] = i % 4;
                memo[dp[j]]++;
                if (dp[j] == 1) {
                    cost += arr[j];
                } else if (dp[j] == 2) {
                    cost += arr[j];
                } else if (dp[j] == 3) {
                    cost += arr[j];
                }
                i /= 4;
            }
            cost += Math.abs(A - memo[1]) + Math.abs(B - memo[2]) + Math.abs(C - memo[3]);
            for (int j = 1; j < 4; j++) {
                if (memo[j] < 1) {
                    cost += 10000;
                } else {
                    cost += (memo[j] - 1) * 10;
                }
            }
            ans = Math.min(ans, cost);
        }
        System.out.println(ans);
    }
}

// Translate the above Java code to C++ and end with comment "