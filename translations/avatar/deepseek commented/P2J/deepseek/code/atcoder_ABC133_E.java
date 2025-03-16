import java.util.*;

public class Main {
    static final int MOD = (int) (1e9 + 7);
    static List<List<Integer>> graph = new ArrayList<>();
    static int N, K;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        long result = dfs(0, -1, K);
        System.out.println(result);
    }

    private static long dfs(int fro, int to, int f) {
        long caseNum = f;
        int colorNum = f == K ? K - 1 : K - 2;

        for (int u : graph.get(fro)) {
            if (u == to) continue;
            long pat = dfs(u, fro, colorNum);
            if (pat == 0) {
                caseNum = 0;
                break;
            }
            caseNum = caseNum * pat % MOD;
            colorNum--;
        }
        return caseNum;
    }
}
