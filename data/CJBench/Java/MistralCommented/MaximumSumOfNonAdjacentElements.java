
import java.util.Scanner;
final class Main {
    private Main() {
    }

    // Method to find the maximum sum of non-adjacent elements using dynamic programming approach 1
    public static int getMaxSumApproach1(int[] arr) {
        if (arr.length == 0) { // Base case: empty array returns 0
            return 0;
        }
        int n = arr.length; // Length of the array
        int[] dp = new int[n]; // Array to store the maximum sum of non-adjacent elements ending at each index

        dp[0] = arr[0]; // The maximum sum of non-adjacent elements ending at index 0 is the first element itself

        for (int ind = 1; ind < n; ind++) { // Iterate through the array from index 1 to n-1
            int notTake = dp[ind - 1]; // The maximum sum of non-adjacent elements ending at index ind-1
            int take = arr[ind]; // The element at index ind
            if (ind > 1) { // If we can take the element at index ind-2
                take += dp[ind - 2]; // Add the maximum sum of non-adjacent elements ending at index ind-2
            }
            dp[ind] = Math.max(take, notTake); // Update the maximum sum of non-adjacent elements ending at index ind
        }
        return dp[n - 1]; // The maximum sum of non-adjacent elements ending at the last index
    }

    // Method to find the maximum sum of non-adjacent elements using dynamic programming approach 2
    public static int getMaxSumApproach2(int[] arr) {
        if (arr.length == 0) { // Base case: empty array returns 0
            return 0;
        }
        int n = arr.length; // Length of the array
        int prev1 = arr[0]; // Initialize the previous two maximum sums
        int prev2 = 0;

        for (int ind = 1; ind < n; ind++) { // Iterate through the array from index 1 to n-1
            int notTake = prev1; // The maximum sum of non-adjacent elements ending at the previous index
            int take = arr[ind]; // The element at the current index
            if (ind > 1) { // If we can take the element at index ind-1
                take += prev2; // Add the maximum sum of non-adjacent elements ending at index ind-1
            }
            int current = Math.max(take, notTake); // Update the maximum sum of non-adjacent elements at the current index
            prev2 = prev1; // Update the previous maximum sum
            prev1 = current; // Update the current maximum sum
        }
        return prev1; // The maximum sum of non-adjacent elements at the last index
    }

    // Main method to read input and call the appropriate method based on user choice
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console

        int n = scanner.nextInt(); // Read the number of elements in the array
        int[] array = new int[n]; // Create an array of size n to store the elements

        for (int i = 0; i < n; i++) { // Read the elements of the array and store them in the array
            array[i] = scanner.nextInt();
        }

        int choice = scanner.nextInt(); // Read the user choice to determine which method to call

        int result;
        if (choice == 1) { // If the user chooses the first method
            result = getMaxSumApproach1(array);
        } else { // If the user chooses the second method
            result = getMaxSumApproach2(array);
        }

        System.out.println("The maximum sum of non-adjacent elements is: " + result); // Print the result to the console