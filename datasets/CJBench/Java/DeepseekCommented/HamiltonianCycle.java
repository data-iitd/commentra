import java.util.Arrays;
import java.util.Scanner;
public class Main {
    private int vertex; // Number of vertices in the graph
    private int pathCount; // Counter for the number of vertices in the current path
    private int[] cycle; // Array to store the current path
    private int[][] graph; // The graph represented as an adjacency matrix

    // Method to find a Hamiltonian cycle in the graph
    public int[] findMain(int[][] graph) {
        if (graph.length == 1) { // If the graph has only one vertex, return the single vertex as the cycle
            return new int[] {0, 0};
        }
        this.vertex = graph.length; // Set the number of vertices
        this.cycle = new int[this.vertex + 1]; // Initialize the cycle array with size vertex + 1
        Arrays.fill(this.cycle, -1); // Fill the cycle array with -1 (indicating unvisited vertices)
        this.graph = graph; // Set the graph
        this.cycle[0] = 0; // Start the cycle from vertex 0
        this.pathCount = 1; // Initialize the path count to 1 (starting vertex is already included)
        if (!isPathFound(0)) { // Try to find a path starting from vertex 0
            Arrays.fill(this.cycle, -1); // If no path is found, reset the cycle
        } else {
            this.cycle[this.cycle.length - 1] = this.cycle[0]; // Complete the cycle by connecting the last vertex to the first
        }
        return cycle; // Return the found cycle
    }

    // Recursive method to find a Hamiltonian path
    public boolean isPathFound(int vertex) {
        if (this.graph[vertex][0] == 1 && this.pathCount == this.vertex) { // If the path includes the first vertex and all vertices are visited, a cycle is found
            return true;
        }
        if (this.pathCount == this.vertex) { // If all vertices are visited but the first vertex is not included, no cycle is found
            return false;
        }
        for (int v = 0; v < this.vertex; v++) { // Iterate through all vertices
            if (this.graph[vertex][v] == 1) { // If there is an edge between the current vertex and v
                this.cycle[this.pathCount++] = v; // Add v to the path
                this.graph[vertex][v] = 0; // Mark the edge as used
                this.graph[v][vertex] = 0; // Mark the reverse edge as used
                if (!isPresent(v)) { // Check if v is already in the path
                    return isPathFound(v); // Recursively find the path
                }
                this.graph[vertex][v] = 1; // Unmark the edge as used
                this.graph[v][vertex] = 1; // Unmark the reverse edge as used
                this.cycle[--this.pathCount] = -1; // Remove v from the path
            }
        }
        return false; // If no path is found, return false
    }

    // Method to check if a vertex is already in the current path
    public boolean isPresent(int vertex) {
        for (int i = 0; i < pathCount - 1; i++) { // Iterate through the current path
            if (cycle[i] == vertex) { // If the vertex is found in the path
                return true; // Return true
            }
        }
        return false; // If the vertex is not found, return false
    }

    // Main method to read input and print the Hamiltonian cycle
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of vertices
        int[][] graph = new int[n][n]; // Create an adjacency matrix for the graph
        for (int i = 0; i < n; i++) { // Read the graph adjacency matrix
            for (int j = 0; j < n; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }
        Main hamiltonianCycle = new Main();
        int[] result = hamiltonianCycle.findMain(graph); // Find the Hamiltonian cycle
        System.out.println("Hamiltonian Cycle:");
        if (result[0] == -1) { // If no Hamiltonian cycle exists
            System.out.println("No Hamiltonian Cycle exists.");
        } else {
            for (int vertex : result) { // Print the Hamiltonian cycle
                System.out.print(vertex + " ");
            }
        }
        scanner.close(); // Close the scanner
    }
}
