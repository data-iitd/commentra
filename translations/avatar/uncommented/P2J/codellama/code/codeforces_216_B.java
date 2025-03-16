import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] g = new int[n + 1][n + 1];
            for (int i = 0; i < m; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                g[a][b] = 1;
                g[b][a] = 1;
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (g[i][i] == 0) {
                    int nodes = 0;
                    int edges = 0;
                    for (int j = 1; j <= n; j++) {
                        if (g[i][j] == 1) {
                            nodes++;
                            edges += g[j][j];
                        }
                    }
                    if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                        ans++;
                    }
                }
            }
            if ((n - ans) % 2 == 1) {
                ans++;
            }
            System.out.println(ans);
        }
    }
}
