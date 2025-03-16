import java.util.*;
import java.io.*;

public class Main {
    static class P {
        int _1, _2;
        P(int _1, int _2) {
            this._1 = _1;
            this._2 = _2;
        }
    }

    static int N;
    static List<P>[] G;
    static int[][] U;
    static int[] R;
    static long[] L;
    static final int INF = 1145141919;
    static final int MOD = 1000000007;
    static final int MAX_L = 22;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        G = new ArrayList[100000];
        for (int i = 0; i < 100000; i++) {
            G[i] = new ArrayList<>();
        }
        U = new int[MAX_L][100000];
        R = new int[100000];
        L = new long[100000];

        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            G[a].add(new P(b, c));
            G[b].add(new P(a, c));
        }

        // Perform necessary operations
        // ...

        scanner.close();
    }
}
