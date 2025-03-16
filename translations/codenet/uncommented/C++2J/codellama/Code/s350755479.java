
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] node = new Node[n + 1];
        for (int i = 1; i <= n; i ++) {
            node[i] = new Node();
            node[i].x = sc.nextInt();
            node[i].y = sc.nextInt();
            node[i].id = i;
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.x - o2.x;
            }
        });
        int cnt = 0;
        for (int i = 2; i <= n; i ++) {
            e[cnt ++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.y - o2.y;
            }
        });
        for (int i = 2; i <= n; i ++) {
            e[cnt ++] = new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y);
        }
        Arrays.sort(e, 0, cnt, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.val - o2.val;
            }
        });
        long ans = 0;
        for (int i = 0; i < cnt; i ++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            if (findpar(u) == findpar(v)) continue;
            unite(u, v);
            ans += val;
        }
        System.out.println(ans);
    }

    static class Node {
        int x, y, id;
    }

    static class Edge {
        int u, v, val;
        Edge(int u, int v, int val) {
            this.u = u;
            this.v = v;
            this.val = val;
        }
    }

    static int[] par = new int[maxn];
    static int n;
    static Edge[] e = new Edge[maxn << 1];

    static void init() {
        for (int i = 0; i <= n; i ++)
            par[i] = i;
    }

    static int findpar(int x) {
        return par[x] = (par[x] == x ? x : findpar(par[x]));
    }

    static void unite(int x, int y) {
        x = findpar(x), y = findpar(y);
        if (x == y) return;
        par[x] = y;
    }

    static final int maxn = 1e5 + 5;

    // 