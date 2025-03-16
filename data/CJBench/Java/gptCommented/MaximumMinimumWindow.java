import java.util.Scanner;
import java.util.Stack;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to calculate the maximum of minimums for all window sizes
    public static int[] calculateMaxOfMin(int[] arr, int n) {
        // Stack to store indices of array elements
        Stack<Integer> s = new Stack<>();
        // Arrays to store the nearest smaller elements to the left and right
        int[] left = new int[n];
        int[] right = new int[n];
        // Result array to store the maximum of minimums for each window size
        int[] ans = new int[n + 1];

        // Initialize left and right arrays
        for (int i = 0; i < n; i++) {
            left[i] = -1; // Default value for left
            right[i] = n; // Default value for right
        }

        // Fill the left array with indices of the nearest smaller elements
        for (int i = 0; i < n; i++) {
            // Pop elements from the stack while the current element is smaller
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            // If stack is not empty, the top element is the nearest smaller element
            if (!s.isEmpty()) {
                left[i] = s.peek();
            }
            // Push the current index onto the stack
            s.push(i);
        }

        // Clear the stack to reuse it for the right array
        s.clear(); 

        // Fill the right array with indices of the nearest smaller elements
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack while the current element is smaller
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            // If stack is not empty, the top element is the nearest smaller element
            if (!s.isEmpty()) {
                right[i] = s.peek();
            }
            // Push the current index onto the stack
            s.push(i);
        }

        // Calculate the maximum of minimums for each window size
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1; // Calculate the length of the window
            ans[len] = Math.max(ans[len], arr[i]); // Update the maximum for this window size
        }

        // Fill in the result array to ensure each index has the maximum of minimums
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = Math.max(ans[i], ans[i + 1]); // Ensure non-increasing order
        }

        return ans; // Return the result array
    }

    public static void main(String[] args) {
        // Create a scanner to read input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array
        int[] arr = new int[n]; // Initialize the array

        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Calculate the result using the calculateMaxOfMin method
        int[] result = calculateMaxOfMin(arr, n);

        // Print the result for each window size
        for (int i = 1; i <= n; i++) {
            System.out.print(result[i] + " ");
        }

        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
