
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] node = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            node[i] = new Node(sc.nextInt(), sc.nextInt(), i);
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.x - o2.x;
            }
        });
        Edge[] e = new Edge[n * 2];
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.y - o2.y;
            }
        });
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y);
        }
        Arrays.sort(e, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.val - o2.val;
            }
        });
        long ans = 0;
        for (int i = 0; i < cnt; i++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            if (findpar(u) == findpar(v)) continue;
            unite(u, v);
            ans += val;
        }
        System.out.println(ans);
    }

    static class Node {
        int x, y, id;

        public Node(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }
    }

    static class Edge {
        int u, v, val;

        public Edge(int u, int v, int val) {
            this.u = u;
            this.v = v;
            this.val = val;
        }
    }

    static int[] par = new int[100005];

    static void init() {
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    static int findpar(int x) {
        return par[x] = (par[x] == x ? x : findpar(par[x]));
    }

    static void unite(int x, int y) {
        x = findpar(x), y = findpar(y);
        if (x == y) return;
        par[x] = y;
    }

    static int n;

    static long ans = 0;

    static int cnt = 0;

    static Edge[] e = new Edge[n * 2];

    static Node[] node = new Node[n + 1];

    static {
        init();
    }

    static {
        for (int i = 1; i <= n; i++) {
            node[i] = new Node(sc.nextInt(), sc.nextInt(), i);
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.x - o2.x;
            }
        });
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.y - o2.y;
            }
        });
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y);
        }
        Arrays.sort(e, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.val - o2.val;
            }
        });
    }

    static {
        for (int i = 0; i < cnt; i++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            if (findpar(u) == findpar(v)) continue;
            unite(u, v);
            ans += val;
        }
    }

    static {
        System.out.println(ans);
    }
}

