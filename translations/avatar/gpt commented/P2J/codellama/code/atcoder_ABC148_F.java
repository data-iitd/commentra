
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ta = sc.nextInt();
        int ao = sc.nextInt();
        int[][] g = new int[n][n];
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            g[a - 1][b - 1] = 1;
            g[b - 1][a - 1] = 1;
        }
        int[] ta_dist = new int[n];
        int[] ao_dist = new int[n];
        ta_dist[ta - 1] = 0;
        ao_dist[ao - 1] = 0;
        dfs(g, ta_dist, ta - 1);
        dfs(g, ao_dist, ao - 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] > ao_dist[i]) {
                continue;
            }
            res = Math.max(res, ao_dist[i]);
        }
        System.out.println(res - 1);
    }

    public static void dfs(int[][] g, int[] dist, int node) {
        for (int v = 0; v < g.length; v++) {
            if (g[node][v] == 1 && dist[v] == 0) {
                dist[v] = dist[node] + 1;
                dfs(g, dist, v);
            }
        }
    }
}

