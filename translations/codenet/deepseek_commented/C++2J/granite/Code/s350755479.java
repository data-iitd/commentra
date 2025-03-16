
import java.util.*;
import java.io.*;

public class s350755479{

    static class Node implements Comparable<Node> {
        int x, y, id;

        public Node(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }

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

        public int compareTo(Edge o) {
            return this.val - o.val;
        }
    }

    static int[] par;

    static int findpar(int x) {
        if (par[x] == x) return x;
        return par[x] = findpar(par[x]);
    }

    static void unite(int x, int y) {
        x = findpar(x);
        y = findpar(y);
        if (x == y) return;
        par[x] = y;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            String[] strs = br.readLine().split(" ");
            int x = Integer.parseInt(strs[0]);
            int y = Integer.parseInt(strs[1]);
            nodes[i] = new Node(x, y, i);
        }
        Arrays.sort(nodes);
        Edge[] edges = new Edge[2 * n - 1];
        for (int i = 0; i < n - 1; i++) {
            edges[i] = new Edge(nodes[i].id, nodes[i + 1].id, nodes[i + 1].x - nodes[i].x);
        }
        Arrays.sort(nodes, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.y - o2.y;
            }
        });
        for (int i = 0; i < n - 1; i++) {
            edges[i + n - 1] = new Edge(nodes[i].id, nodes[i + 1].id, nodes[i + 1].y - nodes[i].y);
        }
        Arrays.sort(edges);
        par = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        long ans = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            Edge e = edges[i];
            if (findpar(e.u)!= findpar(e.v)) {
                unite(e.u, e.v);
                ans += e.val;
            }
        }
        System.out.println(ans);
    }
}

Translate the above Java code to Python and end with comment "