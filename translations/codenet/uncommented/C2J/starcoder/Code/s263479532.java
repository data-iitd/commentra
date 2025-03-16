
import java.util.*;

public class Prim {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[][] G = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                G[i][j] = in.nextInt();
            }
        }
        System.out.println(prim(G, n));
    }

    public static int prim(int[][] G, int n) {
        int[] d = new int[n];
        int[] pi = new int[n];
        int[] color = new int[n];
        int u, v, mincost, sum = 0;
        for (int i = 0; i < n; i++) {
            d[i] = Integer.MAX_VALUE;
            pi[i] = NIL;
            color[i] = WHITE;
        }
        d[0] = 0;
        while (true) {
            mincost = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (color[i]!= BLACK && d[i] < mincost) {
                    mincost = d[i];
                    u = i;
                }
            }
            if (mincost == Integer.MAX_VALUE) break;
            color[u] = BLACK;
            for (v = 0; v < n; v++) {
                if (color[v]!= BLACK && G[u][v] < d[v] && G[u][v]!= -1) {
                    pi[v] = u;
                    d[v] = G[u][v];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (d[i]!= Integer.MAX_VALUE) sum += d[i];
        }
        return sum;
    }
}

