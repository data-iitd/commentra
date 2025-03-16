
import java.util.Scanner;

public class s375567191{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] g = new int[n][n];
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt();
            for (int j = 0; j < y; j++) {
                int z = scanner.nextInt() - 1;
                g[x][z] = 1;
            }
        }
        dfs(g);
    }

    static int time = 0;
    static int[] d = new int[101];
    static int[] f = new int[101];
    static int[] color = new int[101];

    static void visit(int u) {
        color[u] = 1;
        d[u] = ++time;
        for (int i = 0; i < n; i++) {
            if (g[u][i] == 0) {
                continue;
            }
            if (color[i] == 0) {
                visit(i);
            }
        }
        color[u] = 2;
        f[u] = ++time;
    }

    static void dfs() {
        time = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                visit(i);
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
        }
    }
}

