// Importing java.util.Scanner for reading input from standard input.
import java.util.Scanner;

// Function to solve the problem
void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    void rec(int[] A) {
        // Nonlocal variable to update the result from the recursive calls
        int res = 0;

        // Base case: if all elements of A are placed, calculate the answer
        if (A.length == N) {
            int ans = 0;
            for (int i = 0; i < Q; i++) {
                // Check if the condition is satisfied
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];
                }
            }
            // Update the result with the maximum answer
            res = Math.max(res, ans);
            return;
        }

        // Recursive call: try placing elements from last_max to M
        int last_max = 1;
        if (A.length > 0) {
            last_max = A[A.length - 1];
        }
        for (int i = last_max; i <= M; i++) {
            rec(A);
        }
    }

    // Call the helper function with an empty list
    rec(new int[0]);

    // Print the result
    System.out.println(res);
}

// Main function to read input and call the solve function
void main() {
    // Function to generate tokens from standard input
    Scanner sc = new Scanner(System.in);

    // Read input tokens
    int N = sc.nextInt();
    int M = sc.nextInt();
    int Q = sc.nextInt();

    // Read the arrays a, b, c, and d
    int[] a = new int[Q];
    int[] b = new int[Q];
    int[] c = new int[Q];
    int[] d = new int[Q];
    for (int i = 0; i < Q; i++) {
        a[i] = sc.nextInt();
        b[i] = sc.nextInt();
        c[i] = sc.nextInt();
        d[i] = sc.nextInt();
    }

    // Call the solve function with the given input
    solve(N, M, Q, a, b, c, d);
}

// Run the main function if the script is executed directly
if (true) {
    main();
}

