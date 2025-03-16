import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Reading the number of elements
        int n = sc.nextInt();
        // Initializing the array to store the values
        int[][] arr = new int[n][3];
        // Reading the values into the array
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= 2; ++j) arr[i][j] = sc.nextInt();
        
        // Initializing the DP table with the same dimensions as arr
        int[][] dp = new int[n][3];
        // Setting the first row of dp to be the same as the first row of arr
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][2];
        
        // Filling the DP table
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (j == 0)
                    // Choosing the current element and either of the two previous elements from dp
                    dp[i][j] = Math.max(arr[i][0] + dp[i - 1][1], arr[i][0] + dp[i - 1][2]);
                if (j == 1)
                    // Choosing the current element and either of the two previous elements from dp
                    dp[i][j] = Math.max(arr[i][1] + dp[i - 1][0], arr[i][1] + dp[i - 1][2]);
                if (j == 2)
                    // Choosing the current element and either of the two previous elements from dp
                    dp[i][j] = Math.max(arr[i][2] + dp[i - 1][1], arr[i][2] + dp[i - 1][0]);
            }
        }
        
        // Finding the maximum value in the last row of dp
        int max = -1;
        for (int i = 0; i < 3; ++i)
            if (dp[n - 1][i] > max) max = dp[n - 1][i];
        
        // Printing the maximum value
        System.out.println(max);
    }
}

class sc {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = new StringTokenizer("");
    
    // Method to read the next token
    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(reader.readLine());
        return tokenizer.nextToken();
    }
    
    // Method to read the next integer
    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    
    // Method to read the next double
    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    
    // Method to read the next long
    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    
    // Method to read the next float
    static float nextFloat() throws IOException {
        return Float.parseFloat(next());
    }
}
