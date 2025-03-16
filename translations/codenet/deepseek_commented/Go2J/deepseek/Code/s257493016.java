import java.util.Arrays;
import java.util.Scanner;

public class Main {

    // Function to find the minimum value among a variable number of integers
    public static int min(int... n) {
        if (n.length == 0) {
            throw new IllegalArgumentException("len == 0"); // Throw exception if no arguments are provided
        }
        int r = n[0]; // Initialize result with the first element
        for (int i = 1; i < n.length; i++) {
            if (n[i] <= r) { // Update result if a smaller element is found
                r = n[i];
            }
        }
        return r; // Return the minimum value
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt(); // Read the value of H from standard input
        int N = scanner.nextInt(); // Read the value of N from standard input
        int[] dp = new int[H + 10001]; // Create an array for dynamic programming with a large initial value
        Arrays.fill(dp, 2100000000); // Initialize the array with a large value
        int amax = 0; // Initialize variable to keep track of the maximum attack value

        for (int i = 0; i < N; i++) {
            int A = scanner.nextInt(); // Read the attack value A from standard input
            int B = scanner.nextInt(); // Read the cost B from standard input
            if (A >= amax) {
                amax = A; // Update amax if the current attack value is greater than or equal to the current amax
            }
            dp[A] = Math.min(dp[A], B); // Update the cost for attack value A
            for (int j = A + 1; j <= H + A + 1; j++) {
                dp[j] = Math.min(dp[j], dp[j - A] + B); // Update the cost for all possible health values using the current attack
            }
        }
        scanner.close();

        int result = Integer.MAX_VALUE;
        for (int i = H; i <= H + amax; i++) {
            result = Math.min(result, dp[i]); // Find the minimum cost to reduce health H to zero or below
        }
        System.out.println(result); // Print the minimum cost
    }
}
