
import java.util.*;

public class Prim {

    public static void main(String[] args) {
        int n, G[][];
        int i, j;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        G = new int[n][n];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                G[i][j] = in.nextInt();
            }
        }
        System.out.println(prim(G, n));
    }

    public static int prim(int G[][], int n) {
        int u, i, v, mincost, d[] = new int[n], pi[] = new int[n], color[] = new int[n], sum = 0;
        for (u = 0; u < n; u++) {
            d[u] = Integer.MAX_VALUE;
            pi[u] = -1;
            color[u] = 0;
        }
        d[0] = 0;
        while (true) {
            mincost = Integer.MAX_VALUE;
            for (i = 0; i < n; i++) {
                if (color[i] == 0 && d[i] < mincost) {
                    mincost = d[i];
                    u = i;
                }
            }
            if (mincost == Integer.MAX_VALUE) break;
            color[u] = 1;
            for (v = 0; v < n; v++) {
                if (color[v] == 0 && G[u][v] < d[v] && G[u][v]!= -1) {
                    pi[v] = u;
                    d[v] = G[u][v];
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (d[i]!= Integer.MAX_VALUE) sum += d[i];
        }
        return sum;
    }
}

