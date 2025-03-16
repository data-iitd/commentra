import java.util.Scanner;

public class Main {
    // Function to solve the problem
    public static void solve(long N, long[] T, long M, long[] P, long[] X) {
        // Iterate through each query
        for (int i = 0; i < M; i++) {
            // Initialize the answer variable to zero
            long ans = 0;

            // Iterate through each element in T up to the position of the current query
            for (int j = 0; j < N; j++) {
                // If the current index j is equal to the position of the current query - 1
                if (j == P[i] - 1) {
                    // Add the value of X[i] to the answer variable
                    ans += X[i];
                } else {
                    // Otherwise, add the value of the current element in T to the answer variable
                    ans += T[j];
                }
            }

            // Print the answer for the current query
            System.out.println(ans);
        }
    }

    // Main function
    public static void main(String[] args) {
        // Initialize Scanner for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in T from the standard input
        long N = scanner.nextLong();

        // Initialize an array T of size N
        long[] T = new long[(int) N];

        // Read the elements of T from the standard input
        for (int i = 0; i < N; i++) {
            T[i] = scanner.nextLong();
        }

        // Read the number of queries from the standard input
        long M = scanner.nextLong();

        // Initialize arrays P and X of size M
        long[] P = new long[(int) M];
        long[] X = new long[(int) M];

        // Read the positions and values of the queries from the standard input
        for (int i = 0; i < M; i++) {
            P[i] = scanner.nextLong();
            X[i] = scanner.nextLong();
        }

        // Call the solve function with the given arguments
        solve(N, T, M, P, X);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
