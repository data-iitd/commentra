import java.util.*;

public class Main {
    // Define constants for large values and mathematical constants
    static final int inf = (int) 1e9 + 7;
    static final long mod = (long) 1e9 + 7;
    static final long mod1 = 998244353;
    static final long big = (long) 1e18;
    static final double PI = 2 * Math.asin(1);

    public static void main(String[] args) {
        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize a list to store the elements
        List<Long> A = new ArrayList<>(N);

        // Input the elements into the list
        for (int i = 0; i < N; ++i) {
            A.add(scanner.nextLong());
        }

        // Sort the list in descending order
        A.sort(Collections.reverseOrder());

        // Initialize variables to track the minimum difference and the corresponding index
        int index = -1;
        long maxDiff = inf;

        // Find the element in the list that minimizes the difference with twice the second largest element
        for (int i = 1; i < N; ++i) {
            // Calculate the absolute difference and update if it's smaller than the current max
            long diff = Math.abs(A.get(0) - 2 * A.get(i));
            if (maxDiff > diff) {
                maxDiff = diff;
                index = i; // Store the index of the element that gives the minimum difference
            }
        }

        // Output the largest element and the element that minimizes the difference
        System.out.println(A.get(0) + " " + A.get(index));
    }
}

// <END-OF-CODE>
