
import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int x, y, id;
    }

    static class Edge {
        int u, v, val;
        public Edge(int u, int v, int val) {
            this.u = u;
            this.v = v;
            this.val = val;
        }
        public boolean equals(Object obj) {
            Edge e = (Edge)obj;
            return this.val == e.val;
        }
        public int compareTo(Edge e) {
            return this.val - e.val;
        }
    }

    static int n;
    static Node node[] = new Node[maxn];
    static Edge e[] = new Edge[maxn << 1];

    static int par[] = new int[maxn];

    static void init() {
        for (int i = 0; i <= n; i ++)
            par[i] = i;
    }

    static int findpar(int x) {
        return par[x] = (par[x] == x? x : findpar(par[x]));
    }

    static void unite(int x, int y) {
        x = findpar(x), y = findpar(y);
        if (x == y) return;
        par[x] = y;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        init();
        for (int i = 1; i <= n; i ++) {
            node[i] = new Node();
            node[i].x = sc.nextInt();
            node[i].y = sc.nextInt();
            node[i].id = i;
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            public int compare(Node a, Node b) {
                return a.x - b.x;
            }
        });
        int cnt = 0;
        for (int i = 2; i <= n; i ++)
            e[cnt ++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            public int compare(Node a, Node b) {
                return a.y - b.y;
            }
        });
        for (int i = 2; i <= n; i ++)
            e[cnt ++] = new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y);
        Arrays.sort(e, 0, cnt);
        long ans = 0;
        for (int i = 0; i < cnt; i ++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            if (findpar(u) == findpar(v)) continue;
            unite(u, v);
            ans += val;
        }
        System.out.println(ans);
    }
}

