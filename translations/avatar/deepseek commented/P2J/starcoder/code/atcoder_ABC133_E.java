import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[][] graph = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = sc.nextInt();
            }
        }
        int mod = (int) 1e9 + 7;
        int ans = dfs(graph, 0, -1, K, mod);
        System.out.println(ans);
    }

    public static int dfs(int[][] graph, int fro, int to, int f, int mod) {
        int caseNum = f;
        int colorNum = K - 1;
        if (f == K) {
            colorNum--;
        }
        for (int u : graph[fro]) {
            if (u == to) {
                continue;
            }
            int pat = dfs(graph, u, fro, colorNum, mod);
            if (pat == 0) {
                caseNum = 0;
                break;
            }
            caseNum = (caseNum * pat) % mod;
            colorNum--;
        }
        return caseNum;
    }
}

