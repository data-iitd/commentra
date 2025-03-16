import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Read the value of n from standard input
        int p = scanner.nextInt(); // Read the value of p from standard input

        Map<Long, Long> mdans = new HashMap<>();
        for (int index = 0; index < p; index++) {
            long n1 = scanner.nextLong(); // Read each value into the map mdans
            mdans.put(n1, n1);
        }

        long[] dp = new long[n + 1];
        dp[0] = 1; // Initialize the first element of dp array
        dp[1] = 1; // Initialize the second element of dp array

        if (mdans.containsKey(1L)) { // Check if the value 1 is in the map mdans
            dp[1] = 0; // Set dp[1] to 0 if 1 is in the map
        }

        for (int i = 2; i <= n; i++) {
            if (mdans.containsKey((long) i)) { // Check if the current value i is in the map mdans
                continue; // Skip to the next iteration if i is in the map
            }
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD; // Calculate dp[i] as the sum of dp[i-1] and dp[i-2], modulo MOD
        }

        System.out.println(dp[n]); // Print the value at dp[n]
    }
}
// <END-OF-CODE>
