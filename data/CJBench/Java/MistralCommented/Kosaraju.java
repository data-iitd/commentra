import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.Scanner; // Import necessary libraries

public class Main {
    // Declare instance variables
    private final Stack<Integer> stack = new Stack<>();
    private List<Integer> scc = new ArrayList<>();
    private final List<List<Integer>> sccsList = new ArrayList<>();

    // Method to find strongly connected components using Kosaraju's algorithm
    public List<List<Integer>> kosaraju(int v, List<List<Integer>> list) {
        // Sort edges by their finish time (LTS)
        sortEdgesByLowestFinishTime(v, list);

        // Create the transpose graph
        List<List<Integer>> transposeGraph = createTransposeMatrix(v, list);

        // Find strongly connected components in the transpose graph
        findStronglyConnectedComponents(v, transposeGraph);

        return sccsList;
    }

    // Sort edges by their lowest finish time (LTS)
    private void sortEdgesByLowestFinishTime(int v, List<List<Integer>> list) {
        int[] vis = new int[v]; // Initialize a visited array

        // DFS traversal to compute LTS for all vertices
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, list);
            }
        }
    }

    // Depth-First Search (DFS) to compute LTS
    private void dfs(int node, int[] vis, List<List<Integer>> list) {
        // Mark the current node as visited
        vis[node] = 1;

        // Recur for all neighbors
        for (Integer neighbor : list.get(node)) {
            if (vis[neighbor] == 0) {
                dfs(neighbor, vis, list);
            }
        }

        // Push the current node to the stack
        stack.push(node);
    }

    // Create the transpose graph
    private List<List<Integer>> createTransposeMatrix(int v, List<List<Integer>> list) {
        List<List<Integer>> transposeGraph = new ArrayList<>(); // Initialize the transpose graph

        // Create an adjacency list for the transpose graph
        for (int i = 0; i < v; i++) {
            transposeGraph.add(new ArrayList<>());
        }

        // Add edges from the transpose graph
        for (int i = 0; i < v; i++) {
            for (Integer neighbor : list.get(i)) {
                transposeGraph.get(neighbor).add(i);
            }
        }

        return transposeGraph;
    }

    // Find strongly connected components in the transpose graph
    private void findStronglyConnectedComponents(int v, List<List<Integer>> transposeGraph) {
        int[] vis = new int[v]; // Initialize a visited array

        // DFS traversal to find SCCs
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (vis[node] == 0) {
                dfs2(node, vis, transposeGraph);
                sccsList.add(scc); // Add the SCC to the list
                scc = new ArrayList<>(); // Initialize a new SCC
            }
        }
    }

    // Depth-First Search (DFS) to find SCCs
    private void dfs2(int node, int[] vis, List<List<Integer>> list) {
        // Mark the current node as visited
        vis[node] = 1;

        // Add the current node to the SCC
        scc.add(node);

        // Recur for all neighbors
        for (Integer neighbor : list.get(node)) {
            if (vis[neighbor] == 0) {
                dfs2(neighbor, vis, list);
            }
        }
    }

    // Main method to read input and call the kosaraju method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize a scanner to read input

        int vertices = sc.nextInt(); // Read the number of vertices
        int edges = sc.nextInt(); // Read the number of edges

        List<List<Integer>> adjacencyList = new ArrayList<>(); // Initialize an empty adjacency list

        // Create the adjacency list based on input
        for (int i = 0; i < vertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        for (int i = 0; i < edges; i++) {
            int u = sc.nextInt(); // Read the source vertex
            int v = sc.nextInt(); // Read the destination vertex
            adjacencyList.get(u).add(v); // Add the edge from u to v
        }

        Main kosaraju = new Main(); // Initialize an instance of the Main class
        List<List<Integer>> sccs = kosaraju.kosaraju(vertices, adjacencyList); // Call the kosaraju method

        System.out.println("Strongly Connected Components:"); // Print the header for SCCs
        for (List<Integer> scc : sccs) {
            System.out.println(scc); // Print each SCC
        }

        sc.close(); // Close the scanner
    }
}
