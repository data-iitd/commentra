import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int mod = 1000000007;
        int[][] graph = new int[N][N];
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }

        int ans = dfs(graph, 0, K, mod);
        System.out.println(ans);
    }

    public static int dfs(int[][] graph, int fro, int f, int mod) {
        int caseNum = f;
        int colorNum = K - 1;
        if (f == K) {
            colorNum = K - 2;
        }
        for (int u = 0; u < graph.length; u++) {
            if (graph[fro][u] == 1) {
                int pat = dfs(graph, u, colorNum, mod);
                if (pat == 0) {
                    caseNum = 0;
                    break;
                }
                caseNum = (caseNum * pat) % mod;
                colorNum--;
            }
        }
        return caseNum;
    }
}

