import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in); 
        
        // Read the total number of items (n) to be processed
        int n = scanner.nextInt(); 
        
        // Define the maximum size for the dp array
        int maxn = 4010; 
        
        // Read three integer values (a, b, c) which represent the sizes of items
        int a = scanner.nextInt(); 
        int b = scanner.nextInt(); 
        int c = scanner.nextInt(); 
        
        // Store the sizes of items in an array for easier access
        int[] arr = { a, b, c }; 
        
        // Initialize a dp array to store the maximum number of items that can be formed
        int[] dp = new int[maxn]; 
        
        // Set all dp values to Integer.MIN_VALUE to indicate uncomputed states
        for (int i = 0; i < n; i++) { 
            dp[i] = Integer.MIN_VALUE; 
        }
        
        // Base case: zero items can be formed with zero size
        dp[0] = 0; 
        
        // Iterate through each item size (a, b, c)
        for (int i = 0; i < 3; i++) { 
            // Update the dp array for each possible size from the current item size
            for (int j = arr[i]; j < dp.length; j++) { 
                // Calculate the maximum number of items that can be formed
                dp[j] = Math.max(dp[j], dp[j - arr[i]] + 1); 
            } 
        } 
        
        // Output the maximum number of items that can be formed with size n
        System.out.println(dp[n]); 
    } 
}
