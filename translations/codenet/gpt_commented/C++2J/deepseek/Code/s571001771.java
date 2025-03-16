import java.util.*;

public class Main {
    // Define a pair type for convenience
    static class PP {
        int first, second;
        PP(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of keys (n) and the number of items (m)
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Arrays to store the keys and costs
        int[] key = new int[1005];
        int[] cost = new int[1005];
        // DP table to store the minimum costs for each state
        long[][] dp = new long[1 << 12 + 5][1005];
        // Define a large constant for infinity
        final long INF = 123456789012L;

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
            cost[i] = scanner.nextInt(); // Read cost for item i
            int b = scanner.nextInt(); // Read number of keys for item i
            for (int j = 0; j < b; j++) {
                int c = scanner.nextInt(); // Read each key
                key[i] |= (1 << (c - 1)); // Update the key bitmask for item i
            }
        }

        // Fill the DP table
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < m; j++) {
                // Update the DP table for not taking the (j+1)th item
                dp[i][j + 1] = Math.min(dp[i][j], dp[i][j + 1]);
                // Update the DP table for taking the (j+1)th item
                dp[i | key[j + 1]][j + 1] = Math.min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1]);
            }
        }

        // Check if it's possible to obtain all keys
        if (dp[(1 << n) - 1][m] == INF)
            System.out.println(-1); // If not possible, print -1
        else
            System.out.println(dp[(1 << n) - 1][m]); // Print the minimum cost to obtain all keys
    }
}
