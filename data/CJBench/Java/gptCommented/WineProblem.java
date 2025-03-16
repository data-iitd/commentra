import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = scanner.nextInt();
        
        // Initialize an array to hold the input values
        int[] arr = new int[n];
        
        // Read the values into the array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Call the wpbu method to calculate the maximum profit
        int result = wpbu(arr);
        
        // Output the maximum profit
        System.out.println("Maximum profit: " + result);
        
        // Close the scanner to free up resources
        scanner.close();
    }

    public static int wpbu(int[] arr) {
        // Validate the input array to ensure it is not null or empty
        if (arr == null || arr.length == 0) {
            throw new IllegalArgumentException("Input array cannot be null or empty.");
        }
        
        // Get the length of the array
        int n = arr.length;
        
        // Create a 2D array to store the maximum profit values for subproblems
        int[][] strg = new int[n][n];
        
        // Iterate over the possible lengths of the subarrays (slides)
        for (int slide = 0; slide <= n - 1; slide++) {
            // Iterate over the starting index of the subarray
            for (int si = 0; si <= n - slide - 1; si++) {
                // Calculate the ending index of the subarray
                int ei = si + slide;
                
                // Calculate the current year based on the number of remaining items
                int year = (n - (ei - si + 1)) + 1;
                
                // If the subarray has only one item, calculate its profit
                if (si == ei) {
                    strg[si][ei] = arr[si] * year;
                } else {
                    // Calculate the profit if taking the start or the end item
                    int start = strg[si + 1][ei] + arr[si] * year; // Profit by taking the start item
                    int end = strg[si][ei - 1] + arr[ei] * year;   // Profit by taking the end item
                    
                    // Store the maximum profit in the DP table
                    strg[si][ei] = Math.max(start, end);
                }
            }
        }
        
        // Return the maximum profit obtainable from the entire array
        return strg[0][n - 1];
    }
}
