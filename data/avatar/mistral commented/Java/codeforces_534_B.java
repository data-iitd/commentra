import java.util.Arrays; // Importing the Arrays utility class
import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    // Main method is the entry point of the Java application
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object for user input

        // Reading input variables from the user
        int v1 = sc.nextInt(); // Reading the first integer value
        int v2 = sc.nextInt(); // Reading the second integer value
        int t = sc.nextInt(); // Reading the number of time steps
        int d = sc.nextInt(); // Reading the maximum difference between two consecutive values

        long[][] dp = new long[t - 1][1150]; // Creating a 2D array dp of size (t-1) x 1150 for dynamic programming table

        // Initializing the first row of the dp table with the given value
        for (int i = 0; i < t - 1; i++) {
            Arrays.fill(dp[i], Long.MIN_VALUE); // Initializing all elements of the current row with minimum long value
            dp[i][v1] = v1; // Setting the value of the cell (i, v1) to v1
        }

        long sum = 0; // Initializing a variable sum to 0

        // Filling the dp table using dynamic programming
        for (int i = 1; i < t - 1; i++) {
            for (int j = 0; j < 1150; j++) {
                for (int x = 0; x <= d; x++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j + x] + j); // Filling the current cell with the maximum value of itself and the sum of the previous cell and the current element plus the jump
                }
                for (int x = d; x >= 0; x--) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - x] + j); // Filling the current cell with the maximum value of itself and the sum of the previous cell and the current element minus the jump
                }
            }
            sum += dp[i][1149]; // Adding the value of the last cell of the current row to the sum
        }

        long ans = Long.MIN_VALUE; // Initializing a variable ans with minimum long value

        // Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row and adding the value of the last cell of the last row
        for (int i = t - 2; i < t - 1; i++) {
            for (int j = 0; j < 1150; j++) {
                if (Math.abs(j - v2) <= d) { // Checking if the absolute difference between j and v2 is less than or equal to d
                    ans = Math.max(ans, dp[i][j] + v2); // Updating the value of ans with the maximum of itself and the sum of the current cell and v2
                }
            }
        }

        System.out.println(ans); // Printing the final answer
    }
}
