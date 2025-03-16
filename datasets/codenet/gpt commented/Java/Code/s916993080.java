import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Read the number of elements (n) from input
        int n = sc.nextInt();
        
        // Initialize a 2D array to store the input values
        int[][] arr = new int[n][3];
        
        // Populate the array with input values
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= 2; ++j) 
                arr[i][j] = sc.nextInt();
        
        // Initialize a DP array to store the maximum values computed
        int[][] dp = new int[n][3];
        
        // Base case: the first row of dp is the same as the first row of arr
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][2];
        
        // Fill the DP table
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                // Calculate the maximum value for each column in the current row
                if (j == 0)
                    dp[i][j] = Math.max(arr[i][0] + dp[i - 1][1], arr[i][0] + dp[i - 1][2]);
                if (j == 1)
                    dp[i][j] = Math.max(arr[i][1] + dp[i - 1][0], arr[i][1] + dp[i - 1][2]);
                if (j == 2)
                    dp[i][j] = Math.max(arr[i][2] + dp[i - 1][1], arr[i][2] + dp[i - 1][0]);
            }
        }
        
        // Find the maximum value from the last row of the DP table
        int max = -1;
        for (int i = 0; i < 3; ++i)
            if (dp[n - 1][i] > max) 
                max = dp[n - 1][i];
        
        // Output the maximum value found
        System.out.println(max);
    }
}

// Class for handling input
class sc {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = new StringTokenizer("");
    
    // Method to get the next token as a String
    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(reader.readLine());
        return tokenizer.nextToken();
    }
    
    // Method to get the next token as an integer
    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    
    // Method to get the next token as a double
    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    
    // Method to get the next token as a long
    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    
    // Method to get the next token as a float
    static float nextFloat() throws IOException {
        return Float.parseFloat(next());
    }
}
