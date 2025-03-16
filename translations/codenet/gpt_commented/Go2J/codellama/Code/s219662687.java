
import java.util.Scanner;
import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {
        // Define a large constant for infinity
        int INF = (int) Math.pow(10, 11);

        // Read the number of elements in the first array A and initialize it
        int A = nextInt();
        // Read the number of elements in the second array B
        int B = nextInt();
        // Read the number of queries Q
        int Q = nextInt();

        // Initialize the first array with boundary values
        int[] s = new int[A + 2];
        s[0] = -INF;
        s[A + 1] = INF;
        // Populate the first array with input values
        for (int i = 1; i <= A; i++) {
            s[i] = nextInt();
        }

        // Initialize the second array with boundary values
        int[] t = new int[B + 2];
        t[0] = -INF;
        t[B + 1] = INF;
        // Populate the second array with input values
        for (int i = 1; i <= B; i++) {
            t[i] = nextInt();
        }

        // Process each query
        for (int i = 0; i < Q; i++) {
            // Read the query value x
            int x = nextInt();
            // Find the position in the first array where x would fit
            int b = Arrays.binarySearch(s, x);
            int d = Arrays.binarySearch(t, x);
            // Initialize the result with infinity
            int res = INF;

            // Check the closest values in the first array
            for (int S : new int[] { s[b - 1], s[b] }) {
                // Check the closest values in the second array
                for (int T : new int[] { t[d - 1], t[d] }) {
                    // Calculate the distances for both possible paths
                    int d1 = Math.abs(S - x) + Math.abs(T - S);
                    int d2 = Math.abs(T - x) + Math.abs(S - T);
                    // Update the result with the minimum distance found
                    res = Math.min(res, Math.min(d1, d2));
                }
            }

            // Output the result for the current query
            System.out.println(res);
        }
    }

    // Function to read the next integer from input
    public static int nextInt() {
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    // Function to read the next float from input
    public static float nextFloat() {
        Scanner sc = new Scanner(System.in);
        return sc.nextFloat();
    }

    // Function to read the next string from input
    public static String nextString() {
        Scanner sc = new Scanner(System.in);
        return sc.next();
    }
}

