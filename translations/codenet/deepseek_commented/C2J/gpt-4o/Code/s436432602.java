import java.util.Scanner;

public class GameStrategy {
    public static void run() {
        // Read the number of elements (n) and the target value (k)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Declare an array to store the elements
        int[] a = new int[100];
        
        // Read n elements into the array a
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Allocate memory for the dynamic programming array dp
        int[] dp = new int[k + 1];
        
        // Iterate from 1 to k to fill the dp array
        for (int i = 1; i <= k; i++) {
            // Initialize the win flag to 0
            int win = 0;
            
            // Check each element in the array a to see if it can be subtracted from i
            for (int j = 0; j < n && a[j] <= i; j++) {
                if (dp[i - a[j]] == 0) {
                    // If the resulting value is zero, set win to 1
                    win = 1;
                }
            }
            
            // Set dp[i] to the win flag
            dp[i] = win;
        }
        
        // Print the result based on the value of dp[k]
        System.out.println(dp[k] == 1 ? "First" : "Second");
    }

    public static void main(String[] args) {
        // Call the run function to execute the game strategy
        run();
    }
}

// <END-OF-CODE>
