
import java.util.Scanner;

public class s069149000{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] G = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int e = scanner.nextInt();
                if (e == -1) {
                    G[i][j] = Integer.MAX_VALUE;
                } else {
                    G[i][j] = e;
                }
            }
        }
        prim(G, n);
    }

    public static void prim(int[][] G, int n) {
        int[] d = new int[n];
        int[] pi = new int[n];
        int[] color = new int[n];
        int min, u, v, sum = 0;

        for (int i = 0; i < n; i++) {
            d[i] = Integer.MAX_VALUE;
            pi[i] = -1;
            color[i] = 0;
        }

        d[0] = 0;

        while (true) {
            min = Integer.MAX_VALUE;
            u = -1;
            for (int i = 0; i < n; i++) {
                if (color[i]!= 2 && d[i] < min) {
                    min = d[i];
                    u = i;
                }
            }
            if (u == -1) {
                break;
            }
            color[u] = 2;
            for (int v = 0; v < n; v++) {
                if (color[v]!= 2 && G[u][v]!= Integer.MAX_VALUE) {
                    if (d[v] > G[u][v]) {
                        d[v] = G[u][v];
                        pi[v] = u;
                        color[v] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (pi[i]!= -1) {
                sum += G[i][pi[i]];
            }
        }

        System.out.println(sum);
    }
}
