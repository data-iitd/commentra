// Import necessary packages
import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        // Create a scanner to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of test cases N
        int N = scanner.nextInt();

        // Read an array h of N integers
        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt();
        }

        // Initialize a dp array of size N with zeros
        int[] dp = new int[N];
        dp[0] = 0; // The first element is 0 as we start there
        if (N > 1) {
            dp[1] = Math.abs(h[0] - h[1]); // Set the first element of dp to the absolute difference between the first and second elements of h
        }

        // Iterate over the array h from the second element to the last
        for (int i = 2; i < N; i++) {
            // Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
            dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]), dp[i - 2] + Math.abs(h[i] - h[i - 2]));
        }

        // Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
        System.out.println(dp[N - 1]);

        // Close the scanner
        scanner.close();
    }
}
