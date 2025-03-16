import java.util.Scanner;

public class Main {

    // Initialize a Scanner object for input
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        // Start a new thread to run the main logic of the program
        new Thread(null, new Main(), "", 128 * 1024 * 1024).start();
    }

    public void run() {
        // Read the number of elements from input
        int n = sc.nextInt();
        // Initialize an array to store the input elements
        int[] a = new int[n];
        
        // Populate the array with input values
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize variables to track costs and current positions for two directions
        long cost1 = 0;
        long cost2 = 0;
        int current1 = 0;
        int current2 = 0;
        
        // Arrays to store cumulative costs for both directions
        long[] dp1 = new long[n];
        long[] dp2 = new long[n];
        
        // Calculate cumulative costs from the start and end of the array
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            // Calculate cost moving from left to right
            cost1 += Math.abs(a[i] - current1);
            current1 = a[i];
            dp1[i] = cost1; // Store the cumulative cost for the left direction
            
            // Calculate cost moving from right to left
            cost2 += Math.abs(a[j] - current2);
            current2 = a[j];
            dp2[j] = cost2; // Store the cumulative cost for the right direction
        }

        // Output the total costs based on the position in the array
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                // For the first element, only consider the right direction
                System.out.println(dp2[i + 1] + Math.abs(a[1]));
            } else if (i == n - 1) {
                // For the last element, only consider the left direction
                System.out.println(dp1[i - 1] + Math.abs(a[i - 1]));
            } else {
                // For middle elements, combine costs from both directions
                System.out.println(dp1[i - 1] + dp2[i + 1] + Math.abs(a[i - 1] - a[i + 1]));
            }
        }
    }
}
