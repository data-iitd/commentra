import java.util.*;

public class Main {
    // Define a constant for the maximum number of nodes
    static final int maxn = 100005;

    // Structure to represent a node with coordinates and an ID
    static class Node {
        int x, y, id;
    }

    // Structure to represent an edge with two nodes and a weight
    static class Edge implements Comparable<Edge> {
        int u, v, val;

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.val, o.val);
        }
    }

    // Array to store the parent of each node for union-find
    static int[] par = new int[maxn];
    static Node[] node = new Node[maxn];
    static Edge[] e = new Edge[maxn << 1];
    static int n; // Number of nodes

    // Function to initialize the union-find structure
    static void init() {
        for (int i = 0; i <= n; i++)
            par[i] = i; // Each node is its own parent initially
    }

    // Function to find the representative parent of a node
    static int findpar(int x) {
        if (par[x] == x) return x;
        return par[x] = findpar(par[x]); // Path compression
    }

    // Function to unite two nodes in the union-find structure
    static void unite(int x, int y) {
        x = findpar(x);
        y = findpar(y);
        if (x == y) return;
        par[x] = y;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes
        n = scanner.nextInt();

        // Initialize the union-find structure
        init();

        // Read the coordinates of each node and assign an ID
        node = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            node[i] = new Node();
            node[i].x = scanner.nextInt();
            node[i].y = scanner.nextInt();
            node[i].id = i;
        }

        // Sort nodes based on their x-coordinate
        Arrays.sort(node, 1, n + 1, (a, b) -> Integer.compare(a.x, b.x));

        int cnt = 0;
        // Create edges based on x-coordinates
        for (int i = 2; i <= n; i++) {
            e[cnt] = new Edge();
            e[cnt].u = node[i - 1].id;
            e[cnt].v = node[i].id;
            e[cnt].val = node[i].x - node[i - 1].x;
            cnt++;
        }

        // Sort nodes based on their y-coordinate
        Arrays.sort(node, 1, n + 1, (a, b) -> Integer.compare(a.y, b.y));
        // Create edges based on y-coordinates
        for (int i = 2; i <= n; i++) {
            e[cnt] = new Edge();
            e[cnt].u = node[i - 1].id;
            e[cnt].v = node[i].id;
            e[cnt].val = node[i].y - node[i - 1].y;
            cnt++;
        }

        // Sort edges based on their weight
        Arrays.sort(e, 0, cnt);

        long ans = 0;
        // Process each edge in sorted order
        for (int i = 0; i < cnt; i++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            if (findpar(u) == findpar(v)) continue;
            unite(u, v);
            ans += val;
        }

        // Output the total weight of the minimum spanning tree
        System.out.println(ans);

        scanner.close();
    }
}
