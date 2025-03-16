import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long N, K; // Declare variables for number of elements and steps
        long[] A = new long[200100]; // Array to store the input values
        long[] B = new long[200100]; // Array to track the first visit time to each position
        for (int i = 0; i < 200100; i++) {
            B[i] = -1; // Initialize to -1 to indicate unvisited positions
        }
        
        int now = 1; // Current position, starting at 1
        long cnt = 0; // Counter for the number of steps taken

        // Read the number of elements (N) and the number of steps (K)
        N = scanner.nextLong();
        K = scanner.nextLong();

        // Read the elements into array A
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong(); // Store input values in A, starting from index 1
        }

        // Mark the starting position as visited at step 0
        B[1] = 0; // Starting point is visited at step 0

        long j;
        // Traverse the positions based on the values in A
        for (j = 1; j <= K; j++) {
            now = (int) A[now]; // Move to the next position based on the current position

            // Check if the current position has been visited before
            if (B[now] == -1) {
                B[now] = j; // Mark the position with the current step count
            } else {
                // If the position has been visited, calculate the cycle length
                cnt = j; // Store the current step count
                break; // Exit the loop as we found a cycle
            }
        }

        // If we did not reach the maximum steps K
        if (j < K) {
            long tmp;
            // Calculate how many additional steps to take within the cycle
            tmp = (K - B[now]) % (cnt - B[now]);
            
            // Move to the final position after the calculated additional steps
            for (long step = 0; step < tmp; step++) {
                now = (int) A[now]; // Continue moving to the next position
            }
        }

        // Output the final position after all movements
        System.out.println(now);
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
