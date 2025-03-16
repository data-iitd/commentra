import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static ArrayList<P>[] G;
    static int[][] U;
    static int[] R;
    static long[] L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        G = new ArrayList[N];
        for (int i = 0; i < N; i++) G[i] = new ArrayList<>();
        for (int i = 0; i < N - 1; i++) {
            line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]) - 1;
            int v = Integer.parseInt(line[1]) - 1;
            G[u].add(new P(v, i));
            G[v].add(new P(u, i));
        }
        U = new int[MAX_L][N];
        R = new int[N];
        L = new long[N];
        solve();
    }

    static void solve() {
        // Write your code here
    }
}

