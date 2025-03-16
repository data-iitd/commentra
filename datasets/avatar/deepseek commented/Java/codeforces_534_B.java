
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Step 1: Read input values for v1, v2, t, and d.
        int v1 = sc.nextInt();
        int v2 = sc.nextInt();
        int t = sc.nextInt();
        int d = sc.nextInt();
        
        // Step 2: Initialize a 2D array dp with dimensions (t-1) x 1150, and fill it with a very small value (-1e17).
        long[][] dp = new long[t - 1][1150];
        for (int i = 0; i < t - 1; i++) {
            Arrays.fill(dp[i], - (long) (1e17));
        }
        
        // Step 3: Set the initial value of dp[0][v1] to v1.
        dp[0][v1] = v1;
        
        // Step 4: Iterate through the time steps from 1 to t-2.
        long sum = 0;
        for (int i = 1; i < t - 1; i++) {
            // Step 5: For each time step, update the dp array based on the possible values of j (current position) and x (distance change).
            for (int j = 0; j < 1150; j++) {
                for (int x = 0; x <= d; x++) {
                    if (j + x < 1150) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j + x] + j);
                    }
                }
                for (int x = d; x >= 0; x--) {
                    if (j - x >= 0) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - x] + j);
                    }
                }
            }
        }
        
        // Step 6: After updating the dp array, find the maximum value of dp[t-2][j] + v2 where the absolute difference between j and v2 is within the range d.
        long ans = Long.MIN_VALUE;
        for (int i = t - 2; i < t - 1; i++) {
            for (int j = 0; j < 1150; j++) {
                if (Math.abs(j - v2) <= d) {
                    ans = Math.max(ans, dp[i][j] + v2);
                }
            }
        }
        
        // Step 7: Print the result.
        System.out.println(ans);
    }
}