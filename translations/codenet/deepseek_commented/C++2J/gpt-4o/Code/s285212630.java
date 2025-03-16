import java.util.*;

public class Main {
    static final int MAX_L = 22;
    static long N;
    static List<Pair>[] G = new ArrayList[100000];
    static int[][] U = new int[MAX_L][100000];
    static int[] R = new int[100000];
    static long[] L = new long[100000];

    static class Pair {
        int _1, _2;
        Pair(int a, int b) {
            this._1 = a;
            this._2 = b;
        }
    }

    // Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
    static void dfs(int x, int p, int r, long l) {
        U[0][x] = p;
        R[x] = r;
        L[x] = l;
        for (Pair pp : G[x]) {
            int t = pp._1;
            if (t == p) continue;
            dfs(t, x, r + 1, l + pp._2);
        }
    }

    // Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
    static int lca(int a, int b) {
        if (R[a] > R[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        for (int k = 0; k < MAX_L; k++) {
            if ((R[a] - R[b] >> k & 1) == 1) {
                b = U[k][b];
            }
        }
        if (a == b) return a;
        for (int k = MAX_L - 1; k >= 0; k--) {
            if (U[k][a] != U[k][b]) {
                a = U[k][a];
                b = U[k][b];
            }
        }
        return U[0][a];
    }

    // Distance calculation function to find the distance between two nodes
    static long dist(int x, int y) {
        int g = lca(x, y);
        return L[x] + L[y] - 2 * L[g];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextLong();
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            if (G[a] == null) G[a] = new ArrayList<>();
            if (G[b] == null) G[b] = new ArrayList<>();
            G[a].add(new Pair(b, c));
            G[b].add(new Pair(a, c));
        }
        for (int i = 0; i < MAX_L; i++) {
            Arrays.fill(U[i], -1);
        }
        dfs(0, -1, 0, 0);
        for (int i = 0; i < MAX_L - 1; i++) {
            for (int v = 0; v < N; v++) {
                if (U[i][v] == -1) U[i + 1][v] = -1;
                else U[i + 1][v] = U[i][U[i][v]];
            }
        }
        int Q = scanner.nextInt();
        int K = scanner.nextInt() - 1;
        for (int i = 0; i < Q; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;
            System.out.println(dist(x, K) + dist(K, y));
        }
        scanner.close();
    }
}
// <END-OF-CODE>
