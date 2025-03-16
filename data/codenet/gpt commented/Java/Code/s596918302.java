import java.util.*;

public class Main {
    public static void main(String args[]) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of rows (n) for the 2D array
        int n = sc.nextInt();
        
        // Initialize a 2D array with n rows and 3 columns
        int[][] arr = new int[n][3];
        
        // Populate the 2D array with input values
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        
        // Variable to hold the final answer
        int ans = 0;
        
        // Calculate the maximum value using dynamic programming approach
        ans = dpx(arr, n);
        
        // Print the result
        System.out.println(ans);
    }
    
    // Function to calculate the minimum cost to reach the end of the array
    static int min(int[] arr, int n) { 
        // Base case: if there's only one element, no cost
        if(n == 1) return 0;
        
        // Base case: if there are two elements, return the absolute difference
        if(n == 2) return Math.abs(arr[n - 1] - arr[n - 2]);
        
        // Calculate the cost of taking the last two elements
        int op1 = Math.abs(arr[n - 1] - arr[n - 2]) + min(arr, n - 1);
        
        // Calculate the cost of taking the last three elements
        int op2 = Math.abs(arr[n - 1] - arr[n - 3]) + min(arr, n - 2);
        
        // Return the minimum of the two options
        return Math.min(op1, op2);
    }
    
    // Recursive function to calculate maximum value using dynamic programming
    static int dpc(int[][] arr, int i, int n, int row) {
        // Base case: if we have processed all rows, return 0
        if(row == n)
            return 0;
        
        // Variables to hold the indices of the next choices
        int j = 0, k = 0;
        
        // Determine the indices based on the current choice (i)
        if(i == 1) {
            j = 0;
            k = 2;
        } else if(i == 0) {
            j = 1;
            k = 2;
        } else {
            j = 0;
            k = 1;
        }
        
        // Return the current value plus the maximum of the next choices
        return arr[row][i] + Math.max(dpc(arr, j, n, row + 1), dpc(arr, k, n, row + 1));
    }
    
    // Dynamic programming function to calculate maximum value iteratively
    static int dpx(int[][] arr, int n) {
        // Create a DP table to store intermediate results
        int[][] dp = new int[n][3];
        
        // Initialize the first row of the DP table with the first row of the input array
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][2];
        
        // Fill the DP table
        for(int i = 1; i < n; i++) {
            for(int in = 0; in < 3; in++) {
                int j = 0, k = 0;
                
                // Determine the indices based on the current choice (in)
                if(in == 1) {
                    j = 0;
                    k = 2;
                } else if(in == 0) {
                    j = 1;
                    k = 2;
                } else {
                    j = 0;
                    k = 1;
                }
                
                // Update the DP table with the maximum value for the current choice
                dp[i][in] = Math.max(dp[i - 1][k], dp[i - 1][j]) + arr[i][in];
            }
        }
        
        // Return the maximum value from the last row of the DP table
        return Math.max(dp[n - 1][0], Math.max(dp[n - 1][1], dp[n - 1][2]));
    }
}
