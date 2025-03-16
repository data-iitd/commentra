import java.util.*;

public class BitMatching {
    private static final int V = 520;
    private static final int MAX_V = 2 * V;
    private static int[] match = new int[MAX_V];
    private static boolean[] used = new boolean[MAX_V];
    private static List<Integer>[] G = new List[MAX_V];

    static {
        for (int i = 0; i < MAX_V; i++) {
            G[i] = new ArrayList<>();
        }
    }

    public static void init() {
        for (int i = 0; i < MAX_V; i++) {
            G[i].clear();
        }
        Arrays.fill(match, -1);
    }

    public static void add(int a, int b) {
        G[a].add(b + V);
        G[b + V].add(a);
    }

    private static boolean dfs(int v) {
        used[v] = true;
        for (int u : G[v]) {
            int w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    public static int exec() {
        int res = 0;
        for (int v = 0; v < V; v++) {
            if (match[v] < 0) {
                Arrays.fill(used, false);
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }

    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            if (n == 0) break;
            init();
            int[] a = new int[n];
            int[] b = new int[m];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j]) != 1) {
                        add(i, j);
                    }
                }
            }
            System.out.println(exec());
        }
        scanner.close();
    }
}
