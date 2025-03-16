
import java.util.*;

public class atcoder_ABC133_E{
    static final int MOD = 100000007;
    static int ans = 1;
    static int n, k;
    static List<Integer>[] graph;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            graph[a].add(b);
            graph[b].add(a);
        }
        dfs(0, -1, k);
        System.out.println(ans);
    }

    public static void dfs(int cur, int parent, int color) {
        int caseNum = color;
        int colorNum = k - 1;
        if (color == k) {
            colorNum--;
        }
        for (int next : graph[cur]) {
            if (next == parent) {
                continue;
            }
            dfs(next, cur, colorNum);
            caseNum = (int) ((long) caseNum * ans % MOD);
            colorNum--;
        }
        ans = caseNum;
    }
}

Translate the above Java code to C++ and end with comment "