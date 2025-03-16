import java.util.Scanner;

public class KeyCost {
    // Define a large constant for infinity
    static final long INF = 123456789012L;
    // Arrays to store the keys and costs
    static long[] key = new long[1005];
    static long[] cost = new long[1005];
    // DP table to store the minimum costs for each state
    static long[][] dp = new long[(1 << 12) + 5][1005];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of keys (n) and the number of items (m)
        long n = scanner.nextLong();
        long m = scanner.nextLong();

        // Initialize the DP table with infinity
        for (int i = 0; i < (1 << 12) + 5; i++) {
            for (int j = 0; j < 1005; j++) {
                dp[i][j] = INF; // Set each entry to infinity
            }
        }

        // Base case: cost of obtaining no keys is 0
        dp[0][0] = 0;

        // Read the costs and keys for each item
        for (int i = 1; i <= m; i++) {
            long b = scanner.nextLong(); // Read number of keys for item i
            cost[i] = scanner.nextLong(); // Read cost for item i
            for (int j = 0; j < b; j++) {
                long c = scanner.nextLong(); // Read each key
                key[i] += (1 << (c - 1)); // Update the key bitmask for item i
            }
        }

        // Fill the DP table
        for (long i = 0; i < (1 << n); i++) {
            for (int j = 0; j < m; j++) {
                // Update the DP table for not taking the (j+1)th item
                dp[i][j + 1] = Math.min(dp[i][j], dp[i][j + 1]);
                // Update the DP table for taking the (j+1)th item
                dp[(int)(i | key[j + 1])][j + 1] = Math.min(dp[(int)(i | key[j + 1])][j + 1], dp[(int)i][j] + cost[j + 1]);
            }
        }

        // Check if it's possible to obtain all keys
        if (dp[(1 << (int)n) - 1][(int)m] == INF) {
            System.out.println(-1); // If not possible, print -1
        } else {
            System.out.println(dp[(1 << (int)n) - 1][(int)m]); // Print the minimum cost to obtain all keys
        }

        scanner.close();
    }
}
// <END-OF-CODE>
