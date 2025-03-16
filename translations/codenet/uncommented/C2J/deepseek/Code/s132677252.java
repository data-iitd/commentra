public class Main {
    static class DirectedEdge {
        int vertex;
        int next;
    }

    static class DirectedGraph {
        DirectedEdge[] edge;
        int[] start;
        int pointer;
        int vertexNum;
        int edgeMaxSize;
    }

    static class Node {
        int one;
        int zero;
    }

    static class Deque {
        Node[] array;
        int front;
        int last;
        int mask;
    }

    static final int mod = 1000000007;

    static int modPow(int r, int n) {
        int t = 1;
        int s = r;
        while (n > 0) {
            if ((n & 1) != 0) t = (int) ((long) t * s % mod);
            s = (int) ((long) s * s % mod);
            n >>= 1;
        }
        return t;
    }

    static Node merge(Node[] a, int n) {
        long one = 0;
        long zero = 1;
        long total = 1;
        for (int i = 0; i < n; ++i) {
            one = (one * a[i].zero + zero * a[i].one) % mod;
            zero = zero * a[i].zero % mod;
            total = total * (a[i].zero + a[i].one) % mod;
        }
        return new Node() {{
            one = (int) one;
            zero = (int) ((total + mod - one) % mod);
        }};
    }

    static Deque newDeque() {
        final int len = 2;
        Deque d = new Deque();
        d.array = new Node[len];
        d.front = d.last = 0;
        d.mask = len - 1;
        return d;
    }

    static void freeDeque(Deque d) {
        d.array = null;
    }

    static int getSize(Deque d) {
        return (d.last + (~d.front + 1)) & d.mask;
    }

    static void dequeRealloc(Deque d) {
        Node[] array = new Node[2 * (d.mask + 1)];
        int k = 0;
        for (int i = d.front; i != d.last; i = (i + 1) & d.mask) {
            array[k++] = d.array[i];
        }
        d.array = array;
        d.front = 0;
        d.last = k;
        d.mask = 2 * d.mask + 1;
    }

    static Node getAt(Deque d, int x) {
        return d.array[(d.front + x) & d.mask];
    }

    static void assignAt(Deque d, int x, Node v) {
        d.array[(d.front + x) & d.mask] = v;
    }

    static void pushFront(Deque d, Node v) {
        if (((d.last + 1) & d.mask) == d.front) {
            dequeRealloc(d);
        }
        d.front = (d.front + d.mask) & d.mask;
        d.array[d.front] = v;
    }

    static int compareDequeSize(Deque[] a, Deque[] b) {
        Deque p = a[0];
        Deque q = b[0];
        int d = getSize(p) - getSize(q);
        return d == 0 ? 0 : d > 0 ? -1 : 1;
    }

    static void run() {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] p = new int[n + 1];
        int[] depth = new int[n + 1];
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        DirectedGraph g = newDirectedGraph(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = scanner.nextInt();
            addEdge(g, p[i], i);
            depth[i] = depth[p[i]] + 1;
            cnt[depth[i]]++;
        }
        Deque[][] dp = new Deque[n + 1][];
        Deque[][] child = new Deque[n + 1][];
        Node[] lst = new Node[n + 1];
        for (int i = n; i >= 0; --i) {
            int v = i;
            if (g.start[v] == -1) {
                dp[v] = new Deque[]{newDeque()};
                pushFront(dp[v][0], new Node() {{one = 1; zero = 1;}});
                continue;
            }
            int len = 0;
            for (int p = g.start[v]; p != -1; p = g.edge[p].next) {
                int u = g.edge[p].vertex;
                child[len++] = dp[u];
            }
            if (len > 1) {
                java.util.Arrays.sort(child, 0, len, (a, b) -> compareDequeSize(a, b));
                for (int d = 0; d < getSize(child[1]); ++d) {
                    int j = 0;
                    for (; j < len && d < getSize(child[j]); ++j) {
                        lst[j] = getAt(child[j], d);
                    }
                    assignAt(child[0], d, merge(lst, j));
                }
                for (int j = 1; j < len; ++j) {
                    freeDeque(child[j]);
                }
            }
            dp[v] = child[0];
            pushFront(dp[v][0], new Node() {{one = 1; zero = 1;}});
        }
        long ans = 0;
        for (int i = 0; i < getSize(dp[0][0]); ++i) {
            ans += (long) modPow(2, n + 1 - cnt[i]) * getAt(dp[0][0], i).one % mod;
        }
        System.out.println(ans % mod);
    }

    static DirectedGraph newDirectedGraph(int vertexNum) {
        DirectedGraph g = new DirectedGraph();
        g.edge = new DirectedEdge[1];
        g.start = new int[vertexNum];
        g.pointer = 0;
        g.vertexNum = vertexNum;
        g.edgeMaxSize = 1;
        java.util.Arrays.fill(g.start, -1);
        return g;
    }

    static void addEdge(DirectedGraph g, int from, int to) {
        if (g.pointer == g.edgeMaxSize) {
            g.edgeMaxSize *= 2;
            g.edge = java.util.Arrays.copyOf(g.edge, g.edgeMaxSize);
        }
        g.edge[g.pointer] = new DirectedEdge() {{vertex = to; next = g.start[from];}};
        g.start[from] = g.pointer++;
    }

    public static void main(String[] args) {
        run();
    }
}
