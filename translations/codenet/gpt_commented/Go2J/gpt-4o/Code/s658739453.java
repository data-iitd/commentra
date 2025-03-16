import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Define a constant for the modulo operation
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        // Declare variables for the number of elements (n) and the number of blocked positions (p)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int p = scanner.nextInt();

        // Create a map to store the blocked positions
        Map<Long, Long> blockedPositions = new HashMap<>();

        // Read the blocked positions and store them in the map
        for (int index = 0; index < p; index++) {
            long blockedPosition = scanner.nextLong();
            blockedPositions.put(blockedPosition, blockedPosition);
        }

        // Initialize an array to store the number of ways to reach each position
        long[] dp = new long[n + 1];

        // Base cases: There is 1 way to reach the 0th and 1st positions
        dp[0] = 1;
        dp[1] = 1;

        // If the first position is blocked, set the number of ways to reach it to 0
        if (blockedPositions.containsKey(1L)) {
            dp[1] = 0;
        }

        // Iterate through positions from 2 to n to calculate the number of ways to reach each position
        for (int i = 2; i <= n; i++) {
            // If the current position is blocked, skip the calculation
            if (blockedPositions.containsKey((long) i)) {
                continue;
            }
            // Calculate the number of ways to reach the current position using the previous two positions
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        // Print the number of ways to reach the nth position
        System.out.println(dp[n]);
    }
}
// <END-OF-CODE>
