import java.util.Scanner;

public class Main {
    static long[][][] dp = new long[3000][3000][4];
    static long[] dpl = new long[3000];
    static int[][] mat = new int[3000][3000];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int rr = scanner.nextInt();
        int cc = scanner.nextInt();
        int k = scanner.nextInt();

        // Input the values into the matrix
        for (int i = 0; i < k; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int v = scanner.nextInt();
            // Store the value in the matrix (adjusting for 0-based indexing)
            mat[r - 1][c - 1] = v;
        }

        // Initialize the dynamic programming array with the value at the starting position
        dp[0][0][1] = mat[0][0];

        // Iterate through each cell in the matrix
        for (int y = 0; y < rr; y++) {
            for (int x = 0; x < cc; x++) {
                // Iterate through the four possible states (c)
                for (int c = 0; c < 4; c++) {
                    int v = mat[y][x]; // Get the current cell value
                    long q; // Variable to store the computed maximum value

                    // Check if we are at the first column or if the current value is zero
                    if (c == 0 || v == 0) {
                        // If at the first column, take the value from dpl, else take the maximum from previous states
                        q = (x == 0) ? dpl[x] : Math.max(dpl[x], dp[y][x - 1][c]);
                    } else {
                        // If not at the first column, calculate the maximum considering the current value
                        q = (x == 0) ? dpl[x] + v : Math.max(dpl[x] + v, Math.max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v));
                    }
                    // Store the computed maximum value in the dp array
                    dp[y][x][c] = q;
                }
            }
            // Update the dpl array with the maximum values from the current row
            for (int x = 0; x < cc; x++) {
                dpl[x] = Math.max(Math.max(dp[y][x][0], dp[y][x][1]), Math.max(dp[y][x][2], dp[y][x][3]));
            }
        }

        // Output the maximum value found in the last column
        System.out.println(dpl[cc - 1]);

        scanner.close();
    }
}

// <END-OF-CODE>
