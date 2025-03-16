import java.util.*;
import java.io.*;

public class Main {
    // Define long long type for convenience
    static long long ll;
    // Define a pair type for convenience
    static class PP {
        long long first, second;
        PP(long long a, long long b) {
            first = a;
            second = b;
        }
    }

    // Arrays to store the keys and costs
    static long long key[] = new long long[1005];
    static long long cost[] = new long long[1005];
    // DP table to store the minimum costs for each state
    static long long dp[][] = new long long[(1 << 12) + 5][1005];
    // Define a large constant for infinity
    static final long long INF = 123456789012;

    public static void main(String[] args) {
        // Read the number of keys (n) and the number of items (m)
        Scanner sc = new Scanner(System.in);
        long long n = sc.nextLong();
        long long m = sc.nextLong();

        // Initialize the DP table with infinity
        for(int i = 0; i < (1 << 12) + 5; i++) {
            for(int j = 0; j < 1005; j++) {
                dp[i][j] = INF; // Set each entry to infinity
            }
        }

        // Base case: cost of obtaining no keys is 0
        dp[0][0] = 0;

        // Read the costs and keys for each item
        for(int i = 1; i <= m; i++) {
            long long b = sc.nextLong();
            long long c = sc.nextLong(); // Read cost and number of keys for item i
            for(int j = 0; j < b; j++) {
                long long k = sc.nextLong(); // Read each key
                key[i] += (1 << (k - 1)); // Update the key bitmask for item i
            }
        }

        // Fill the DP table
        for(long long i = 0; i < (1 << n); i++) {
            for(int j = 0; j < m; j++) {
                // Update the DP table for not taking the (j+1)th item
                dp[i][j + 1] = Math.min(dp[i][j], dp[i][j + 1]);
                // Update the DP table for taking the (j+1)th item
                dp[i | key[j + 1]][j + 1] = Math.min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1]);
            }
        }

        // Check if it's possible to obtain all keys
        if(dp[(1 << n) - 1][m] == INF)
            System.out.println(-1); // If not possible, print -1
        else
            System.out.println(dp[(1 << n) - 1][m]); // Print the minimum cost to obtain all keys
    }
}

