import java.util.*;

public class Main {
    // Define a constant for the maximum number of nodes
    static final int maxn = 100005;

    // Class to represent a node with coordinates and an ID
    static class Node {
        int x, y, id;

        Node(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }
    }

    // Class to represent an edge with two nodes and a weight
    static class Edge implements Comparable<Edge> {
        int u, v, val;

        Edge(int u, int v, int val) {
            this.u = u;
            this.v = v;
            this.val = val;
        }

        // Overriding the compareTo method for sorting edges based on their weight
        @Override
        public int compareTo(Edge rhs) {
            return Integer.compare(this.val, rhs.val);
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
        if (par[x] != x) {
            par[x] = findpar(par[x]); // Path compression
        }
        return par[x];
    }

    // Function to unite two nodes in the union-find structure
    static void unite(int x, int y) {
        x = findpar(x);
        y = findpar(y);
        if (x != y) {
            par[x] = y; // Union the sets by making one parent of the other
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes
        n = scanner.nextInt();

        // Initialize the union-find structure
        init();

        // Read the coordinates of each node and assign an ID
        for (int i = 1; i <= n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            node[i] = new Node(x, y, i); // Assign ID to the node
        }

        // Sort nodes based on their x-coordinate
        Arrays.sort(node, 1, n + 1, Comparator.comparingInt(a -> a.x));

        int cnt = 0; // Counter for edges
        // Create edges based on x-coordinates
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x);
        }

        // Sort nodes based on their y-coordinate
        Arrays.sort(node, 1, n + 1, Comparator.comparingInt(a -> a.y));
        // Create edges based on y-coordinates
        for (int i = 2; i <= n; i++) {
            e[cnt++] = new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y);
        }

        // Sort edges based on their weight
        Arrays.sort(e, 0, cnt);

        long ans = 0; // Variable to store the total weight of the minimum spanning tree
        // Process each edge in sorted order
        for (int i = 0; i < cnt; i++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            // If u and v are already connected, skip this edge
            if (findpar(u) == findpar(v)) continue;
            unite(u, v); // Union the two nodes
            ans += val; // Add the weight of this edge to the total
        }

        // Output the total weight of the minimum spanning tree
        System.out.println(ans);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
