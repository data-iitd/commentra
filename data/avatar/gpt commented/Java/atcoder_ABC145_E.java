import java.util.Arrays; 
import java.util.Comparator; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of items (N) and the time limit (T)
        int N = sc.nextInt(); 
        int T = sc.nextInt(); 
        
        // Initialize a 2D array to store the time and value of each item
        int[][] AB = new int[N][2]; 
        
        // Read the time and value for each item from the input
        for (int i = 0; i < N; i++) { 
            AB[i][0] = sc.nextInt(); // Time required for the item
            AB[i][1] = sc.nextInt(); // Value of the item
        } 
        
        // Sort the items based on the time required in ascending order
        Arrays.sort(AB, Comparator.comparingInt(a -> a[0])); 
        
        // Initialize a DP table where dp[i][j] represents the maximum value 
        // that can be obtained using the first i items within j time
        int[][] dp = new int[N + 1][6001]; 
        
        // Fill the DP table
        for (int i = 1; i <= N; i++) { 
            for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) { 
                // Carry forward the maximum value from the previous item
                dp[i][timeAfterEat] = Math.max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]); 
                
                // Get the time and value of the current item
                int time = AB[i - 1][0]; 
                int value = AB[i - 1][1]; 
                
                // Check if the current item can be taken within the remaining time
                if (0 <= timeAfterEat - time && timeAfterEat - time < T) { 
                    // Update the DP table with the maximum value obtained by taking the current item
                    dp[i][timeAfterEat] = Math.max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value); 
                } 
            } 
        } 
        
        // Output the maximum value that can be obtained using all items
        System.out.println(Arrays.stream(dp[N]).max().getAsInt()); 
    } 
}
