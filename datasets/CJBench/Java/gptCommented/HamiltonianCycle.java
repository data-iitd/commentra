import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private int vertex; // Number of vertices in the graph
    private int pathCount; // Count of vertices in the current path
    private int[] cycle; // Array to store the cycle path
    private int[][] graph; // Adjacency matrix representation of the graph

    // Method to find the Hamiltonian cycle in the given graph
    public int[] findMain(int[][] graph) {
        // If the graph has only one vertex, return a trivial cycle
        if (graph.length == 1) {
            return new int[] {0, 0};
        }
        
        // Initialize the number of vertices and cycle array
        this.vertex = graph.length;
        this.cycle = new int[this.vertex + 1];
        Arrays.fill(this.cycle, -1); // Fill cycle array with -1 to indicate unvisited
        this.graph = graph; // Set the graph
        this.cycle[0] = 0; // Start the cycle with the first vertex
        this.pathCount = 1; // Initialize path count
        
        // Check if a Hamiltonian path can be found starting from vertex 0
        if (!isPathFound(0)) {
            Arrays.fill(this.cycle, -1); // Reset cycle if no path is found
        } else {
            this.cycle[this.cycle.length - 1] = this.cycle[0]; // Close the cycle
        }
        
        return cycle; // Return the found cycle
    }

    // Recursive method to find the Hamiltonian path
    public boolean isPathFound(int vertex) {
        // Check if we have returned to the starting vertex and visited all vertices
        if (this.graph[vertex][0] == 1 && this.pathCount == this.vertex) {
            return true; // Hamiltonian cycle found
        }
        
        // If all vertices are visited but not returning to start, return false
        if (this.pathCount == this.vertex) {
            return false;
        }
        
        // Explore all adjacent vertices
        for (int v = 0; v < this.vertex; v++) {
            // If there is an edge to the adjacent vertex
            if (this.graph[vertex][v] == 1) {
                this.cycle[this.pathCount++] = v; // Add vertex to cycle
                this.graph[vertex][v] = 0; // Remove edge from graph
                this.graph[v][vertex] = 0; // Remove reverse edge
                
                // Check if the vertex is already in the cycle
                if (!isPresent(v)) {
                    // Recursively search for the next vertex
                    if (isPathFound(v)) {
                        return true; // Path found
                    }
                }
                
                // Backtrack: restore the edge and remove the vertex from the cycle
                this.graph[vertex][v] = 1; // Restore edge
                this.graph[v][vertex] = 1; // Restore reverse edge
                this.cycle[--this.pathCount] = -1; // Remove vertex from cycle
            }
        }
        return false; // No path found
    }

    // Method to check if a vertex is already in the cycle
    public boolean isPresent(int vertex) {
        for (int i = 0; i < pathCount - 1; i++) {
            if (cycle[i] == vertex) {
                return true; // Vertex is present in the cycle
            }
        }
        return false; // Vertex is not present
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of vertices
        int n = scanner.nextInt();
        int[][] graph = new int[n][n]; // Initialize the graph
        
        // Read the adjacency matrix from input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }
        
        // Create an instance of Main to find the Hamiltonian cycle
        Main hamiltonianCycle = new Main();
        int[] result = hamiltonianCycle.findMain(graph); // Find the cycle
        
        // Output the result
        System.out.println("Hamiltonian Cycle:");
        if (result[0] == -1) {
            System.out.println("No Hamiltonian Cycle exists."); // No cycle found
        } else {
            for (int vertex : result) {
                System.out.print(vertex + " "); // Print the cycle
            }
        }
        
        scanner.close(); // Close the scanner
    }
}
