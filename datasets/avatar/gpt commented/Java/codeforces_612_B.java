import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        // Create a Scanner object to read input from the console
        Scanner s = new Scanner(System.in);
        
        // Read the number of elements to be processed
        int n = s.nextInt();
        
        // Initialize a dp array to store the indices of the input elements
        int dp[] = new int[200001];
        
        // Populate the dp array with the indices of the input elements
        for (int i = 0; i < n; i++) {
            // Read the next integer and store its index in the dp array
            dp[s.nextInt()] = i;
        }
        
        // Initialize a variable to accumulate the result
        long ans = 0;
        
        // Calculate the total distance between consecutive elements in the dp array
        for (int i = 2; i <= n; i++) {
            // Add the absolute difference of indices of consecutive elements to ans
            ans += Math.abs(dp[i] - dp[i - 1]);
        }
        
        // Output the final result
        System.out.println(ans);
    }
}
