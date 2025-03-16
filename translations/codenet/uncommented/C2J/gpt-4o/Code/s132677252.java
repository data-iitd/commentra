import java.util.*;

public class DirectedGraph {
    static final int MOD = 1000000007;

    static class GraphEdge {
        int vertex;
        int next;

        GraphEdge(int vertex, int next) {
            this.vertex = vertex;
            this.next = next;
        }
    }

    static class Graph {
        GraphEdge[] edge;
        int[] start;
        int pointer;
        int vertexNum;
        int edgeMaxSize;

        Graph(int vertexNum) {
            this.vertexNum = vertexNum;
            this.edge = new GraphEdge[1];
            this.start = new int[vertexNum];
            this.pointer = 0;
            this.edgeMaxSize = 1;
            Arrays.fill(this.start, -1);
        }

        void addEdge(int from, int to) {
            if (pointer == edgeMaxSize) {
                edgeMaxSize *= 2;
                edge = Arrays.copyOf(edge, edgeMaxSize);
            }
            edge[pointer] = new GraphEdge(to, start[from]);
            start[from] = pointer++;
        }
    }

    static class Node {
        int one;
        int zero;

        Node(int one, int zero) {
            this.one = one;
            this.zero = zero;
        }
    }

    static Node merge(Node[] a, int n) {
        long one = 0;
        long zero = 1;
        long total = 1;
        for (int i = 0; i < n; i++) {
            one = (one * a[i].zero + zero * a[i].one) % MOD;
            zero = zero * a[i].zero % MOD;
            total = total * (a[i].zero + a[i].one) % MOD;
        }
        return new Node((int) one, (int) ((total + MOD - one) % MOD));
    }

    static class Deque {
        Node[] array;
        int front;
        int last;
        int mask;

        Deque() {
            int len = 2;
            this.array = new Node[len];
            this.front = this.last = 0;
            this.mask = len - 1;
        }

        int getSize() {
            return (last + (~front + 1)) & mask;
        }

        void realloc() {
            Node[] newArray = new Node[2 * (mask + 1)];
            int k = 0;
            for (int i = front; i != last; i = (i + 1) & mask) {
                newArray[k++] = array[i];
            }
            array = newArray;
            front = 0;
            last = k;
            mask = 2 * mask + 1;
        }

        Node getAt(int x) {
            return array[(front + x) & mask];
        }

        void assignAt(int x, Node v) {
            array[(front + x) & mask] = v;
        }

        void pushFront(Node v) {
            if (((last + 1) & mask) == front) {
                realloc();
            }
            front = (front + mask) & mask;
            array[front] = v;
        }
    }

    static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] p = new int[n + 1];
        int[] depth = new int[n + 1];
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        Graph g = new Graph(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = scanner.nextInt();
            g.addEdge(p[i], i);
            depth[i] = depth[p[i]] + 1;
            cnt[depth[i]]++;
        }
        Deque[] dp = new Deque[n + 1];
        Deque[] child = new Deque[n + 1];
        Node[] lst = new Node[n + 1];
        for (int i = n; i >= 0; i--) {
            int v = i;
            if (g.start[v] == -1) {
                dp[v] = new Deque();
                dp[v].pushFront(new Node(1, 1));
                continue;
            }
            int len = 0;
            for (int pIdx = g.start[v]; pIdx != -1; pIdx = g.edge[pIdx].next) {
                int u = g.edge[pIdx].vertex;
                child[len++] = dp[u];
            }
            if (len > 1) {
                Arrays.sort(child, 0, len, (a, b) -> Integer.compare(b.getSize(), a.getSize()));
                for (int d = 0; d < child[1].getSize(); d++) {
                    int j = 0;
                    for (; j < len && d < child[j].getSize(); j++) {
                        lst[j] = child[j].getAt(d);
                    }
                    child[0].assignAt(d, merge(lst, j));
                }
                for (int j = 1; j < len; j++) {
                    child[j] = null; // Freeing the deque
                }
            }
            dp[v] = child[0];
            dp[v].pushFront(new Node(1, 1));
        }
        long ans = 0;
        for (int i = 0; i < dp[0].getSize(); i++) {
            ans += (long) modPow(2, n + 1 - cnt[i]) * dp[0].getAt(i).one % MOD;
        }
        System.out.println(ans % MOD);
    }

    static int modPow(int r, int n) {
        long t = 1;
        long s = r;
        while (n > 0) {
            if ((n & 1) != 0) t = t * s % MOD;
            s = s * s % MOD;
            n >>= 1;
        }
        return (int) t;
    }

    public static void main(String[] args) {
        run();
    }
}

// <END-OF-CODE>
