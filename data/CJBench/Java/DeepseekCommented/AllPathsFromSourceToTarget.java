import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private final int v; // Number of vertices in the graph
    private final List<List<Integer>> paths = new ArrayList<>(); // List to store all paths from source to destination
    private ArrayList<Integer>[] adjList; // Adjacency list to represent the graph

    // Constructor to initialize the graph with a given number of vertices
    public Main(int vertices) {
        this.v = vertices;
        initAdjList(); // Initialize the adjacency list
    }

    // Method to initialize the adjacency list
    private void initAdjList() {
        adjList = new ArrayList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new ArrayList<>();
        }
    }

    // Method to add an edge to the graph
    public void addEdge(int u, int v) {
        adjList[u].add(v); // Add v to the adjacency list of u
    }

    // Method to store all paths from source to destination
    public void storeAllPaths(int s, int d) {
        boolean[] isVisited = new boolean[v]; // Array to keep track of visited vertices
        ArrayList<Integer> pathList = new ArrayList<>(); // List to store the current path
        pathList.add(s); // Add the source vertex to the path
        storeAllPathsUtil(s, d, isVisited, pathList); // Call the utility function to find all paths
    }

    // Utility function to find all paths recursively
    private void storeAllPathsUtil(Integer u, Integer d, boolean[] isVisited, List<Integer> localPathList) {
        if (u.equals(d)) { // If the current vertex is the destination
            paths.add(new ArrayList<>(localPathList)); // Add the current path to the list of paths
            return;
        }
        isVisited[u] = true; // Mark the current vertex as visited
        for (Integer i : adjList[u]) { // Iterate through all adjacent vertices
            if (!isVisited[i]) { // If the adjacent vertex is not visited
                localPathList.add(i); // Add the adjacent vertex to the current path
                storeAllPathsUtil(i, d, isVisited, localPathList); // Recursively call the utility function
                localPathList.remove(i); // Remove the adjacent vertex from the current path (backtracking)
            }
        }
        isVisited[u] = false; // Mark the current vertex as not visited (backtracking)
    }

    // Method to get the list of all paths
    public List<List<Integer>> getPaths() {
        return paths;
    }

    // Main method to read input, construct the graph, and find all paths
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt(); // Read the number of vertices
        int edges = scanner.nextInt(); // Read the number of edges
        int[][] edgeList = new int[edges][2]; // Array to store the edges
        for (int i = 0; i < edges; i++) {
            edgeList[i][0] = scanner.nextInt(); // Read the source vertex of the edge
            edgeList[i][1] = scanner.nextInt(); // Read the destination vertex of the edge
        }
        int source = scanner.nextInt(); // Read the source vertex
        int destination = scanner.nextInt(); // Read the destination vertex
        Main graph = new Main(vertices); // Create a new graph with the given number of vertices
        for (int[] edge : edgeList) {
            graph.addEdge(edge[0], edge[1]); // Add all edges to the graph
        }
        graph.storeAllPaths(source, destination); // Find all paths from source to destination
        System.out.println("All paths from source to destination: ");
        for (List<Integer> path : graph.getPaths()) {
            System.out.println(path); // Print all paths
        }
        scanner.close(); // Close the scanner
    }
}
