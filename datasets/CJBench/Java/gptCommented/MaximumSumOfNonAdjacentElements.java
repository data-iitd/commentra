import java.util.Scanner;

final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to calculate the maximum sum of non-adjacent elements using dynamic programming (Approach 1)
    public static int getMaxSumApproach1(int[] arr) {
        // If the array is empty, return 0 as the maximum sum
        if (arr.length == 0) {
            return 0; 
        }
        
        int n = arr.length; // Get the length of the array
        int[] dp = new int[n]; // Create a dp array to store maximum sums
        
        dp[0] = arr[0]; // Initialize the first element of dp with the first element of arr
        
        // Iterate through the array starting from the second element
        for (int ind = 1; ind < n; ind++) {
            int notTake = dp[ind - 1]; // Maximum sum if we do not take the current element
            int take = arr[ind]; // Start with the current element
            
            // If we are not at the first element, add the maximum sum from two elements before
            if (ind > 1) {
                take += dp[ind - 2];
            }
            
            // Store the maximum of taking or not taking the current element
            dp[ind] = Math.max(take, notTake);
        }
        
        // Return the maximum sum found for the entire array
        return dp[n - 1];
    }

    // Method to calculate the maximum sum of non-adjacent elements using a space-optimized approach (Approach 2)
    public static int getMaxSumApproach2(int[] arr) {
        // If the array is empty, return 0 as the maximum sum
        if (arr.length == 0) {
            return 0; 
        }
        
        int n = arr.length; // Get the length of the array
        int prev1 = arr[0]; // Initialize prev1 with the first element of arr
        int prev2 = 0; // Initialize prev2 to 0
        
        // Iterate through the array starting from the second element
        for (int ind = 1; ind < n; ind++) {
            int notTake = prev1; // Maximum sum if we do not take the current element
            int take = arr[ind]; // Start with the current element
            
            // If we are not at the first element, add the maximum sum from two elements before
            if (ind > 1) {
                take += prev2;
            }
            
            // Calculate the current maximum sum
            int current = Math.max(take, notTake);
            
            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;
            prev1 = current;
        }
        
        // Return the maximum sum found for the entire array
        return prev1;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        
        // Read the number of elements in the array
        int n = scanner.nextInt();
        int[] array = new int[n]; // Initialize the array
        
        // Read the elements of the array from input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        // Read the choice of approach from input
        int choice = scanner.nextInt();
        int result; // Variable to store the result
        
        // Determine which approach to use based on user choice
        if (choice == 1) {
            result = getMaxSumApproach1(array); // Use Approach 1
        } else {
            result = getMaxSumApproach2(array); // Use Approach 2
        }
        
        // Print the result
        System.out.println("The maximum sum of non-adjacent elements is: " + result);
    }
}
