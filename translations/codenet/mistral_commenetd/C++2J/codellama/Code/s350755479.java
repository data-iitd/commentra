
import java.util.*;
import java.io.*;

class Node {
    int x, y, id;
    public Node(int x, int y, int id) {
        this.x = x;
        this.y = y;
        this.id = id;
    }
}

class Edge {
    int u, v, val;
    public Edge(int u, int v, int val) {
        this.u = u;
        this.v = v;
        this.val = val;
    }
}

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        Node[] node = new Node[n + 1];
        for (int i = 1; i <= n; i ++) {
            line = br.readLine().split(" ");
            int x = Integer.parseInt(line[0]);
            int y = Integer.parseInt(line[1]);
            node[i] = new Node(x, y, i);
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            public int compare(Node a, Node b) {
                return a.x - b.x;
            }
        });
        int cnt = 0;
        Edge[] e = new Edge[n * 2];
        for (int i = 2; i <= n; i ++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        }
        Arrays.sort(node, 1, n + 1, new Comparator<Node>() {
            public int compare(Node a, Node b) {
                return a.y - b.y;
            }
        });
        for (int i = 2; i <= n; i ++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y);
        }
        Arrays.sort(e, new Comparator<Edge>() {
            public int compare(Edge a, Edge b) {
                return a.val - b.val;
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
    public static int[] par = new int[100005];
    public static int findpar(int x) {
        return par[x] = (par[x] == x ? x : findpar(par[x]));
    }
    public static void unite(int x, int y) {
        x = findpar(x), y = findpar(y);
        if (x == y) return;
        par[x] = y;
    }
}

