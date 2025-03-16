import java.util.Scanner;

public class Main {
    // Function to solve the problem based on the given parameters
    public static void solve(long N, long[] T, long M, long[] P, long[] X) {
        // Iterate over each modification request
        for (int i = 0; i < M; i++) {
            long ans = 0; // Initialize the answer for the current modification
            // Calculate the total time considering the current modification
            for (int j = 0; j < N; j++) {
                // If the current index matches the modified position, add the new time value
                if (j == P[i] - 1) ans += X[i];
                // Otherwise, add the original time value
                else ans += T[j];
            }
            // Output the result for the current modification
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input

        long N; // Number of original time values
        N = scanner.nextLong(); // Read the number of time values
        long[] T = new long[(int) N]; // Array to store the original time values
        for (int i = 0; i < N; i++) T[i] = scanner.nextLong(); // Read the original time values into the array

        long M; // Number of modifications
        M = scanner.nextLong(); // Read the number of modifications
        long[] P = new long[(int) M]; // Array to store the positions of modifications
        long[] X = new long[(int) M]; // Array to store the new time values for modifications
        for (int i = 0; i < M; i++) {
            P[i] = scanner.nextLong(); // Read the modification positions
            X[i] = scanner.nextLong(); // Read the new time values
        }

        // Call the solve function to process the modifications and output results
        solve(N, T, M, P, X);
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
