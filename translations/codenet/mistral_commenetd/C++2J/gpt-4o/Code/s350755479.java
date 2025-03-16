import java.util.*;

public class Main {
    static final int maxn = 100005; // maximum number of nodes in the graph

    static class Node {
        int x, y, id; // x and y coordinates, id of each node
        Node(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }
    }

    static class Edge implements Comparable<Edge> {
        int u, v, val; // u and v are the ids of the nodes connected by the edge, the value of the edge
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

    static int[] par = new int[maxn]; // parent array to keep track of the parent of each node in the disjoint set data structure
    static int n; // number of nodes in the graph

    // Initialization function for the disjoint set data structure
    static void init() {
        for (int i = 0; i <= n; i++) {
            par[i] = i; // each node initially belongs to its own set
        }
    }

    // Function to find the representative of a set
    static int findpar(int x) {
        if (par[x] != x) {
            par[x] = findpar(par[x]); // path compression is used to reduce the height of the tree
        }
        return par[x];
    }

    // Function to merge two sets
    static void unite(int x, int y) {
        x = findpar(x);
        y = findpar(y);
        if (x != y) {
            par[x] = y; // merge by making the root of set y as the parent of the root of set x
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // read the number of nodes in the graph

        init(); // initialize the disjoint set data structure

        Node[] node = new Node[n + 1]; // array to hold nodes
        for (int i = 1; i <= n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            node[i] = new Node(x, y, i); // read the coordinates of each node and assign an id to it
        }

        // Sort the nodes based on their x-coordinates
        Arrays.sort(node, 1, n + 1, Comparator.comparingInt(a -> a.x));

        List<Edge> edges = new ArrayList<>(); // list to hold edges
        // Create edges between adjacent nodes based on their x-coordinates
        for (int i = 2; i <= n; i++) {
            edges.add(new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x));
        }

        // Sort the nodes based on their y-coordinates
        Arrays.sort(node, 1, n + 1, Comparator.comparingInt(a -> a.y));
        // Create edges between adjacent nodes based on their y-coordinates
        for (int i = 2; i <= n; i++) {
            edges.add(new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y));
        }

        // Sort the edges based on their values
        Collections.sort(edges);

        long ans = 0; // initialize the answer to 0
        // Process each edge in the sorted order
        for (Edge edge : edges) {
            int u = edge.u, v = edge.v, val = edge.val;
            // Skip if the nodes are already in the same set
            if (findpar(u) == findpar(v)) continue;
            // Merge the sets of the nodes and add the value of the edge to the answer
            unite(u, v);
            ans += val;
        }

        System.out.println(ans); // print the final answer
        scanner.close();
    }
}
// <END-OF-CODE>
