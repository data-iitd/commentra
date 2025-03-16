import java.util.Scanner;

public class SubsetSum {
    // Constants
    static final int LEN = 300;
    static final int TRUE = 1;
    static final int FALSE = -1;

    // Global variables
    static int n;
    static int[] A = new int[LEN];
    static int flag;

    public static void main(String[] args) {
        // Scanner for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        n = scanner.nextInt();
        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Read the number of queries
        int q = scanner.nextInt();
        // Iterate over each query
        for (int i = 0; i < q; i++) {
            // Read the target sum for the current query
            int M = scanner.nextInt();
            // Initialize the flag to FALSE
            flag = FALSE;

            // Call the solve function to find a subset that sums up to M
            solve(-1, M);
            // Print "yes" if a subset is found, otherwise print "no"
            if (flag == TRUE) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

        scanner.close();
    }

    // Recursive function to find a subset that sums up to m
    static int solve(int i, int m) {
        // Base case: if index i exceeds the number of elements, return FALSE
        if (i >= n) return FALSE;
        // If the remaining sum m is negative, return FALSE
        else if (m < 0) return FALSE;
        // If the remaining sum m is zero or the current element A[i] equals m, set flag to TRUE and return TRUE
        else if (m == 0 || m - A[i + 1] == 0) {
            flag = TRUE;
            return TRUE;
        } else {
            // Recursive call without using the current element A[i]
            solve(i + 1, m);
            // Recursive call using the current element A[i]
            solve(i + 1, m - A[i]);
        }
        return FALSE; // Return FALSE if no subset found
    }
}
// <END-OF-CODE>
