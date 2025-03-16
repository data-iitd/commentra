import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of vertices and edges from the input
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        
        // Initialize the graph using an adjacency matrix representation
        AdjacencyMatrixGraph graph = new AdjacencyMatrixGraph(vertices);
        
        // Read edges from the input and add them to the graph
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }
        
        // Read the starting vertices for DFS and BFS
        int dfsStartVertex = scanner.nextInt();
        int bfsStartVertex = scanner.nextInt();
        
        // Print the adjacency matrix of the graph
        System.out.println("The graph matrix:");
        System.out.println(graph);
        
        // Perform and print the result of Depth First Search
        System.out.println("Depth First Order:");
        System.out.println(graph.depthFirstOrder(dfsStartVertex));
        
        // Perform and print the result of Breadth First Search
        System.out.println("Breadth First Order:");
        System.out.println(graph.breadthFirstOrder(bfsStartVertex));
    }
}

class AdjacencyMatrixGraph {
    private int vertexCount; // Number of vertices in the graph
    private int edgeCount;   // Number of edges in the graph
    private int[][] adjMatrix; // Adjacency matrix to represent the graph
    static final int EDGE_EXIST = 1; // Constant to represent an existing edge
    static final int EDGE_NONE = 0;   // Constant to represent no edge

    // Constructor to initialize the graph with a given number of vertices
    AdjacencyMatrixGraph(int givenNumberOfVertices) {
        this.vertexCount = givenNumberOfVertices;
        this.edgeCount = 0;
        this.adjMatrix = new int[givenNumberOfVertices][givenNumberOfVertices];
    }

    // Method to return the number of vertices in the graph
    public int numberOfVertices() {
        return this.vertexCount;
    }

    // Method to return the number of edges in the graph
    public int numberOfEdges() {
        return this.edgeCount;
    }

    // Method to add an edge between two vertices
    public boolean addEdge(int from, int to) {
        // Check if the vertices are valid
        if (from >= 0 && from < vertexCount && to >= 0 && to < vertexCount) {
            // Check if the edge does not already exist
            if (adjMatrix[from][to] == EDGE_NONE) {
                // Add the edge in both directions (undirected graph)
                adjMatrix[from][to] = EDGE_EXIST;
                adjMatrix[to][from] = EDGE_EXIST;
                edgeCount++; // Increment the edge count
                return true; // Edge added successfully
            }
        }
        return false; // Edge could not be added
    }

    // Method to perform Depth First Search and return the order of traversal
    public List<Integer> depthFirstOrder(int startVertex) {
        // Check if the starting vertex is valid
        if (startVertex < 0 || startVertex >= vertexCount) {
            return new ArrayList<>(); // Return an empty list if invalid
        }
        boolean[] visited = new boolean[vertexCount]; // Track visited vertices
        List<Integer> orderList = new ArrayList<>(); // List to store the order of traversal
        dfs(startVertex, visited, orderList); // Start DFS
        return orderList; // Return the order of traversal
    }

    // Recursive helper method for Depth First Search
    private void dfs(int currentVertex, boolean[] visited, List<Integer> orderList) {
        // If the vertex has already been visited, return
        if (visited[currentVertex]) return;
        visited[currentVertex] = true; // Mark the current vertex as visited
        orderList.add(currentVertex); // Add the current vertex to the order list
        
        // Explore all adjacent vertices
        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[currentVertex][i] == EDGE_EXIST) {
                dfs(i, visited, orderList); // Recursively visit adjacent vertices
            }
        }
    }

    // Method to perform Breadth First Search and return the order of traversal
    public List<Integer> breadthFirstOrder(int startVertex) {
        // Check if the starting vertex is valid
        if (startVertex < 0 || startVertex >= vertexCount) {
            return new ArrayList<>(); // Return an empty list if invalid
        }
        boolean[] visited = new boolean[vertexCount]; // Track visited vertices
        List<Integer> orderList = new ArrayList<>(); // List to store the order of traversal
        Queue<Integer> queue = new LinkedList<>(); // Queue for BFS
        queue.add(startVertex); // Enqueue the starting vertex
        
        // Process the queue until it is empty
        while (!queue.isEmpty()) {
            int currentVertex = queue.poll(); // Dequeue the front vertex
            if (visited[currentVertex]) continue; // Skip if already visited
            visited[currentVertex] = true; // Mark the current vertex as visited
            orderList.add(currentVertex); // Add the current vertex to the order list
            
            // Enqueue all adjacent vertices
            for (int i = 0; i < vertexCount; i++) {
                if (adjMatrix[currentVertex][i] == EDGE_EXIST) {
                    queue.add(i); // Add adjacent vertex to the queue
                }
            }
        }
        return orderList; // Return the order of traversal
    }

    // Override toString method to display the adjacency matrix
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("    "); // StringBuilder for efficient string concatenation
        for (int i = 0; i < vertexCount; i++) {
            sb.append(i).append(" "); // Append vertex indices
        }
        sb.append("\n"); // New line after vertex indices
        for (int i = 0; i < vertexCount; i++) {
            sb.append(i).append(" : "); // Append vertex number
            for (int j = 0; j < vertexCount; j++) {
                sb.append(adjMatrix[i][j]).append(" "); // Append adjacency values
            }
            sb.append("\n"); // New line after each vertex's adjacency list
        }
        return sb.toString(); // Return the string representation of the adjacency matrix
    }
}

