import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Input: This handles the input operation.
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long[] T = new long[N];
        REP(i, N) T[i] = sc.nextLong();
        long M = sc.nextLong();
        long[] P = new long[M];
        long[] X = new long[M];
        REP(i, M) {
            P[i] = sc.nextLong();
            X[i] = sc.nextLong();
        }
        // Solve: This handles the solve operation.
        solve(N, T, M, P, X);
    }

    public static void solve(long N, long[] T, long M, long[] P, long[] X) {
        // Solve function: This function processes the input data to calculate and output the results for each operation.
        REP(i, M) {
            // Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
            long ans = 0;
            REP(j, N) {
                if (j == P[i] - 1) ans += X[i];
                else ans += T[j];
            }
            System.out.println(ans);
        }
    }
}

