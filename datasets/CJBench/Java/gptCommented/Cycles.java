import java.util.ArrayList;
import java.util.Scanner;

// Class to find cycles in a directed graph using Depth First Search (DFS)
class Cycle {
    private final int nodes; // Number of nodes in the graph
    private int[][] adjacencyMatrix; // Adjacency matrix to represent the graph
    private boolean[] visited; // Array to track visited nodes during DFS
    ArrayList<ArrayList<Integer>> cycles = new ArrayList<>(); // List to store found cycles

    // Constructor to initialize the graph with nodes and edges
    Cycle(int nodes, int edges, int[][] edgesInput) {
        this.nodes = nodes;
        adjacencyMatrix = new int[nodes][nodes]; // Initialize adjacency matrix
        visited = new boolean[nodes]; // Initialize visited array
        for (int i = 0; i < nodes; i++) {
            visited[i] = false; // Mark all nodes as unvisited
        }
        // Populate the adjacency matrix based on the input edges
        for (int[] edge : edgesInput) {
            int start = edge[0];
            int end = edge[1];
            adjacencyMatrix[start][end] = 1; // Mark the edge in the adjacency matrix
        }
    }

    // Method to start the cycle detection process
    public void start() {
        // Iterate through each node to initiate DFS
        for (int i = 0; i < nodes; i++) {
            ArrayList<Integer> temp = new ArrayList<>(); // Temporary list to store the current path
            dfs(i, i, temp); // Start DFS from the current node
            // Reset the adjacency matrix for the current node to avoid duplicate cycles
            for (int j = 0; j < nodes; j++) {
                adjacencyMatrix[i][j] = 0;
                adjacencyMatrix[j][i] = 0;
            }
        }
    }

    // Depth First Search method to explore the graph and find cycles
    private void dfs(Integer start, Integer curr, ArrayList<Integer> temp) {
        temp.add(curr); // Add the current node to the path
        visited[curr] = true; // Mark the current node as visited
        // Explore all adjacent nodes
        for (int i = 0; i < nodes; i++) {
            if (adjacencyMatrix[curr][i] == 1) { // Check if there is an edge
                if (i == start) { // Check if we found a cycle
                    cycles.add(new ArrayList<>(temp)); // Store the found cycle
                } else {
                    if (!visited[i]) { // If the node is not visited, continue DFS
                        dfs(start, i, temp);
                    }
                }
            }
        }
        // Backtrack: remove the current node from the path
        if (temp.size() > 0) {
            temp.remove(temp.size() - 1);
        }
        visited[curr] = false; // Mark the current node as unvisited for future searches
    }

    // Method to print all found cycles
    public void printAll() {
        if (cycles.isEmpty()) { // Check if no cycles were found
            System.out.println("No cycles found.");
            return;
        }
        // Print each cycle
        for (ArrayList<Integer> cycle : cycles) {
            for (int i = 0; i < cycle.size(); i++) {
                System.out.print(cycle.get(i) + " -> "); // Print the cycle path
            }
            System.out.println(cycle.get(0)); // Complete the cycle by returning to the start
            System.out.println(); // Print a new line for better readability
        }
    }
}

// Main class to execute the cycle detection program
public final class Main {
    private Main() {
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int nodes = scanner.nextInt(); // Read the number of nodes
        int edges = scanner.nextInt(); // Read the number of edges
        int[][] edgesInput = new int[edges][2]; // Initialize the edges input array
        // Read the edges from input
        for (int i = 0; i < edges; i++) {
            edgesInput[i][0] = scanner.nextInt(); // Start node of the edge
            edgesInput[i][1] = scanner.nextInt(); // End node of the edge
        }
        // Create a Cycle object to find cycles in the graph
        Cycle cycleFinder = new Cycle(nodes, edges, edgesInput);
        cycleFinder.start(); // Start the cycle detection process
        cycleFinder.printAll(); // Print all found cycles
    }
}
