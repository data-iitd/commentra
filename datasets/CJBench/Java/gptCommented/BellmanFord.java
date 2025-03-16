import java.util.Scanner;

class Main {
    // Number of vertices and edges in the graph
    int vertex;
    int edge;
    // Array to store edges
    private Edge[] edges;
    // Index to keep track of the current edge position
    private int index = 0;

    // Constructor to initialize the graph with a given number of vertices and edges
    Main(int v, int e) {
        vertex = v;
        edge = e;
        edges = new Edge[e]; // Initialize the edges array
    }

    // Inner class to represent an edge in the graph
    class Edge {
        int u; // Start vertex of the edge
        int v; // End vertex of the edge
        int w; // Weight of the edge

        // Constructor to create an edge with specified vertices and weight
        Edge(int a, int b, int c) {
            u = a;
            v = b;
            w = c;
        }
    }

    // Method to add an edge to the graph
    public void addEdge(int x, int y, int z) {
        edges[index++] = new Edge(x, y, z); // Create a new edge and add it to the array
    }

    // Method to retrieve the array of edges
    public Edge[] getEdgeArray() {
        return edges; // Return the edges array
    }

    // Recursive method to print the path from the source to a given vertex
    void printPath(int[] parent, int vertex) {
        if (parent[vertex] == -1) { // Base case: if there is no parent
            return;
        }
        printPath(parent, parent[vertex]); // Recursively print the parent path
        System.out.print(vertex + " "); // Print the current vertex
    }

    // Method to execute the Bellman-Ford algorithm from a given source vertex
    public void execute(int source) {
        // Arrays to store distances and parent vertices
        int[] dist = new int[vertex];
        int[] parent = new int[vertex];

        // Initialize distances to infinity and parents to -1
        for (int i = 0; i < vertex; i++) {
            dist[i] = Integer.MAX_VALUE; // Set initial distances to max value
            parent[i] = -1; // Set initial parents to -1 (no parent)
        }
        dist[source] = 0; // Distance from source to itself is 0

        // Relax edges repeatedly
        for (int i = 0; i < vertex - 1; i++) {
            for (int j = 0; j < edge; j++) {
                Edge e = edges[j]; // Get the edge
                // Check if the edge can be relaxed
                if (dist[e.u] != Integer.MAX_VALUE && dist[e.v] > dist[e.u] + e.w) {
                    dist[e.v] = dist[e.u] + e.w; // Update distance
                    parent[e.v] = e.u; // Update parent
                }
            }
        }

        // Check for negative weight cycles
        for (int j = 0; j < edge; j++) {
            Edge e = edges[j];
            // If we can still relax an edge, a negative cycle exists
            if (dist[e.u] != Integer.MAX_VALUE && dist[e.v] > dist[e.u] + e.w) {
                System.out.println("Negative cycle detected");
                return; // Exit the method if a negative cycle is found
            }
        }

        // Print the distances from the source to each vertex
        System.out.println("Vertex distances from source:");
        for (int i = 0; i < vertex; i++) {
            System.out.println("Vertex: " + i + ", Distance: " + dist[i]);
        }

        // Print the paths from the source to each vertex
        System.out.println("Paths:");
        for (int i = 0; i < vertex; i++) {
            System.out.print("Path to " + i + ": " + source + " ");
            printPath(parent, i); // Print the path using the parent array
            System.out.println();
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner for input
        int v = sc.nextInt(); // Read number of vertices
        int e = sc.nextInt(); // Read number of edges
        Main bf = new Main(v, e); // Create a new graph instance

        // Read edges from input
        for (int i = 0; i < e; i++) {
            int u = sc.nextInt(); // Start vertex
            int ve = sc.nextInt(); // End vertex
            int w = sc.nextInt(); // Weight of the edge
            bf.addEdge(u, ve, w); // Add the edge to the graph
        }

        int source = sc.nextInt(); // Read the source vertex
        bf.execute(source); // Execute the Bellman-Ford algorithm
    }
}
