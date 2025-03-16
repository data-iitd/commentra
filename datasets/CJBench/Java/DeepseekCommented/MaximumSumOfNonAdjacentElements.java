import java.util.Scanner; // Importing Scanner class for reading input
final class Main { // Defining the Main class which cannot be inherited
    private Main() {
    } // Private constructor to prevent instantiation

    // Method to calculate the maximum sum of non-adjacent elements using dynamic programming
    public static int getMaxSumApproach1(int[] arr) {
        if (arr.length == 0) {
            return 0; // Return 0 if the array is empty
        }
        int n = arr.length;
        int[] dp = new int[n];
        dp[0] = arr[0]; // Initialize the first element of dp array
        for (int ind = 1; ind < n; ind++) {
            int notTake = dp[ind - 1]; // Value if we don't take the current element
            int take = arr[ind]; // Value if we take the current element
            if (ind > 1) {
                take += dp[ind - 2]; // Add the value from two indices back if possible
            }
            dp[ind] = Math.max(take, notTake); // Choose the maximum of take or notTake
        }
        return dp[n - 1]; // Return the last element of dp array which contains the result
    }

    // Method to calculate the maximum sum of non-adjacent elements using a space-efficient approach
    public static int getMaxSumApproach2(int[] arr) {
        if (arr.length == 0) {
            return 0; // Return 0 if the array is empty
        }
        int n = arr.length;
        int prev1 = arr[0]; // Store the value of the first element
        int prev2 = 0; // Initialize the second previous value
        for (int ind = 1; ind < n; ind++) {
            int notTake = prev1; // Value if we don't take the current element
            int take = arr[ind]; // Value if we take the current element
            if (ind > 1) {
                take += prev2; // Add the value from two indices back if possible
            }
            int current = Math.max(take, notTake); // Choose the maximum of take or notTake
            prev2 = prev1; // Update the second previous value
            prev1 = current; // Update the previous value
        }
        return prev1; // Return the last updated previous value which contains the result
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int n = scanner.nextInt(); // Read the size of the array
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt(); // Read the elements of the array
        }
        int choice = scanner.nextInt(); // Read the choice of the method
        int result;
        if (choice == 1) {
            result = getMaxSumApproach1(array); // Calculate the result using method 1
        } else {
            result = getMaxSumApproach2(array); // Calculate the result using method 2
        }
        System.out.println("The maximum sum of non-adjacent elements is: " + result); // Print the result
    }
}
