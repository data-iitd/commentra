import java.util.*;

public class Main {
    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextLong();
        }
        long[] dp = new long[n + 1];
        dp[0] = 1;
        Map<Long, Long> kek = new HashMap<>();
        Map<Long, Integer> prev = new HashMap<>();
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + (prev.getOrDefault(nums[i - 1], -1) != i - 1 ? kek.getOrDefault(nums[i - 1], 0L) : 0);
            dp[i] %= MOD;
            kek.put(nums[i - 1], dp[i]);
            prev.put(nums[i - 1], i);
        }
        System.out.println(dp[n]);
    }
}

// <END-OF-CODE>
