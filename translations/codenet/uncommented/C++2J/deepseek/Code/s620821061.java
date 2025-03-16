import java.util.*;

public class Main {
    static class BitMatching {
        private final List<Integer>[] graph;
        private final int[] match;
        private final boolean[] used;

        @SuppressWarnings("unchecked")
        public BitMatching(int V) {
            graph = new List[2 * V];
            for (int i = 0; i < 2 * V; i++) {
                graph[i] = new ArrayList<>();
            }
            match = new int[2 * V];
            used = new boolean[2 * V];
            Arrays.fill(match, -1);
        }

        public void addEdge(int a, int b) {
            graph[a].add(b + V);
            graph[b + V].add(a);
        }

        private boolean dfs(int v) {
            used[v] = true;
            for (int u : graph[v]) {
                int w = match[u];
                if (w < 0 || (!used[w] && dfs(w))) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
            return false;
        }

        public int execute() {
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
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            if (n == 0) break;
            BitMatching bm = new BitMatching(n);
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
                        bm.addEdge(i, j);
                    }
                }
            }
            System.out.println(bm.execute());
        }
        scanner.close();
    }

    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
