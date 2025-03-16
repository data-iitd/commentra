import java.util.Arrays;
import java.util.Scanner;

public class Main {

    // min function returns the minimum value from a variable number of integer arguments.
    // It throws an IllegalArgumentException if no arguments are provided.
    public static int min(int... n) {
        if (n.length == 0) {
            throw new IllegalArgumentException("len == 0"); // Ensure there is at least one argument
        }
        int r = n[0]; // Initialize the result with the first argument
        // Iterate through the remaining arguments to find the minimum
        for (int i = 1; i < n.length; i++) {
            if (n[i] <= r) {
                r = n[i]; // Update the result if a smaller value is found
            }
        }
        return r; // Return the minimum value found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int N = scanner.nextInt();

        // Initialize a dynamic programming array to store the minimum cost for each height
        int[] dp = new int[H + 10001];
        // Set initial values to a large number (infinity) for all heights
        Arrays.fill(dp, 2100000000); // Represents a large value (infinity)

        int amax = 0; // Variable to track the maximum height of items
        // Process each item
        for (int i = 0; i < N; i++) {
            // Read the height A and cost B of the current item
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            // Update amax if the current item's height is greater
            if (A >= amax) {
                amax = A;
            }
            // Update the minimum cost for achieving height A
            dp[A] = Math.min(dp[A], B);
            // Update the minimum cost for all heights from A+1 to H+A+1
            for (int j = A + 1; j <= H + amax + 1; j++) {
                dp[j] = Math.min(dp[j], dp[j - A] + B); // Calculate the minimum cost for height j
            }
        }

        // Print the minimum cost to achieve height H considering all possible heights up to amax
        int[] dpSubset = Arrays.copyOfRange(dp, H, H + amax + 1);
        System.out.println(min(dpSubset));
    }
}
