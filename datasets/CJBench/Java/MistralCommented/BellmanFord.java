
import java.util.Scanner;
class Main 
{
    int vertex; // Number of vertices in the graph
    int edge; // Number of edges in the graph
    private Edge[] edges; // Array to store edges
    private int index = 0; // Index for adding edges to the array

    Main(int v, int e) { // Constructor to initialize the graph with given number of vertices and edges
        vertex = v;
        edge = e;
        edges = new Edge[e];
    }

    class Edge { // Class to represent an edge with source, destination and weight
        int u;
        int v;
        int w;

        Edge(int a, int b, int c) {
            u = a;
            v = b;
            w = c;
        }
    }

    public void addEdge(int x, int y, int z) { // Method to add an edge to the graph
        edges[index++] = new Edge(x, y, z);
    }

    public Edge[] getEdgeArray() { // Method to get the array of edges
        return edges;
    }

    // Method to print the path from source to destination vertex
    void printPath(int[] parent, int vertex) {
        if (parent[vertex] == -1) { // Base case: if the current vertex is the source, return
            return;
        }
        printPath(parent, parent[vertex]); // Recursive call: print the path from the parent to the current vertex
        System.out.print(vertex + " "); // Print the current vertex
    }

    // Method to execute the breadth-first search algorithm from a given source vertex
    public void execute(int source) {
        int[] dist = new int[vertex]; // Array to store the shortest distance from the source to each vertex
        int[] parent = new int[vertex]; // Array to store the parent of each vertex in the shortest path tree

        // Initialize all distances as infinity and parents as null
        for (int i = 0; i < vertex; i++) {
            dist[i] = Integer.MAX_VALUE;
            parent[i] = -1;
        }

        // Set the distance of the source vertex to 0 and mark it as visited
        dist[source] = 0;

        // Perform breadth-first search for vertex-1 times
        for (int i = 0; i < vertex - 1; i++) {
            for (int j = 0; j < edge; j++) { // Iterate through all edges
                Edge e = edges[j]; // Get the current edge
                int u = e.u; // Get the source vertex
                int v = e.v; // Get the destination vertex
                int weight = e.w; // Get the weight of the edge

                // If the distance to the source vertex is not infinity and the distance to the destination vertex can be improved, update the distance and parent
                if (dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }

        // Check for negative weight cycle
        for (int j = 0; j < edge; j++) {
            Edge e = edges[j];
            int u = e.u;
            int v = e.v;
            int weight = e.w;

            if (dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + weight) {
                System.out.println("Negative cycle detected");
                return;
            }
        }

        // Print the vertex distances from the source and their corresponding paths
        System.out.println("Vertex distances from source:");
        for (int i = 0; i < vertex; i++) {
            System.out.println("Vertex: " + i + ", Distance: " + dist[i]);
        }
        System.out.println("Paths:");
        for (int i = 0; i < vertex; i++) {
            System.out.print("Path to " + i + ": " + source + " ");
            printPath(parent, i);
            System.out.println();
        }
    }

    public static void main(String[] args) { // Main method to read input and execute the algorithm
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt(); // Read the number of vertices
        int e = sc.nextInt(); // Read the number of edges
        Main bf = new Main(v, e); // Create a new graph with the given number of vertices and edges

        for (int i = 0; i < e; i++) { // Read and add edges to the graph
            int u = sc.nextInt();
            int ve = sc.nextInt();
            int w = sc.nextInt();
            bf.addEdge(u, ve, w);
        }

        int source = sc.nextInt(); // Read the source vertex
        bf.execute(source); // Execute the breadth-first search algorithm from the source vertex