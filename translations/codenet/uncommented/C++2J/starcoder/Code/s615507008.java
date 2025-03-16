import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long N = in.nextLong();
        long[] T = new long[N];
        for (int i = 0; i < N; i++) {
            T[i] = in.nextLong();
        }
        long M = in.nextLong();
        long[] P = new long[M];
        long[] X = new long[M];
        for (int i = 0; i < M; i++) {
            P[i] = in.nextLong();
            X[i] = in.nextLong();
        }
        solve(N, T, M, P, X);
    }

    public static void solve(long N, long[] T, long M, long[] P, long[] X) {
        for (int i = 0; i < M; i++) {
            long ans = 0;
            for (int j = 0; j < N; j++) {
                if (j == P[i] - 1) ans += X[i];
                else ans += T[j];
            }
            System.out.println(ans);
        }
    }
}

