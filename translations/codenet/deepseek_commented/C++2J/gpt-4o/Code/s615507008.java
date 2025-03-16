import java.util.Scanner;

public class Main {
    // Main class: This is the entry point of the program.

    public static void solve(long N, long[] T, long M, long[] P, long[] X) {
        // Solve function: This function processes the input data to calculate and output the results for each operation.
        for (int i = 0; i < M; i++) {
            // Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
            long ans = 0;
            for (int j = 0; j < N; j++) {
                if (j == P[i] - 1) ans += X[i];
                else ans += T[j];
            }
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        // Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long[] T = new long[(int) N];
        for (int i = 0; i < N; i++) {
            T[i] = scanner.nextLong();
        }
        long M = scanner.nextLong();
        long[] P = new long[(int) M];
        long[] X = new long[(int) M];
        for (int i = 0; i < M; i++) {
            P[i] = scanner.nextLong();
            X[i] = scanner.nextLong();
        }
        solve(N, T, M, P, X);
        scanner.close();
    }
}

// <END-OF-CODE>
