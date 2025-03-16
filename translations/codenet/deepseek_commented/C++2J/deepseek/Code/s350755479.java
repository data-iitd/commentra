import java.util.*;

class Node {
    int x, y, id;
    Node(int x, int y, int id) {
        this.x = x;
        this.y = y;
        this.id = id;
    }
}

class Edge implements Comparable<Edge> {
    int u, v, val;
    Edge(int u, int v, int val) {
        this.u = u;
        this.v = v;
        this.val = val;
    }

    @Override
    public int compareTo(Edge other) {
        return Integer.compare(this.val, other.val);
    }
}

public class Main {
    static final int maxn = 100005;
    static Node[] node = new Node[maxn];
    static Edge[] e = new Edge[maxn << 1];
    static int[] par = new int[maxn];
    static int n;

    static boolean cmp1(Node a, Node b) {
        return a.x < b.x;
    }

    static boolean cmp2(Node a, Node b) {
        return a.y < b.y;
    }

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

        init();

        for (int i = 1; i <= n; i++) {
            node[i] = new Node(scanner.nextInt(), scanner.nextInt(), i);
        }

        Arrays.sort(node, 1, n + 1, Main::cmp1);

        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        }

        Arrays.sort(node, 1, n + 1, Main::cmp2);
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
    }
}
