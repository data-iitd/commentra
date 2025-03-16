
import java.util.Scanner;

public class Main {
    public static void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        int res = 0; // Initialize the result variable to store the maximum score

        // Define the recursive function to generate sequences
        void rec(int[] A) {
            if (A.length == N) { // If the sequence length is equal to N
                int ans = 0; // Initialize the answer for this sequence
                for (int i = 0; i < Q; i++) { // Iterate over all constraints
                    if (A[b[i] - 1] - A[a[i] - 1] == c[i]) { // Check if the constraint is satisfied
                        ans += d[i]; // Add the value of the constraint to the answer
                    }
                }
                res = Math.max(res, ans); // Update the result with the maximum score
                return;
            }
            int last_max = 1; // Determine the starting point for the next number
            if (A.length == 0) {
                last_max = 1;
            } else {
                last_max = A[A.length - 1] + 1;
            }
            for (int i = last_max; i <= M; i++) { // Generate the next number in the sequence
                rec(A);
            }
        }

        rec(new int[0]); // Start the recursive function with an empty list
        System.out.println(res); // Print the result
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the value of N
        int M = scanner.nextInt(); // Read the value of M
        int Q = scanner.nextInt(); // Read the value of Q
        int[] a = new int[Q]; // Read the list a
        int[] b = new int[Q]; // Read the list b
        int[] c = new int[Q]; // Read the list c
        int[] d = new int[Q]; // Read the list d
        for (int i = 0; i < Q; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = scanner.nextInt();
            d[i] = scanner.nextInt();
        }
        solve(N, M, Q, a, b, c, d); // Call the solve function with the input values
    }
}

