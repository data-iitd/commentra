import java.math.BigInteger;
import java.util.*;
import static java.lang.System.*;

class Main {
    // Scanner for reading input and Random for generating random numbers
    public static Scanner sc = new Scanner(in);
    public static Random rand = new Random();

    // Main method to run the logic
    public void run() {
        // Infinite loop to process multiple test cases
        TCase: while (true) {
            // Read width (W) and height (H) of the map
            int W = sc.nextInt(), H = sc.nextInt();
            // Exit condition for the loop
            if (W == 0 && H == 0) return;

            // Initialize the map with characters
            char[][] map = new char[H][W];

            // Read the map input
            for (int h = 0; h < H; h++) {
                map[h] = sc.next().toCharArray();
            }

            // Initialize a 2D array for dynamic programming to store BigInteger values
            BigInteger[][] dp = new BigInteger[H][W];

            // Fill the dp array based on the map values
            for (int h = 0; h < H; h++) {
                for (int w = 0; w < W; w++) {
                    BigInteger hprev = BigInteger.ZERO; // Value from the cell above
                    if (h >= 1) {
                        hprev = dp[h - 1][w];
                    }
                    BigInteger wprev = BigInteger.ZERO; // Value from the cell to the left
                    if (w >= 1) {
                        wprev = dp[h][w - 1];
                    }
                    // Check if the current cell contains a digit
                    if (Character.isDigit(map[h][w])) {
                        BigInteger max;
                        // Determine the maximum value from the previous cells
                        if (hprev.compareTo(wprev) > 0) {
                            max = hprev;
                        } else {
                            max = wprev;
                        }
                        // Update the dp value for the current cell
                        dp[h][w] = max.multiply(BigInteger.TEN).add(new BigInteger(map[h][w] + ""));
                    } else {
                        // If not a digit, set the dp value to zero
                        dp[h][w] = BigInteger.ZERO;
                    }
                }
            }
            // Find the maximum value in the dp array
            BigInteger max = BigInteger.ZERO;
            for (int h = 0; h < H; h++) {
                for (int w = 0; w < W; w++) {
                    if (dp[h][w].compareTo(max) > 0) max = dp[h][w];
                }
            }
            // Print the maximum value found
            ln(max);
        }
    }

    // Main entry point of the program
    public static void main(String[] args) {
        new Main().run();
    }

    // Helper method to read an array of integers from input
    public int[] nextIntArray(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = sc.nextInt();
        }
        return res;
    }

    // Helper method to print an object without a newline
    public static void pr(Object o) {
        out.print(o);
    }

    // Helper method to print an object with a newline
    public static void ln(Object o) {
        out.println(o);
    }

    // Overloaded method to print a newline
    public static void ln() {
        out.println();
    }
}
