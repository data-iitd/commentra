
import java.util.Scanner;

public class s263479532{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] G = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                G[i][j] = scanner.nextInt();
            }
        }
        System.out.println(prim(G));
    }

    public static int prim(int[][] G) {
        int n = G.length;
        int[] d = new int[n];
        int[] pi = new int[n];
        int[] color = new int[n];
        int sum = 0;

        for (int u = 0; u < n; u++) {
            d[u] = Integer.MAX_VALUE;
            pi[u] = -1;
            color[u] = 0; // WHITE
        }

        d[0] = 0;

        while (true) {
            int minCost = Integer.MAX_VALUE;
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (color[i]!= 2 && d[i] < minCost) {
                    minCost = d[i];
                    u = i;
                }
            }

            if (minCost == Integer.MAX_VALUE) break;

            color[u] = 2; // BLACK

            for (int v = 0; v < n; v++) {
                if (color[v]!= 2 && G[u][v] < d[v] && G[u][v]!= -1) {
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

