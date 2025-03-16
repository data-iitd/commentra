import java.util.*;

public class Main {
    static List<List<Integer>> graph = new ArrayList<>();
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Initialize the graph
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        long ans = dfs(0, -1, K);
        System.out.println(ans);
    }

    static long dfs(int fro, int to, int f) {
        long caseNum = f;
        int colorNum = (f == K) ? K - 1 : K - 2;

        for (int u : graph.get(fro)) {
            if (u == to) {
                continue;
            }
            long pat = dfs(u, fro, colorNum);
            if (pat == 0) {
                caseNum = 0;
                break;
            }
            caseNum = (caseNum * pat) % MOD;
            colorNum--;
        }
        return caseNum;
    }
}
// <END-OF-CODE>
