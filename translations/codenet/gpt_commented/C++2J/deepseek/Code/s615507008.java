import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Number of original time values
        long[] T = new long[N]; // Array to store the original time values
        for (int i = 0; i < N; i++) {
            T[i] = scanner.nextLong(); // Read the original time values into the array
        }

        int M = scanner.nextInt(); // Number of modifications
        int[] P = new int[M]; // Array to store the positions of modifications
        int[] X = new int[M]; // Array to store the new time values for modifications
        for (int i = 0; i < M; i++) {
            P[i] = scanner.nextInt() - 1; // Read the modification positions and new time values
            X[i] = scanner.nextInt(); // Read the modification positions and new time values
        }

        // Call the solve function to process the modifications and output results
        solve(N, T, M, P, X);
    }

    public static void solve(int N, long[] T, int M, int[] P, int[] X) {
        // Iterate over each modification request
        for (int i = 0; i < M; i++) {
            long ans = 0; // Initialize the answer for the current modification
            // Calculate the total time considering the current modification
            for (int j = 0; j < N; j++) {
                // If the current index matches the modified position, add the new time value
                if (j == P[i]) ans += X[i];
                // Otherwise, add the original time value
                else ans += T[j];
            }
            // Output the result for the current modification
            System.out.println(ans);
        }
    }
}
