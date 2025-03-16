import java.util.Scanner;

public class Main {
    static long[] key = new long[1005]; // Array to store the keys in a binary format
    static long[] cost = new long[1005]; // Array to store the cost of each item
    static long[][] dp = new long[(1 << 12) + 5][1005]; // 2D array for dynamic programming
    static final long INF = 123456789012L; // Constant for infinity

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong(); // Read the number of keys (n)
        long m = scanner.nextLong(); // Read the number of items (m)

        // Initialize the dp array with infinity
        for (int i = 0; i < (1 << 12) + 5; i++) {
            for (int j = 0; j < 1005; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0; // Base case: no keys and no cost

        for (int i = 1; i <= m; i++) { // Read the cost and keys for each item
            long b = scanner.nextLong();
            cost[i] = scanner.nextLong();
            for (int j = 0; j < b; j++) {
                long c = scanner.nextLong();
                key[i] += (1 << (c - 1)); // Convert key information into binary format
            }
        }

        for (long i = 0; i < (1 << n); i++) { // Iterate through all possible states
            for (int j = 0; j < m; j++) {
                dp[(int) i][j + 1] = Math.min(dp[(int) i][j], dp[(int) i][j + 1]); // Update the dp array based on the current state
                dp[(int) (i | key[j + 1])][j + 1] = Math.min(dp[(int) (i | key[j + 1])][j + 1], dp[(int) i][j] + cost[j + 1]); // Update the dp array based on the next state
            }
        }

        if (dp[(1 << n) - 1][m] == INF) {
            System.out.println(-1); // Check if it's not possible to collect all keys and output -1
        } else {
            System.out.println(dp[(1 << n) - 1][m]); // Output the minimum cost to collect all keys
        }

        scanner.close();
    }
}
// <END-OF-CODE>
