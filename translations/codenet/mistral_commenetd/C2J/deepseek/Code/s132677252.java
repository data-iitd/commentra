import java.util.*;

public class Main {
    static class GraphEdge {
        int vertex;
        int next;
    }

    static class DirectedGraph {
        GraphEdge[] edge;
        int[] start;
        int pointer;
        int vertexNum;
        int edgeMaxSize;
    }

    static class Node {
        int one;
        int zero;
    }

    static DirectedGraph newGraph(int vertexNum) {
        DirectedGraph g = new DirectedGraph();
        g.edge = new GraphEdge[1];
        g.edge[0] = new GraphEdge();
        g.start = new int[vertexNum];
        Arrays.fill(g.start, -1);
        g.pointer = 0;
        g.vertexNum = vertexNum;
        g.edgeMaxSize = 1;
        return g;
    }

    static void addEdge(DirectedGraph g, int from, int to) {
        if (g.pointer == g.edgeMaxSize) {
            g.edgeMaxSize *= 2;
            g.edge = Arrays.copyOf(g.edge, g.edgeMaxSize);
        }
        g.edge[g.pointer] = new GraphEdge();
        g.edge[g.pointer].vertex = to;
        g.edge[g.pointer].next = g.start[from];
        g.start[from] = g.pointer++;
    }

    static final int mod = 1000000007;

    static int modPow(int r, int n) {
        long t = 1;
        long s = r;
        while (n > 0) {
            if ((n & 1) != 0) t = t * s % mod;
            s = s * s % mod;
            n >>= 1;
        }
        return (int) t;
    }

    static class DequeNode {
        Node value;
    }

    static class Deque {
        DequeNode[] array;
        int front;
        int last;
        int mask;
    }

    static Deque newDeque() {
        Deque d = new Deque();
        d.array = new DequeNode[2];
        d.array[0] = new DequeNode();
        d.front = d.last = 0;
        d.mask = 1;
        return d;
    }

    static void freeDeque(Deque d) {
        d.array = null;
    }

    static int getSize(Deque d) {
        return (d.last + (~d.front + 1)) & d.mask;
    }

    static void dequeRealloc(Deque d) {
        DequeNode[] array = new DequeNode[2 * (d.mask + 1)];
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
        return d.array[(d.front + x) & d.mask].value;
    }

    static void assignAt(Deque d, int x, Node v) {
        d.array[(d.front + x) & d.mask].value = v;
    }

    static void pushFront(Deque d, Node v) {
        if (((d.last + 1) & d.mask) == d.front) {
            dequeRealloc(d);
        }
        d.front = (d.front + d.mask) & d.mask;
        d.array[d.front] = new DequeNode();
        d.array[d.front].value = v;
    }

    static int cmpDequeSize(Deque[] a, Deque[] b) {
        int d = getSize(a[0]) - getSize(b[0]);
        return d == 0 ? 0 : d > 0 ? -1 : 1;
    }

    static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] p = new int[n + 1];
        int[] depth = new int[n + 1];
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        DirectedGraph g = newGraph(n + 1);
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
                dp[v] = new Deque[1];
                dp[v][0] = newDeque();
                pushFront(dp[v][0], new Node());
                dp[v][0][0].one = 1;
                dp[v][0][0].zero = 1;
                continue;
            }
            List<Deque> childList = new ArrayList<>();
            for (int p = g.start[v]; p != -1; p = g.edge[p].next) {
                int u = g.edge[p].vertex;
                childList.add(dp[u][0]);
            }
            if (childList.size() > 1) {
                childList.sort(Main::cmpDequeSize);
                for (int d = 0; d < getSize(childList.get(1)); ++d) {
                    int j = 0;
                    for (; j < childList.size() && d < getSize(childList.get(j)); ++j) {
                        lst[j] = getAt(childList.get(j), d);
                    }
                    assignAt(childList.get(0), d, merge(lst, j));
                }
                for (int j = 1; j < childList.size(); ++j) {
                    freeDeque(childList.get(j));
                }
            }
            dp[v] = new Deque[1];
            dp[v][0] = childList.get(0);
            pushFront(dp[v][0], new Node());
            dp[v][0][0].one = 1;
            dp[v][0][0].zero = 1;
        }
        long ans = 0;
        for (int i = 0; i < getSize(dp[0][0]); ++i) {
            ans += (long) modPow(2, n + 1 - cnt[i]) * getAt(dp[0][0], i).one % mod;
        }
        System.out.println(ans % mod);
    }

    public static void main(String[] args) {
        run();
    }
}
