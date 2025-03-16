import java.util.*;

public class Main {
    // Define necessary data types and constants
    static final long INF = 123456789012L; // Constants and data types are defined here
    static long[] key = new long[1005]; // Initialize arrays here
    static long[] cost = new long[1005];
    static long[][] dp = new long[(1 << 12) + 5][1005]; // 2D dynamic programming table

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input
        long n = scanner.nextLong(); // n is the number of switches
        long m = scanner.nextLong(); // m is the number of bulbs

        // Initialize dynamic programming table with infinite values
        for (int i = 0; i < (1 << 12) + 5; i++) {
            Arrays.fill(dp[i], INF); // Set all values to infinite
        }
        dp[0][0] = 0; // Set the initial value of dp[0][0] to 0

        // Read bulbs' information
        for (int i = 1; i <= m; i++) {
            long b; // The number of switches needed to turn on this bulb
            cost[i] = scanner.nextLong();
            b = scanner.nextLong();

            // Update key array
            for (int j = 0; j < b; j++) {
                long c; // The position of the switch
                c = scanner.nextLong();
                key[i] += (1L << (c - 1)); // Set the corresponding bit in key[i] to 1
            }
        }

        // Fill dynamic programming table
        for (long i = 0; i < (1 << n); i++) { // Iterate through all possible combinations of switches
            for (int j = 0; j < m; j++) { // Iterate through all bulbs
                dp[(int)i][j + 1] = Math.min(dp[(int)i][j], dp[(int)i][j + 1]); // Update dp[i][j+1]
                dp[(int)(i | key[j + 1])][j + 1] = Math.min(dp[(int)(i | key[j + 1])][j + 1], dp[(int)i][j] + cost[j + 1]); // Update dp[i|key[j+1]][j+1]
            }
        }

        // Output result
        if (dp[(1 << n) - 1][m] == INF) {
            System.out.println(-1); // Check if the minimum cost is infinite
        } else {
            System.out.println(dp[(1 << n) - 1][m]); // Output the minimum cost
        }

        scanner.close();
    }
}
// <END-OF-CODE>
