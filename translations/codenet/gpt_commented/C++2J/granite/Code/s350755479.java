
import java.io.*;
import java.util.*;

public class s350755479{
    static class Node implements Comparable<Node> {
        int x, y, id;

        public Node(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }

        @Override
        public int compareTo(Node o) {
            return this.x - o.x;
        }
    }

    static class Edge implements Comparable<Edge> {
        int u, v, val;

        public Edge(int u, int v, int val) {
            this.u = u;
            this.v = v;
            this.val = val;
        }

        @Override
        public int compareTo(Edge o) {
            return this.val - o.val;
        }
    }

    static int[] par;
    static int n;

    static void init() {
        par = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    static int findpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = findpar(par[x]);
    }

    static void unite(int x, int y) {
        int rx = findpar(x);
        int ry = findpar(y);
        if (rx == ry) {
            return;
        }
        par[rx] = ry;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            String[] strs = br.readLine().split(" ");
            int x = Integer.parseInt(strs[0]);
            int y = Integer.parseInt(strs[1]);
            nodes[i] = new Node(x, y, i);
        }
        Arrays.sort(nodes, 1, n + 1);
        Edge[] edges = new Edge[2 * n - 1];
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            edges[cnt++] = new Edge(nodes[i - 1].id, nodes[i].id, nodes[i].x - nodes[i - 1].x);
        }
        Arrays.sort(nodes, 1, n + 1, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.y - o2.y;
            }
        });
        for (int i = 2; i <= n; i++) {
            edges[cnt++] = new Edge(nodes[i - 1].id, nodes[i].id, nodes[i].y - nodes[i - 1].y);
        }
        Arrays.sort(edges);
        init();
        long ans = 0;
        for (int i = 0; i < cnt; i++) {
            Edge edge = edges[i];
            if (findpar(edge.u)!= findpar(edge.v)) {
                unite(edge.u, edge.v);
                ans += edge.val;
            }
        }
        System.out.println(ans);
    }
}

