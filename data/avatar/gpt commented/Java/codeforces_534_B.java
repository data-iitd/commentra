import java.util.Arrays; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read four integers from input: initial velocity (v1), final velocity (v2), time (t), and maximum change in velocity (d)
        int v1 = sc.nextInt(); 
        int v2 = sc.nextInt(); 
        int t = sc.nextInt(); 
        int d = sc.nextInt(); 
        
        // Initialize a 2D array dp to store the maximum values for each time step and velocity
        long[][] dp = new long[t - 1][1150]; 
        
        // Fill the dp array with a very small value to represent uninitialized states
        for (int i = 0; i < t - 1; i++) { 
            Arrays.fill(dp[i], -(long)(1e17)); 
        } 
        
        // Set the initial state for the first time step with the initial velocity
        dp[0][v1] = v1; 
        
        // Variable to accumulate the maximum sum of velocities
        long sum = 0; 
        
        // Iterate through each time step from 1 to t-2
        for (int i = 1; i < t - 1; i++) { 
            // Iterate through each possible velocity
            for (int j = 0; j < 1150; j++) { 
                // Update the dp array for increasing velocities
                for (int x = 0; x <= d; x++) { 
                    if (j + x < 1150) 
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j + x] + j); 
                } 
                // Update the dp array for decreasing velocities
                for (int x = d; x >= 0; x--) { 
                    if (j - x >= 0) { 
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - x] + j); 
                    } 
                } 
            } 
        } 
        
        // Variable to store the final answer, initialized to the smallest possible value
        long ans = Long.MIN_VALUE; 
        
        // Iterate through the last time step to find the maximum achievable velocity close to v2
        for (int i = t - 2; i < t - 1; i++) { 
            for (int j = 0; j < 1150; j++) { 
                // Check if the current velocity is within the allowed range of v2
                if (Math.abs(j - v2) <= d) 
                    ans = Math.max(ans, dp[i][j] + v2); 
            } 
        } 
        
        // Output the final answer
        System.out.println(ans); 
    } 
}
