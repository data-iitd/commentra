import java.util.Scanner;

public class PrimAlgorithm {
    static final int MAX = 100;
    static final int INF = 999999;
    static final int NIL = -1;
    static final int WHITE = 0;
    static final int BLACK = 2;

    static int n;
    static int[][] G = new int[MAX][MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                G[i][j] = scanner.nextInt();
            }
        }
        
        System.out.println(prim());
        
        scanner.close();
    }

    static int prim() {
        int u, i, v, mincost, sum = 0;
        int[] d = new int[n];
        int[] pi = new int[n];
        int[] color = new int[n];

        for (u = 0; u < n; u++) {
            d[u] = INF;
            pi[u] = NIL;
            color[u] = WHITE;
        }

        d[0] = 0;
        while (true) {
            mincost = INF;

            for (i = 0; i < n; i++) {
                if (color[i] != BLACK && d[i] < mincost) {
                    mincost = d[i];
                    u = i;
                }
            }

            if (mincost == INF) break;

            color[u] = BLACK;

            for (v = 0; v < n; v++) {
                if (color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1) {
                    pi[v] = u;
                    d[v] = G[u][v];
                }
            }
        }

        for (i = 0; i < n; i++) {
            if (d[i] != INF) sum += d[i];
        }

        return sum;
    }
}

// <END-OF-CODE>
