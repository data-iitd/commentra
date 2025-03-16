public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long N = scanner.nextLong(); // Number of elements
        long K = scanner.nextLong(); // Number of steps
        long[] A = new long[(int) (200100)]; // Array to store the input values
        long[] B = new long[200100]; // Array to track the first visit time to each position
        int now = 1; // Current position, starting at 1
        long cnt = 0; // Counter for the number of steps taken

        // Read the elements into array A
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        // Initialize array B to -1 to indicate unvisited positions
        for (int i = 0; i < 200100; i++) {
            B[i] = -1;
        }

        // Mark the starting position as visited at step 0
        B[1] = 0; // Starting point is visited at step 0

        // Traverse the positions based on the values in A
        for (long j = 1; j <= K; j++) {
            now = (int) A[(int) now]; // Move to the next position based on the current position

            // Check if the current position has been visited before
            if (B[(int) now] == -1) {
                B[(int) now] = j; // Mark the position with the current step count
            } else {
                // If the position has been visited, calculate the cycle length
                cnt = j; // Store the current step count
                break; // Exit the loop as we found a cycle
            }
        }

        // If we did not reach the maximum steps K
        if (cnt != 0) {
            long tmp;
            // Calculate how many additional steps to take within the cycle
            tmp = (K - B[(int) now]) % (cnt - B[(int) now]);

            // Move to the final position after the calculated additional steps
            for (long j = 0; j < tmp; j++) {
                now = (int) A[(int) now]; // Continue moving to the next position
            }
        }

        // Output the final position after all movements
        System.out.println(now); // End of the program
    }
}
