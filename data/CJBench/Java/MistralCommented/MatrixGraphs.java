
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input from the console

        int vertices = scanner.nextInt(); // Read the number of vertices from the input
        int edges = scanner.nextInt(); // Read the number of edges from the input

        AdjacencyMatrixGraph graph = new AdjacencyMatrixGraph(vertices); // Create an instance of AdjacencyMatrixGraph with the given number of vertices

        for (int i = 0; i < edges; i++) { // Iterate through each edge and add it to the graph
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }

        int dfsStartVertex = scanner.nextInt(); // Read the starting vertex for Depth First Search (DFS)
        int bfsStartVertex = scanner.nextInt(); // Read the starting vertex for Breadth First Search (BFS)

        System.out.println("The graph matrix:"); // Print the graph matrix to the console
        System.out.println(graph);

        System.out.println("Depth First Order:"); // Print the header for the Depth First Order output
        System.out.println(graph.depthFirstOrder(dfsStartVertex)); // Call the depthFirstOrder method and print the result to the console

        System.out.println("Breadth First Order:"); // Print the header for the Breadth First Order output
        System.out.println(graph.breadthFirstOrder(bfsStartVertex)); // Call the breadthFirstOrder method and print the result to the console
    }
}

class AdjacencyMatrixGraph {
    private int vertexCount;
    private int edgeCount;
    private int[][] adjMatrix;
    static final int EDGE_EXIST = 1;
    static final int EDGE_NONE = 0;

    AdjacencyMatrixGraph(int givenNumberOfVertices) {
        this.vertexCount = givenNumberOfVertices; // Initialize the number of vertices
        this.edgeCount = 0; // Initialize the number of edges
        this.adjMatrix = new int[givenNumberOfVertices][givenNumberOfVertices]; // Initialize the adjacency matrix with the given number of rows and columns
    }

    public int numberOfVertices() {
        return this.vertexCount; // Return the number of vertices
    }

    public int numberOfEdges() {
        return this.edgeCount; // Return the number of edges
    }

    public boolean addEdge(int from, int to) {
        if (from >= 0 && from < vertexCount && to >= 0 && to < vertexCount) { // Check if the vertices are within the valid range
            if (adjMatrix[from][to] == EDGE_NONE) { // Check if the edge does not already exist
                adjMatrix[from][to] = EDGE_EXIST; // Set the edge to exist
                adjMatrix[to][from] = EDGE_EXIST; // Set the edge in the opposite direction to exist
                edgeCount++; // Increment the number of edges
                return true; // Return true if the edge was added successfully
            }
        }
        return false; // Return false if the edge could not be added
    }

    public List<Integer> depthFirstOrder(int startVertex) {
        if (startVertex < 0 || startVertex >= vertexCount) { // Check if the starting vertex is within the valid range
            return new ArrayList<>(); // Return an empty list if the starting vertex is invalid
        }

        boolean[] visited = new boolean[vertexCount]; // Initialize an array to keep track of visited vertices
        List<Integer> orderList = new ArrayList<>(); // Initialize a list to store the order of traversal

        dfs(startVertex, visited, orderList); // Call the depth-first search recursive function

        return orderList; // Return the list of vertices in the depth-first order
    }

    private void dfs(int currentVertex, boolean[] visited, List<Integer> orderList) {
        if (visited[currentVertex]) return; // Return if the current vertex has already been visited

        visited[currentVertex] = true; // Mark the current vertex as visited
        orderList.add(currentVertex); // Add the current vertex to the order list

        for (int i = 0; i < vertexCount; i++) { // Iterate through all adjacent vertices
            if (adjMatrix[currentVertex][i] == EDGE_EXIST) {
                dfs(i, visited, orderList); // Recursively call the depth-first search function for the adjacent vertex
            }
        }
    }

    public List<Integer> breadthFirstOrder(int startVertex) {
        if (startVertex < 0 || startVertex >= vertexCount) { // Check if the starting vertex is within the valid range
            return new ArrayList<>(); // Return an empty list if the starting vertex is invalid
        }

        boolean[] visited = new boolean[vertexCount]; // Initialize an array to keep track of visited vertices
        List<Integer> orderList = new ArrayList<>(); // Initialize a list to store the order of traversal
        Queue<Integer> queue = new LinkedList<>(); // Initialize a queue to store the vertices to be processed

        queue.add(startVertex); // Add the starting vertex to the queue

        while (!queue.isEmpty()) { // Process the vertices in the order they are encountered in the BFS traversal
            int currentVertex = queue.poll(); // Get the next vertex from the queue
            if (visited[currentVertex]) continue; // Skip if the vertex has already been visited

            visited[currentVertex] = true; // Mark the current vertex as visited
            orderList.add(currentVertex); // Add the current vertex to the order list

            for (int i = 0; i < vertexCount; i++) { // Iterate through all adjacent vertices
                if (adjMatrix[currentVertex][i] == EDGE_EXIST) {
                    queue.add(i); // Add the adjacent vertex to the queue for processing in the next iteration
                }
            }
        }

        return orderList; // Return the list of vertices in the breadth-first order
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("    "); // Initialize a StringBuilder object to build the string representation of the graph

        for (int i = 0; i < vertexCount; i++) { // Iterate through each vertex and add its index to the header row of the graph matrix
            sb.append(i).append(" ");
        }

        sb.append("\n"); // Add a newline character after the header row

        for (int i = 0; i < vertexCount; i++) { // Iterate through each row of the graph matrix and add its elements to the StringBuilder object
            sb.append(i).append(" : ");
            for (int j = 0; j < vertexCount; j++) {
                sb.append(adjMatrix[i][j]).append(" ");
            }
            sb.append("\n"); // Add a newline character after each row
        }

        return sb.toString(); // Return the string representation of the graph matrix
    }
}