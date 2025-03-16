import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Define a large constant for infinity
    static final int INF = (int) Math.pow(10, 11);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the first array A
        int A = scanner.nextInt();
        // Read the number of elements in the second array B
        int B = scanner.nextInt();
        // Read the number of queries Q
        int Q = scanner.nextInt();

        // Initialize the first array with boundary values
        int[] s = new int[A + 2];
        s[0] = -INF;
        s[A + 1] = INF;
        // Populate the first array with input values
        for (int i = 1; i <= A; i++) {
            s[i] = scanner.nextInt();
        }

        // Initialize the second array with boundary values
        int[] t = new int[B + 2];
        t[0] = -INF;
        t[B + 1] = INF;
        // Populate the second array with input values
        for (int i = 1; i <= B; i++) {
            t[i] = scanner.nextInt();
        }

        // Process each query
        for (int i = 0; i < Q; i++) {
            // Read the query value x
            int x = scanner.nextInt();
            // Find the position in the first array where x would fit
            int b = Arrays.binarySearch(s, x);
            if (b < 0) b = -b - 1; // If not found, get the insertion point
            int d = Arrays.binarySearch(t, x);
            if (d < 0) d = -d - 1; // If not found, get the insertion point

            // Initialize the result with infinity
            int res = INF;

            // Check the closest values in the first array
            for (int S : new int[]{s[b - 1], s[b]}) {
                // Check the closest values in the second array
                for (int T : new int[]{t[d - 1], t[d]}) {
                    // Calculate the distances for both possible paths
                    int d1 = abs(S - x) + abs(T - S);
                    int d2 = abs(T - x) + abs(S - T);
                    // Update the result with the minimum distance found
                    res = Math.min(res, Math.min(d1, d2));
                }
            }

            // Output the result for the current query
            System.out.println(res);
        }

        scanner.close();
    }

    // Function to calculate the absolute value
    static int abs(int x) {
        return Math.abs(x);
    }
}
// <END-OF-CODE>
