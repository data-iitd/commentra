import java.util.Scanner;

public class DepthFirstSearch {
    static final int N = 100;
    static final int WHITE = 0;
    static final int GRAY = 1;
    static final int BLACK = 2;

    static int[][] M = new int[N][N];
    static int n;
    static int[] color = new int[N];
    static int[] d = new int[N];
    static int[] f = new int[N];
    static int tt;

    static void dfsVisit(int u) {
        color[u] = GRAY;
        d[u] = ++tt;
        for (int v = 0; v < n; v++) {
            if (M[u][v] == 0)
                continue;
            if (color[v] == WHITE) {
                dfsVisit(v);
            }
        }
        color[u] = BLACK;
        f[u] = ++tt;
    }

    static void dfs() {
        for (int i = 0; i < n; i++) {
            color[i] = WHITE;
        }
        tt = 0;

        for (int u = 0; u < n; u++) {
            if (color[u] == WHITE)
                dfsVisit(u);
        }

        for (int i = 0; i < n; i++)
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k, u, v;
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
        }
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt() - 1;
            k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt() - 1;
                M[u][v] = 1;
            }
        }

        dfs();
        scanner.close();
    }
}

// <END-OF-CODE>
