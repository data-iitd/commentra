import java.util.*;

public class Main {
    static final int MAXN = 100005;

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

        @Override
        public int compareTo(Edge rhs) {
            return Integer.compare(this.val, rhs.val);
        }
    }

    static int[] par = new int[MAXN];
    static Node[] node = new Node[MAXN];
    static Edge[] e = new Edge[MAXN << 1];
    static int n;

    static void init() {
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    static int findpar(int x) {
        if (par[x] != x) {
            par[x] = findpar(par[x]);
        }
        return par[x];
    }

    static void unite(int x, int y) {
        x = findpar(x);
        y = findpar(y);
        if (x != y) {
            par[x] = y;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        init();

        for (int i = 1; i <= n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            node[i] = new Node(x, y, i);
        }

        Arrays.sort(node, 1, n + 1, Comparator.comparingInt(a -> a.x));

        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        }

        Arrays.sort(node, 1, n + 1, Comparator.comparingInt(a -> a.y));
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y);
        }

        Arrays.sort(e, 0, cnt);

        long ans = 0;
        for (int i = 0; i < cnt; i++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            if (findpar(u) == findpar(v)) continue;
            unite(u, v);
            ans += val;
        }

        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
