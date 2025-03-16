
import java.util.*;
import java.io.*;

class s615507008 {
    public static void main(String[] args) throws IOException {
        // s615507008 function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());
        String[] T_input = br.readLine().split(" ");
        long[] T = new long[(int)N];
        for (int i = 0; i < N; i++) {
            T[i] = Long.parseLong(T_input[i]);
        }
        long M = Long.parseLong(br.readLine());
        String[] P_input = br.readLine().split(" ");
        String[] X_input = br.readLine().split(" ");
        long[] P = new long[(int)M];
        long[] X = new long[(int)M];
        for (int i = 0; i < M; i++) {
            P[i] = Long.parseLong(P_input[i]);
            X[i] = Long.parseLong(X_input[i]);
        }
        solve(N, T, M, P, X);
    }

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
}

Translate the above Java code to Python and end with comment "