import java.util.Scanner; // We import the Scanner class for input

public class Main {
    static long N;
    static long[] A = new long[1 << 18]; // We declare the array A of type long
    static long[][][] dp = new long[1 << 18][2][20]; // We declare a 3-dimensional array dp

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        N = scanner.nextLong(); // We read the value of N from the standard input
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong(); // We read the values of the array A from the standard input
        }

        // Initialize dp array with minimum values
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < 20; j++) {
                dp[i][0][j] = Long.MIN_VALUE; // Initialize dp[i][0][j] with a very large negative value
                dp[i][1][j] = Long.MIN_VALUE; // Initialize dp[i][1][j] with a very large negative value
            }
        }

        // Base case: dp[0][0][10] = 0
        dp[0][0][10] = 0;

        // Iterate through all the elements of the array A
        for (int i = 1; i <= N; i++) {
            for (int j = 6; j <= 14; j++) { // We only consider the cases where j is between 6 and 14
                if (dp[i - 1][0][j] != Long.MIN_VALUE) { // If dp[i-1][0][j] is not equal to the very large negative value
                    dp[i][1][j + 1] = Math.max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]); // Update dp[i][1][j+1]
                    dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][0][j]); // Update dp[i][0][j-1]
                }
                if (dp[i - 1][1][j] != Long.MIN_VALUE) { // If dp[i-1][1][j] is not equal to the very large negative value
                    dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][1][j]); // Update dp[i][0][j-1]
                }
            }
        }

        // Calculate the value of T1 and T2
        long V = 10 + (N / 2) - (N - (N / 2));
        long T1 = dp[N][0][(int)V];
        long T2 = dp[N][1][(int)V];

        // Print the maximum value of T1 and T2
        System.out.println(Math.max(T1, T2));

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
