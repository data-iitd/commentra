import java.util.Scanner;

public class DFS {
    static final int MAX = 101;
    static final int WHITE = 0;
    static final int BLACK = 2;
    static final int GRAY = 1;

    static int time;
    static int n;
    static int[][] g = new int[MAX][MAX];
    static int[] d = new int[MAX];
    static int[] f = new int[MAX];
    static int[] color = new int[MAX];

    static void visit(int u) {
        color[u] = GRAY;
        d[u] = ++time;

        for (int i = 0; i < n; i++) {
            if (g[u][i] == 0)
                continue;
            if (color[i] == WHITE)
                visit(i);
        }

        color[u] = BLACK;
        f[u] = ++time;
    }

    static void dfs() {
        time = 0;

        for (int i = 0; i < n; i++) {
            if (color[i] == WHITE)
                visit(i);
        }

        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            for (int j = 0; j < y; j++) {
                int z = scanner.nextInt();
                g[x - 1][z - 1] = 1;
            }
        }

        dfs();
        scanner.close();
    }
}
