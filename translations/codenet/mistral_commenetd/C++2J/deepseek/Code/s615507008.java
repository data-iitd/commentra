import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in T
        int N = scanner.nextInt();

        // Initialize a list T of size N
        List<Long> T = new ArrayList<>();

        // Read the elements of T from the standard input
        for (int i = 0; i < N; i++) {
            T.add(scanner.nextLong());
        }

        // Read the number of queries from the standard input
        int M = scanner.nextInt();

        // Initialize lists P and X of size M
        List<Long> P = new ArrayList<>();
        List<Long> X = new ArrayList<>();

        // Read the positions and values of the queries from the standard input
        for (int i = 0; i < M; i++) {
            P.add(scanner.nextLong());
            X.add(scanner.nextLong());
        }

        // Call the solve function with the given arguments
        solve(N, T, M, P, X);
    }

    // Function to solve the problem
    public static void solve(int N, List<Long> T, int M, List<Long> P, List<Long> X) {
        // Iterate through each query
        for (int i = 0; i < M; i++) {
            // Initialize the answer variable to zero
            long ans = 0;

            // Iterate through each element in T
            for (int j = 0; j < N; j++) {
                // If the current index j is equal to the position of the current query - 1
                if (j == P.get(i) - 1) {
                    // Add the value of X.get(i) to the answer variable
                    ans += X.get(i);
                }
                // Otherwise, add the value of the current element in T to the answer variable
                else {
                    ans += T.get(j);
                }
            }

            // Print the answer for the current query
            System.out.println(ans);
        }
    }
}
