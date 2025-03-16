// Importing Scanner class to read input from standard input.
import java.util.Scanner;

// Function to solve the problem
public static void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    public void rec(int[] A) {
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
        int last_max = 1 if (A.length == 0) else A[A.length - 1];
        for (int i = last_max; i <= M; i++) {
            rec(A + [i]);
        }
    }

    // Call the helper function with an empty list
    rec([]);

    // Print the result
    System.out.println(res);
}

// Main function to read input and call the solve function
public static void main(String[] args) {
    // Function to generate tokens from standard input
    public static String[] iterate_tokens() {
        Scanner sc = new Scanner(System.in);
        String[] tokens = sc.nextLine().split(" ");
        return tokens;
    }

    // Read input tokens
    String[] tokens = iterate_tokens();

    // Read number of test cases
    int N = Integer.parseInt(tokens[0]);

    // Read number of elements in the array and number of queries
    int M = Integer.parseInt(tokens[1]);
    int Q = Integer.parseInt(tokens[2]);

    // Read the arrays a, b, c, and d
    int[] a = new int[Q];
    int[] b = new int[Q];
    int[] c = new int[Q];
    int[] d = new int[Q];
    for (int i = 0; i < Q; i++) {
        a[i] = Integer.parseInt(tokens[3 + 4 * i]);
        b[i] = Integer.parseInt(tokens[3 + 4 * i + 1]);
        c[i] = Integer.parseInt(tokens[3 + 4 * i + 2]);
        d[i] = Integer.parseInt(tokens[3 + 4 * i + 3]);
    }

    // Call the solve function with the given input
    solve(N, M, Q, a, b, c, d);
}

