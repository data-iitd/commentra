
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Number of vertices in the graph
    private int vertex;

    // Number of paths found in the graph
    private int pathCount;

    // Array to store the cycle of the Hamiltonian path or cycle
    private int[] cycle;

    // 2D array to represent the graph
    private int[][] graph;

    // Function to find the main path or cycle in the graph
    public int[] findMain(int[][] graph) {
        // Base case: If the graph has only one vertex, return an empty cycle
        if (graph.length == 1) {
            return new int[] {0, 0};
        }

        // Initialize the variables
        this.vertex = graph.length;
        this.cycle = new int[this.vertex + 1];
        Arrays.fill(this.cycle, -1);
        this.graph = graph;
        this.cycle[0] = 0;
        this.pathCount = 1;

        // If no path is found, initialize the cycle array with -1 and return it
        if (!isPathFound(0)) {
            Arrays.fill(this.cycle, -1);
            return cycle;
        }

        // Set the last vertex of the cycle to the first vertex
        this.cycle[this.cycle.length - 1] = this.cycle[0];

        return cycle;
    }

    // Function to check if a path is found from the given vertex
    public boolean isPathFound(int vertex) {
        // Base case: If all vertices have been visited and the path count equals the number of vertices,
        // return true as a Hamiltonian path or cycle has been found
        if (this.graph[vertex][0] == 1 && this.pathCount == this.vertex) {
            return true;
        }

        // If all vertices have been visited, return false as no Hamiltonian path or cycle exists
        if (this.pathCount == this.vertex) {
            return false;
        }

        // Iterate through all the adjacent vertices and check if a path exists to them
        for (int v = 0; v < this.vertex; v++) {
            if (this.graph[vertex][v] == 1) {
                // Add the current vertex to the path and recursively check if a path exists to the adjacent vertex
                this.cycle[this.pathCount++] = v;
                this.graph[vertex][v] = 0;
                this.graph[v][vertex] = 0;

                // If a path is found, return true
                if (isPathFound(v)) {
                    return true;
                }

                // Backtrack and restore the graph to its original state
                this.graph[vertex][v] = 1;
                this.graph[v][vertex] = 1;
                this.cycle[--this.pathCount] = -1;
            }
        }

        // If no path is found, return false
        return false;
    }

    // Function to check if a vertex is already present in the cycle
    public boolean isPresent(int vertex) {
        // Iterate through the cycle array and check if the given vertex is present
        for (int i = 0; i < pathCount - 1; i++) {
            if (cycle[i] == vertex) {
                return true;
            }
        }

        // If the vertex is not present, return false
        return false;
    }

    // Main function to read the input and call the findMain function
    public static void main(String[] args) {
        // Initialize the scanner to read the input
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices from the input
        int n = scanner.nextInt();

        // Initialize the 2D array to represent the graph
        int[][] graph = new int[n][n];

        // Read the edges of the graph from the input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        // Initialize the Main class and call the findMain function
        Main hamiltonianCycle = new Main();
        int[] result = hamiltonianCycle.findMain(graph);

        // Print the result
        System.out.println("Hamiltonian Cycle:");
        if (result[0] == -1) {
            System.out.println("No Hamiltonian Cycle exists.");
        } else {
            // Print the vertices of the Hamiltonian cycle
            for (int vertex : result) {
                System.out.print(vertex + " ");
            }
        }

        // Close the scanner
        scanner.close();
    }
}

