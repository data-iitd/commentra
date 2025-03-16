import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long[] T = new long[N];
        for (int i = 0; i < N; i++) {
            T[i] = sc.nextLong();
        }
        long M = sc.nextLong();
        long[] P = new long[M];
        long[] X = new long[M];
        for (int i = 0; i < M; i++) {
            P[i] = sc.nextLong();
            X[i] = sc.nextLong();
        }
        solve(N, T, M, P, X);
    }

    // Function to solve the problem based on the given parameters
    public static void solve(long N, long[] T, long M, long[] P, long[] X) {
        // Iterate over each modification request
        for (int i = 0; i < M; i++) {
            long ans = 0; // Initialize the answer for the current modification
            // Calculate the total time considering the current modification
            for (int j = 0; j < N; j++) {
                // If the current index matches the modified position, add the new time value
                if (j == P[i] - 1) ans += X[i];
                // Otherwise, add the original time value
                else ans += T[j];
            }
            // Output the result for the current modification
            System.out.println(ans);
        }
    }
}

