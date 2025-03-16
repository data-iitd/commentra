import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    // BufferedReader for reading input
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer tokenizer;

    // Method to read the next integer from input
    private static int nextInt() throws IOException {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return Integer.parseInt(tokenizer.nextToken());
    }

    // Method to solve the problem
    private static void solve() throws IOException {
        int N = nextInt(); // Read number of elements
        int[] A = new int[N]; // Create an array to hold the elements
        for (int i = 0; i < N; i++) {
            A[i] = nextInt(); // Read each element into the array
        }

        int maxProfit = 0; // Initialize maximum profit
        int maxCnt = 0;    // Initialize count of maximum profit occurrences
        int maxA = A[N - 1]; // Start with the last element as the maximum

        for (int i = N - 2; i >= 0; i--) { // Iterate backwards through the array
            int profit = Math.max(0, maxA - A[i]); // Calculate profit based on the current element
            if (maxProfit < profit) { // If we found a new maximum profit
                maxProfit = profit; // Update maximum profit
                maxCnt = 1; // Reset count to 1
            } else if (maxProfit == profit) { // If we found another occurrence of the maximum profit
                maxCnt++; // Increment the count
            }
            maxA = Math.max(maxA, A[i]); // Update the maximum element seen so far
        }
        System.out.println(maxCnt); // Output the count of maximum profit occurrences
    }

    // Main method to execute the program
    public static void main(String[] args) throws IOException {
        solve(); // Call the solve function
    }
}

// <END-OF-CODE>
