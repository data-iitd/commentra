import java.util.Scanner;
class Main 
{
    int vertex; // Number of vertices in the graph
    int edge; // Number of edges in the graph
    private Edge[] edges; // Array to store the edges
    private int index = 0; // Index to keep track of the current edge being added

    // Constructor to initialize the graph with a given number of vertices and edges
    Main(int v, int e) {
        vertex = v;
        edge = e;
        edges = new Edge[e]; // Initialize the edges array with the given number of edges
    }

    // Inner class representing an edge in the graph
    class Edge {
        int u; // Source vertex of the edge
        int v; // Destination vertex of the edge
        int w; // Weight of the edge

        // Constructor to initialize the edge with source, destination, and weight
        Edge(int a, int b, int c) {
            u = a;
            v = b;
            w = c;
        }
    }

    // Method to add a new edge to the graph
    public void addEdge(int x, int y, int z) { 
        edges[index++] = new Edge(x, y, z); // Add the new edge to the edges array
    }

    // Method to get the array of edges
    public Edge[] getEdgeArray() {
        return edges; // Return the array of edges
    }

    // Method to print the path from the source to a given vertex
    void printPath(int[] parent, int vertex) {
        if (parent[vertex] == -1) { // Base case: if the parent is -1, return
            return;
        }
        printPath(parent, parent[vertex]); // Recursively call printPath for the parent vertex
        System.out.print(vertex + " "); // Print the current vertex
    }

    // Method to execute the Bellman-Ford algorithm
    public void execute(int source) {
        int[] dist = new int[vertex]; // Array to store the shortest distances from the source
        int[] parent = new int[vertex]; // Array to store the parent vertices for the shortest paths
        for (int i = 0; i < vertex; i++) {
            dist[i] = Integer.MAX_VALUE; // Initialize all distances to infinity
            parent[i] = -1; // Initialize all parents to -1
        }
        dist[source] = 0; // Set the distance to the source to 0
        for (int i = 0; i < vertex - 1; i++) {
            for (int j = 0; j < edge; j++) {
                Edge e = edges[j]; // Get the current edge
                if (dist[e.u] != Integer.MAX_VALUE && dist[e.v] > dist[e.u] + e.w) {
                    dist[e.v] = dist[e.u] + e.w; // Update the distance to the destination vertex
                    parent[e.v] = e.u; // Set the parent of the destination vertex
                }
            }
        }
        for (int j = 0; j < edge; j++) {
            Edge e = edges[j]; // Get the current edge
            if (dist[e.u] != Integer.MAX_VALUE && dist[e.v] > dist[e.u] + e.w) {
                System.out.println("Negative cycle detected"); // If a negative cycle is detected, print a message
                return;
            }
        }
        System.out.println("Vertex distances from source:"); // Print the distances from the source
        for (int i = 0; i < vertex; i++) {
            System.out.println("Vertex: " + i + ", Distance: " + dist[i]); // Print the distance and vertex
        }
        System.out.println("Paths:"); // Print the paths
        for (int i = 0; i < vertex; i++) {
            System.out.print("Path to " + i + ": " + source + " "); // Print the source
            printPath(parent, i); // Print the path to the current vertex
            System.out.println(); // Move to the next line
        }
    }

    // Main method to read input, create an instance of Main, add edges, and execute the algorithm
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt(); // Read the number of vertices
        int e = sc.nextInt(); // Read the number of edges
        Main bf = new Main(v, e); // Create a new instance of Main
        for (int i = 0; i < e; i++) {
            int u = sc.nextInt(); // Read the source vertex of the edge
            int ve = sc.nextInt(); // Read the destination vertex of the edge
            int w = sc.nextInt(); // Read the weight of the edge
            bf.addEdge(u, ve, w); // Add the edge to the graph
        }
        int source = sc.nextInt(); // Read the source vertex for the shortest path calculation
        bf.execute(source); // Execute the Bellman-Ford algorithm with the given source vertex
    }
}
