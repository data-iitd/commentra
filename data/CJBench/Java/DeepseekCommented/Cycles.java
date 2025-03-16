import java.util.ArrayList;
import java.util.Scanner;

// Class to detect cycles in a directed graph using DFS
class Cycle {
    private final int nodes; // Number of nodes in the graph
    private int[][] adjacencyMatrix; // Adjacency matrix to represent the graph
    private boolean[] visited; // Array to keep track of visited nodes
    ArrayList<ArrayList<Integer>> cycles = new ArrayList<>(); // List to store detected cycles

    // Constructor to initialize the graph with nodes, edges, and edges input
    Cycle(int nodes, int edges, int[][] edgesInput) {
        this.nodes = nodes;
        adjacencyMatrix = new int[nodes][nodes];
        visited = new boolean[nodes];
        for (int i = 0; i < nodes; i++) {
            visited[i] = false; // Initialize all nodes as not visited
        }
        for (int[] edge : edgesInput) {
            int start = edge[0];
            int end = edge[1];
            adjacencyMatrix[start][end] = 1; // Set adjacency matrix based on edges
        }
    }

    // Method to start the cycle detection process
    public void start() {
        for (int i = 0; i < nodes; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            dfs(i, i, temp); // Call DFS for each node to detect cycles
            for (int j = 0; j < nodes; j++) {
                adjacencyMatrix[i][j] = 0; // Reset the adjacency matrix for the next DFS call
                adjacencyMatrix[j][i] = 0;
            }
        }
    }

    // Private method to perform DFS and detect cycles
    private void dfs(Integer start, Integer curr, ArrayList<Integer> temp) {
        temp.add(curr);
        visited[curr] = true; // Mark the current node as visited
        for (int i = 0; i < nodes; i++) {
            if (adjacencyMatrix[curr][i] == 1) { // Check for adjacent nodes
                if (i == start) {
                    cycles.add(new ArrayList<>(temp)); // If cycle is detected, add to cycles list
                } else {
                    if (!visited[i]) {
                        dfs(start, i, temp); // Recursively call DFS for unvisited adjacent nodes
                    }
                }
            }
        }
        if (temp.size() > 0) {
            temp.remove(temp.size() - 1); // Backtrack
        }
        visited[curr] = false; // Mark the current node as not visited for other paths
    }

    // Method to print all detected cycles
    public void printAll() {
        if (cycles.isEmpty()) {
            System.out.println("No cycles found.");
            return;
        }
        for (ArrayList<Integer> cycle : cycles) {
            for (int i = 0; i < cycle.size(); i++) {
                System.out.print(cycle.get(i) + " -> "); // Print each node in the cycle
            }
            System.out.println(cycle.get(0)); // Print the first node again to complete the cycle
            System.out.println();
        }
    }
}

// Main class to run the cycle detection program
public final class Main {
    private Main() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int nodes = scanner.nextInt(); // Read the number of nodes
        int edges = scanner.nextInt(); // Read the number of edges
        int[][] edgesInput = new int[edges][2];
        for (int i = 0; i < edges; i++) {
            edgesInput[i][0] = scanner.nextInt(); // Read the start node of each edge
            edgesInput[i][1] = scanner.nextInt(); // Read the end node of each edge
        }
        Cycle cycleFinder = new Cycle(nodes, edges, edgesInput);
        cycleFinder.start(); // Start cycle detection
        cycleFinder.printAll(); // Print all detected cycles
    }
}
