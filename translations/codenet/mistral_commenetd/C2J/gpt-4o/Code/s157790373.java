import java.util.Scanner;

public class SubsequenceChecker {
    static final int LEN = 300;
    static final int TRUE = 1;
    static final int FALSE = -1;

    static int n; // Size of the array A
    static int[] A = new int[LEN]; // Array to be checked
    static int flag; // Flag to check if a subsequence of given length m is found

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt(); // Reading the size of the array A
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt(); // Reading the elements of the array A
        }

        int q = scanner.nextInt(); // Reading the number of queries
        for (int i = 0; i < q; i++) { // Loop through all the queries
            int M = scanner.nextInt(); // Reading the length of subsequence to be checked in the current query
            flag = FALSE; // Initializing the flag to false

            solve(0, M); // Calling the function solve to check if there is a subsequence of given length M in the array A

            if (flag == TRUE) {
                System.out.println("yes"); // If a subsequence of given length M is found, print "yes"
            } else {
                System.out.println("no"); // If no subsequence of given length M is found, print "no"
            }
        }

        scanner.close();
    }

    static int solve(int i, int m) {
        // Base case: If index i goes beyond the size of the array A, return false as no subsequence can start from this index
        if (i >= n) return FALSE;

        // Base case: If length m is negative, return false
        if (m < 0) return FALSE;

        // Base case: If length m is zero, any empty subsequence of length zero can be formed from any index in the array A
        if (m == 0) {
            flag = TRUE; // Setting the flag to true as a subsequence of length m is found
            return TRUE; // Returning true to indicate that a subsequence of length m is found
        }

        // Recursive case: If length m cannot be formed from the element at index i, check if it can be formed from the elements starting from index i+1
        // Not using the element at index i to form the subsequence of length m
        solve(i + 1, m);

        // Using the element at index i to form the subsequence of length m
        solve(i + 1, m - A[i]);

        return FALSE; // Return FALSE if no valid subsequence is found
    }
}
// <END-OF-CODE>
