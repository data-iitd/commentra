import java.util.Scanner; // Importing Scanner class for input

public final class Main {
    private Main() {
    } // Private constructor to prevent instantiation

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int n = scanner.nextInt(); // Read the size of the array
        int[] arr = new int[n]; // Initialize the array with size n
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt(); // Fill the array with n integers
        }
        int result = wpbu(arr); // Call the wpbu method to calculate the maximum profit
        System.out.println("Maximum profit: " + result); // Print the maximum profit
        scanner.close(); // Close the Scanner to free up resources
    }

    public static int wpbu(int[] arr) {
        if (arr == null || arr.length == 0) {
            throw new IllegalArgumentException("Input array cannot be null or empty."); // Check for null or empty array
        }
        int n = arr.length; // Get the length of the array
        int[][] strg = new int[n][n]; // Initialize a 2D array to store maximum profit
        for (int slide = 0; slide <= n - 1; slide++) {
            for (int si = 0; si <= n - slide - 1; si++) {
                int ei = si + slide; // Calculate end index for the current subarray
                int year = (n - (ei - si + 1)) + 1; // Calculate the current year
                if (si == ei) {
                    strg[si][ei] = arr[si] * year; // Base case: single element subarray
                } else {
                    int start = strg[si + 1][ei] + arr[si] * year; // Calculate profit if starting from si
                    int end = strg[si][ei - 1] + arr[ei] * year; // Calculate profit if ending at ei
                    strg[si][ei] = Math.max(start, end); // Store the maximum profit for the current subarray
                }
            }
        }
        return strg[0][n - 1]; // Return the maximum profit for the entire array
    }
}
