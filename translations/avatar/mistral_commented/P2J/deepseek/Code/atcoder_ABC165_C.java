import java.util.*;

public class Main {
    // Function to solve the problem
    public static void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        // Initialize result to 0
        int res = 0;

        // Helper function to calculate the answer recursively
        class Rec {
            void rec(List<Integer> A) {
                // Nonlocal variable to update the result from the recursive calls
                if (A.size() == N) {
                    int ans = 0;
                    for (int i = 0; i < Q; i++) {
                        // Check if the condition is satisfied
                        if (A.get(b[i] - 1) - A.get(a[i] - 1) == c[i]) {
                            ans += d[i];
                        }
                    }
                    // Update the result with the maximum answer
                    res = Math.max(res, ans);
                    return;
                }

                // Recursive call: try placing elements from last_max to M
                int last_max = A.isEmpty() ? 1 : A.get(A.size() - 1);
                for (int i = last_max; i <= M; i++) {
                    List<Integer> newA = new ArrayList<>(A);
                    newA.add(i);
                    rec(newA);
                }
            }
        }

        // Call the helper function with an empty list
        new Rec().rec(new ArrayList<>());

        // Print the result
        System.out.println(res);
    }

    // Main function to read input and call the solve function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read number of test cases
        int N = scanner.nextInt();

        // Read number of elements in the array and number of queries
        int M = scanner.nextInt();
        int Q = scanner.nextInt();

        // Read the arrays a, b, c, and d
        int[] a = new int[Q];
        int[] b = new int[Q];
        int[] c = new int[Q];
        int[] d = new int[Q];
        for (int i = 0; i < Q; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = scanner.nextInt();
            d[i] = scanner.nextInt();
        }

        // Call the solve function with the given input
        solve(N, M, Q, a, b, c, d);
    }
}
