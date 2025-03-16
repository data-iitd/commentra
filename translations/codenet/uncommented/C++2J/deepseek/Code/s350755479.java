import java.util.*;

public class Main {
    static class Node {
        int x, y, id;
        Node(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }
    }

    static class Edge implements Comparable<Edge> {
        int u, v, val;
        Edge(int u, int v, int val) {
            this.u = u;
            this.v = v;
            this.val = val;
        }
        public int compareTo(Edge other) {
            return Integer.compare(this.val, other.val);
        }
    }

    static int[] par;
    static int n;

    static void init() {
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        par = new int[n + 1];
        List<Node> nodes = new ArrayList<>();
        List<Edge> edges = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            nodes.add(new Node(x, y, i));
        }

        Collections.sort(nodes, (a, b) -> Integer.compare(a.x, b.x));

        for (int i = 1; i < n; i++) {
            edges.add(new Edge(nodes.get(i - 1).id, nodes.get(i).id, nodes.get(i).x - nodes.get(i - 1).x));
        }

        Collections.sort(nodes, (a, b) -> Integer.compare(a.y, b.y));

        for (int i = 1; i < n; i++) {
            edges.add(new Edge(nodes.get(i - 1).id, nodes.get(i).id, nodes.get(i).y - nodes.get(i - 1).y));
        }

        Collections.sort(edges);

        init();
        long ans = 0;
        for (Edge edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int val = edge.val;
            if (findpar(u) == findpar(v)) continue;
            unite(u, v);
            ans += val;
        }

        System.out.println(ans);
    }
}
