import java.util.*;

public class Main {
    static final int maxn = 100005; // Define a constant for the maximum number of nodes

    static class Node {
        int x, y, id; // Define a structure for nodes with x, y coordinates and an id
        Node(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }
    }

    static class Edge implements Comparable<Edge> {
        int u, v, val; // Define a structure for edges with u, v nodes and a value
        Edge(int u, int v, int val) {
            this.u = u;
            this.v = v;
            this.val = val;
        }
        public int compareTo(Edge rhs) { // Overload the compareTo method for sorting edges by value
            return Integer.compare(this.val, rhs.val);
        }
    }

    static int[] par = new int[maxn]; // Define an array for storing the parent of each node
    static int n; // Define an integer for the number of nodes

    static void init() { // Define a function to initialize the parent array
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    static int findpar(int x) { // Define a function to find the root of a node using path compression
        if (par[x] != x) {
            par[x] = findpar(par[x]);
        }
        return par[x];
    }

    static void unite(int x, int y) { // Define a function to merge two sets
        x = findpar(x);
        y = findpar(y);
        if (x != y) {
            par[x] = y;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // Read the number of nodes

        init(); // Initialize the parent array

        Node[] node = new Node[n + 1]; // Create an array for nodes
        for (int i = 1; i <= n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            node[i] = new Node(x, y, i); // Read the coordinates of each node and assign an id
        }

        List<Edge> edges = new ArrayList<>(); // Create a list for edges

        Arrays.sort(node, 1, n + 1, Comparator.comparingInt(a -> a.x)); // Sort nodes by x coordinate
        for (int i = 2; i <= n; i++) {
            edges.add(new Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x)); // Create edges based on x differences
        }

        Arrays.sort(node, 1, n + 1, Comparator.comparingInt(a -> a.y)); // Sort nodes by y coordinate
        for (int i = 2; i <= n; i++) {
            edges.add(new Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y)); // Create edges based on y differences
        }

        Collections.sort(edges); // Sort all edges by their values

        long ans = 0; // Initialize a variable to store the total weight of the minimum spanning tree
        for (Edge edge : edges) {
            int u = edge.u, v = edge.v, val = edge.val;
            if (findpar(u) == findpar(v)) continue; // Skip if u and v are already in the same set
            unite(u, v); // Merge u and v
            ans += val; // Add the edge value to the total weight
        }

        System.out.println(ans); // Output the total weight of the minimum spanning tree
        scanner.close();
    }
}
// <END-OF-CODE>
