// Importing necessary packages
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Main function declaration
    public static void main(String[] args) {
        final int INF = (int) Math.pow(10, 11); // Large constant value for initializing arrays

        // Reading input values from standard input
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int Q = scanner.nextInt();

        // Initializing arrays s and t with size A+2 and B+2 respectively
        // The first and last elements are initialized with -INF and INF respectively
        int[] s = new int[A + 2];
        s[0] = -INF;
        s[A + 1] = INF;

        // Reading A elements of array s from standard input
        for (int i = 1; i <= A; i++) {
            s[i] = scanner.nextInt();
        }

        // Initializing array t with size B+2
        // The first and last elements are initialized with -INF and INF respectively
        int[] t = new int[B + 2];
        t[0] = -INF;
        t[B + 1] = INF;

        // Reading B elements of array t from standard input
        for (int i = 1; i <= B; i++) {
            t[i] = scanner.nextInt();
        }

        // Processing each query
        for (int i = 0; i < Q; i++) {
            // Reading query value x from standard input
            int x = scanner.nextInt();

            // Finding the indices b and d of array s and t respectively
            // where s[b] and t[d] are the smallest elements greater than x
            int b = Arrays.binarySearch(s, x);
            if (b < 0) b = -b - 1; // If not found, get the insertion point
            int d = Arrays.binarySearch(t, x);
            if (d < 0) d = -d - 1; // If not found, get the insertion point

            // Computing the minimum distance between x and any pair of elements S and T
            // from arrays s and t respectively
            int res = INF;
            for (int S : new int[]{s[b - 1], s[b]}) {
                for (int T : new int[]{t[d - 1], t[d]}) {
                    // Computing the absolute difference between S and x, and T and S
                    int d1 = Math.abs(S - x);
                    int d2 = Math.abs(T - S);

                    // Updating the minimum distance if the current pair has a smaller distance
                    res = Math.min(res, Math.min(d1, d2));
                }
            }

            // Printing the minimum distance for the current query
            System.out.println(res);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
