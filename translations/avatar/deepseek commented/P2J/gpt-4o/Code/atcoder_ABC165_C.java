import java.util.*;

public class Main {
    static int res;  // Variable to store the maximum score

    public static void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        res = 0;  // Initialize the result variable

        // Define the recursive function to generate sequences
        rec(new ArrayList<>(), N, M, Q, a, b, c, d);
        System.out.println(res);  // Print the result
    }

    private static void rec(List<Integer> A, int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        if (A.size() == N) {  // If the sequence length is equal to N
            int ans = 0;  // Initialize the answer for this sequence
            for (int i = 0; i < Q; i++) {  // Iterate over all constraints
                if (A.get(b[i] - 1) - A.get(a[i] - 1) == c[i]) {  // Check if the constraint is satisfied
                    ans += d[i];  // Add the value of the constraint to the answer
                }
            }
            res = Math.max(res, ans);  // Update the result with the maximum score
            return;
        }
        int lastMax = A.isEmpty() ? 1 : A.get(A.size() - 1);  // Determine the starting point for the next number
        for (int i = lastMax; i <= M; i++) {  // Generate the next number in the sequence
            List<Integer> newA = new ArrayList<>(A);
            newA.add(i);
            rec(newA, N, M, Q, a, b, c, d);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Read the value of N
        int M = scanner.nextInt();  // Read the value of M
        int Q = scanner.nextInt();  // Read the value of Q
        int[] a = new int[Q];  // Initialize the list a
        int[] b = new int[Q];  // Initialize the list b
        int[] c = new int[Q];  // Initialize the list c
        int[] d = new int[Q];  // Initialize the list d

        for (int i = 0; i < Q; i++) {
            a[i] = scanner.nextInt();  // Read the list a
        }
        for (int i = 0; i < Q; i++) {
            b[i] = scanner.nextInt();  // Read the list b
        }
        for (int i = 0; i < Q; i++) {
            c[i] = scanner.nextInt();  // Read the list c
        }
        for (int i = 0; i < Q; i++) {
            d[i] = scanner.nextInt();  // Read the list d
        }
        solve(N, M, Q, a, b, c, d);  // Call the solve function with the input values
    }
}

// <END-OF-CODE>
