import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Node[] node = new Node[n + 1];
        for (int i = 1; i <= n; i ++) {
            node[i] = new Node();
            node[i].x = in.nextInt();
            node[i].y = in.nextInt();
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
    }
    static Edge[] e = new Edge[2 * 100000 + 5];
    static int[] par = new int[100000 + 5];
    static void init() {
        for (int i = 0; i <= 100000; i ++)
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
}

