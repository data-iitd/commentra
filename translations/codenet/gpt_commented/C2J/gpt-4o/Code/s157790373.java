import java.util.Scanner;

public class SubsetSum {
    static final int LEN = 300;
    static final int TRUE = 1;
    static final int FALSE = -1;

    static int n; // Number of elements
    static int[] A = new int[LEN]; // Array of elements
    static int flag; // Flag to indicate if a solution is found

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the array
        n = scanner.nextInt();
        // Read the elements into the array A
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Read the number of queries
        int q = scanner.nextInt();
        // Process each query
        for (int i = 0; i < q; i++) {
            // Read the target sum for the current query
            int M = scanner.nextInt();
            flag = FALSE; // Reset flag for each query

            // Call the solve function to check if a subset sums to M
            solve(-1, M);
            // Output the result based on the flag
            if (flag == TRUE) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

        scanner.close(); // Close the scanner
    }

    // Recursive function to determine if a subset of A can sum to m
    static int solve(int i, int m) {
        // Base case: if index exceeds the number of elements
        if (i >= n) return FALSE;
        // Base case: if the remaining sum is negative
        else if (m < 0) return FALSE;
        // Base case: if the remaining sum is zero (solution found)
        else if (m == 0 || (i + 1 < n && m - A[i + 1] == 0)) {
            flag = TRUE; // Set flag to TRUE indicating a solution is found
            return TRUE; // Return TRUE
        } else {
            // Recursive case: do not use the current element A[i]
            solve(i + 1, m);
            // Recursive case: use the current element A[i]
            solve(i + 1, m - A[i]);
        }
        return FALSE; // Return FALSE if no solution is found
    }
}
// <END-OF-CODE>
