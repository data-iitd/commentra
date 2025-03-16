import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements in T from the standard input
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();

        // Initialize a vector T of size N
        long[] T = new long[N];

        // Read the elements of T from the standard input
        for (int i = 0; i < N; i++) {
            T[i] = sc.nextLong();
        }

        // Read the number of queries from the standard input
        long M = sc.nextLong();

        // Initialize vectors P and X of size M
        long[] P = new long[M], X = new long[M];

        // Read the positions and values of the queries from the standard input
        for (int i = 0; i < M; i++) {
            P[i] = sc.nextLong();
            X[i] = sc.nextLong();
        }

        // Call the solve function with the given arguments
        solve(N, T, M, P, X);
    }

    // Function to solve the problem
    public static void solve(long N, // Number of elements in T
                            long[] T, // Input vector T
                            long M, // Number of queries
                            long[] P, // Position of each query
                            long[] X // Value of each query
                            ) {
        // Initialize a variable to store the answer for each query
        long ans = 0;

        // Iterate through each query
        for (int i = 0; i < M; i++) {
            // Initialize the answer variable to zero
            ans = 0;

            // Iterate through each element in T up to the position of the current query
            for (int j = 0; j < N; j++) {
                // If the current index j is equal to the position of the current query - 1
                if (j == P[i] - 1) {
                    // Add the value of X[i] to the answer variable
                    ans += X[i];
                }
                // Otherwise, add the value of the current element in T to the answer variable
                else {
                    ans += T[j];
                }
            }

            // Print the answer for the current query
            System.out.println(ans);
        }
    }
}

