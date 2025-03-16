import java.util.*;
import java.io.*;

// Define a large constant for infinity
class Main {
    static final long inf = (long) 1e14;

    public static void main(String[] args) {
        // Initialize a scanner for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements and the value of x
        int n = scanner.nextInt();
        long x = scanner.nextInt();

        // Create an array to hold the input integers
        int[] a = new int[n];

        // Read n integers into the array a
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Create a copy of the array a for manipulation
        int[] v = Arrays.copyOf(a, n);

        // Initialize the answer to infinity
        long ans = inf;

        // Iterate over each possible k value
        for (int k = 0; k < n; k++) {
            long kans = 0; // Initialize the current answer for this k

            // Calculate the minimum values for the current k
            for (int i = 0; i < n; i++) {
                if (i - k < 0) {
                    // If i-k is out of bounds, use the wrapped index
                    v[i] = Math.min(v[i], a[(n + i - k) % n]);
                } else {
                    // Otherwise, use the normal index
                    v[i] = Math.min(v[i], a[i - k]);
                }
                // Accumulate the current answer
                kans += v[i];
            }

            // Update the overall answer with the minimum found so far
            ans = Math.min(ans, kans + k * x);
        }

        // Print the final answer
        System.out.println(ans);
    }

    // Utility functions can be added here if needed
}
