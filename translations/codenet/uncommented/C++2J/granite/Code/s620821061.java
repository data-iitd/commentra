
import java.util.*;

class s620821061 {
    static final int V = 520;
    static List<Integer>[] G = new ArrayList[2*V];
    static int[] match = new int[2*V];
    static boolean[] used = new boolean[2*V];

    static void init() {
        for (int i = 0; i < 2*V; i++) {
            G[i] = new ArrayList<>();
        }
    }

    static void add(int a, int b) {
        G[a].add(b+V);
        G[b+V].add(a);
    }

    static boolean dfs(int v) {
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v].get(i), w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    static int exec() {
        int res = 0;
        Arrays.fill(match, -1);
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

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            if (n == 0) break;
            init();
            int[] a = new int[n];
            int[] b = new int[m];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j])!= 1) {
                        add(i, j);
                    }
                }
            }
            System.out.println(exec());
        }
    }
}

