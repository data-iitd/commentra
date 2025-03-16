
import java.util.*;

// Function to solve the problem based on the given parameters
public class s615507008{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Number of original time values
        long[] T = new long[N]; // Array to store the original time values
        for (int i = 0; i < N; i++) T[i] = sc.nextLong(); // Read the original time values into the array

        int M = sc.nextInt(); // Number of modifications
        int[] P = new int[M]; // Array to store the positions of modifications
        long[] X = new long[M]; // Array to store the new time values for modifications
        for (int i = 0; i < M; i++) {
            P[i] = sc.nextInt(); // Read the modification positions
            X[i] = sc.nextLong(); // Read the new time values for modifications
        }

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
}

