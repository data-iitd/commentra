import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Number of vertices in the graph
    private final int v;
    // List to store all paths from source to destination
    private final List<List<Integer>> paths = new ArrayList<>();
    // Adjacency list representation of the graph
    private ArrayList<Integer>[] adjList;

    // Constructor to initialize the graph with a given number of vertices
    public Main(int vertices) {
        this.v = vertices;
        initAdjList(); // Initialize the adjacency list
    }

    // Method to initialize the adjacency list for the graph
    private void initAdjList() {
        adjList = new ArrayList[v]; // Create an array of ArrayLists
        for (int i = 0; i < v; i++) {
            adjList[i] = new ArrayList<>(); // Initialize each adjacency list
        }
    }

    // Method to add an edge from vertex u to vertex v
    public void addEdge(int u, int v) {
        adjList[u].add(v); // Add vertex v to the adjacency list of vertex u
    }

    // Method to find and store all paths from source s to destination d
    public void storeAllPaths(int s, int d) {
        boolean[] isVisited = new boolean[v]; // Track visited vertices
        ArrayList<Integer> pathList = new ArrayList<>(); // List to store the current path
        pathList.add(s); // Add the source to the path
        storeAllPathsUtil(s, d, isVisited, pathList); // Call the utility method to find paths
    }

    // Utility method to recursively find all paths from u to d
    private void storeAllPathsUtil(Integer u, Integer d, boolean[] isVisited, List<Integer> localPathList) {
        // If the current vertex is the destination, add the current path to the list of paths
        if (u.equals(d)) {
            paths.add(new ArrayList<>(localPathList)); // Store a copy of the current path
            return;
        }
        
        isVisited[u] = true; // Mark the current vertex as visited

        // Explore all adjacent vertices of the current vertex
        for (Integer i : adjList[u]) {
            // If the adjacent vertex has not been visited, continue the path
            if (!isVisited[i]) {
                localPathList.add(i); // Add the adjacent vertex to the current path
                storeAllPathsUtil(i, d, isVisited, localPathList); // Recur for the adjacent vertex
                localPathList.remove(i); // Backtrack: remove the vertex from the current path
            }
        }
        
        isVisited[u] = false; // Unmark the current vertex for other paths
    }

    // Method to get all stored paths
    public List<List<Integer>> getPaths() {
        return paths; // Return the list of all paths found
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int vertices = scanner.nextInt(); // Read the number of vertices
        int edges = scanner.nextInt(); // Read the number of edges
        int[][] edgeList = new int[edges][2]; // Array to store edges

        // Read the edges from input
        for (int i = 0; i < edges; i++) {
            edgeList[i][0] = scanner.nextInt(); // Start vertex of the edge
            edgeList[i][1] = scanner.nextInt(); // End vertex of the edge
        }

        int source = scanner.nextInt(); // Read the source vertex
        int destination = scanner.nextInt(); // Read the destination vertex

        // Create a graph instance
        Main graph = new Main(vertices);
        
        // Add edges to the graph
        for (int[] edge : edgeList) {
            graph.addEdge(edge[0], edge[1]);
        }

        // Find all paths from source to destination
        graph.storeAllPaths(source, destination);
        
        // Print all paths found
        System.out.println("All paths from source to destination: ");
        for (List<Integer> path : graph.getPaths()) {
            System.out.println(path); // Print each path
        }

        scanner.close(); // Close the scanner
    }
}
