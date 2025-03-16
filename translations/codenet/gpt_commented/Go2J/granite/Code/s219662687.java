
import java.util.*;

public class s219662687{
    public static void main(String[] args) {
        // Define a large constant for infinity
        final int INF = (int)Math.pow(10, 11);

        // Read the number of elements in the first array A and initialize it
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        // Read the number of elements in the second array B
        int B = sc.nextInt();
        // Read the number of queries Q
        int Q = sc.nextInt();

        // Initialize the first array with boundary values
        int[] s = new int[A+2];
        s[0] = -INF; s[A+1] = INF;
        // Populate the first array with input values
        for (int i = 1; i <= A; i++) {
            s[i] = sc.nextInt();
        }

        // Initialize the second array with boundary values
        int[] t = new int[B+2];
        t[0] = -INF; t[B+1] = INF;
        // Populate the second array with input values
        for (int i = 1; i <= B; i++) {
            t[i] = sc.nextInt();
        }

        // Process each query
        for (int i = 0; i < Q; i++) {
            // Read the query value x
            int x = sc.nextInt();
            // Find the position in the first array where x would fit
            int b = Arrays.binarySearch(s, x);
            int d = Arrays.binarySearch(t, x);
            // Initialize the result with infinity
            int res = INF;

            // Check the closest values in the first array
            for (int S : new int[]{s[b-1], s[b]}) {
                // Check the closest values in the second array
                for (int T : new int[]{t[d-1], t[d]}) {
                    // Calculate the distances for both possible paths
                    int d1 = Math.abs(S-x) + Math.abs(T-S);
                    int d2 = Math.abs(T-x) + Math.abs(S-T);
                    // Update the result with the minimum distance found
                    res = Math.min(res, Math.min(d1, d2));
                }
            }

            // Output the result for the current query
            System.out.println(res);
        }
    }
}

// Utility functions. ----------

// Function to calculate the absolute value
int abs(int x) {
    return (int)Math.abs(x);
}

// Function to find the minimum of two integers
int min(int x, int y) {
    return (int)Math.min(x, y);
}

// Function to find the maximum of two integers
int max(int x, int y) {
    return (int)Math.max(x, y);
}

// ---------- Utility functions.

// End of code.
