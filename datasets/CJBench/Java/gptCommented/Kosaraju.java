import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    // Stack to hold nodes in the order of their finishing times
    private final Stack<Integer> stack = new Stack<>();
    // List to hold the current strongly connected component
    private List<Integer> scc = new ArrayList<>();
    // List to hold all strongly connected components
    private final List<List<Integer>> sccsList = new ArrayList<>();

    // Main method to find strongly connected components using Kosaraju's algorithm
    public List<List<Integer>> kosaraju(int v, List<List<Integer>> list) {
        // Step 1: Sort the edges by their finishing times
        sortEdgesByLowestFinishTime(v, list);
        // Step 2: Create the transpose of the graph
        List<List<Integer>> transposeGraph = createTransposeMatrix(v, list);
        // Step 3: Find strongly connected components in the transposed graph
        findStronglyConnectedComponents(v, transposeGraph);
        return sccsList; // Return the list of strongly connected components
    }

    // Method to perform DFS and fill the stack with nodes based on their finishing times
    private void sortEdgesByLowestFinishTime(int v, List<List<Integer>> list) {
        int[] vis = new int[v]; // Array to track visited nodes
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, list); // Perform DFS if the node is not visited
            }
        }
    }

    // Method to create the transpose of the given graph
    private List<List<Integer>> createTransposeMatrix(int v, List<List<Integer>> list) {
        List<List<Integer>> transposeGraph = new ArrayList<>();
        // Initialize the transpose graph
        for (int i = 0; i < v; i++) {
            transposeGraph.add(new ArrayList<>());
        }
        // Fill the transpose graph with reversed edges
        for (int i = 0; i < v; i++) {
            for (Integer neigh : list.get(i)) {
                transposeGraph.get(neigh).add(i); // Reverse the direction of edges
            }
        }
        return transposeGraph; // Return the transposed graph
    }

    // Method to find strongly connected components in the transposed graph
    public void findStronglyConnectedComponents(int v, List<List<Integer>> transposeGraph) {
        int[] vis = new int[v]; // Array to track visited nodes
        // Process nodes in the order defined by the stack
        while (!stack.isEmpty()) {
            int node = stack.pop(); // Get the top node from the stack
            if (vis[node] == 0) {
                dfs2(node, vis, transposeGraph); // Perform DFS on the transposed graph
                sccsList.add(scc); // Add the found SCC to the list
                scc = new ArrayList<>(); // Reset the current SCC for the next component
            }
        }
    }

    // Depth-first search method to fill the stack with nodes based on finishing times
    private void dfs(int node, int[] vis, List<List<Integer>> list) {
        vis[node] = 1; // Mark the node as visited
        for (Integer neighbour : list.get(node)) {
            if (vis[neighbour] == 0) {
                dfs(neighbour, vis, list); // Recursively visit unvisited neighbours
            }
        }
        stack.push(node); // Push the node onto the stack after visiting all neighbours
    }

    // Depth-first search method to collect nodes in the current strongly connected component
    private void dfs2(int node, int[] vis, List<List<Integer>> list) {
        vis[node] = 1; // Mark the node as visited
        for (Integer neighbour : list.get(node)) {
            if (vis[neighbour] == 0) {
                dfs2(neighbour, vis, list); // Recursively visit unvisited neighbours
            }
        }
        scc.add(node); // Add the node to the current SCC
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertices = sc.nextInt(); // Read number of vertices
        int edges = sc.nextInt(); // Read number of edges
        List<List<Integer>> adjacencyList = new ArrayList<>();
        // Initialize the adjacency list for the graph
        for (int i = 0; i < vertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        // Read edges and populate the adjacency list
        for (int i = 0; i < edges; i++) {
            int u = sc.nextInt(); // Read start vertex of the edge
            int v = sc.nextInt(); // Read end vertex of the edge
            adjacencyList.get(u).add(v); // Add the edge to the adjacency list
        }
        // Create an instance of Main to use the kosaraju method
        Main kosaraju = new Main();
        // Find strongly connected components
        List<List<Integer>> sccs = kosaraju.kosaraju(vertices, adjacencyList);
        // Print the strongly connected components
        System.out.println("Strongly Connected Components:");
        for (List<Integer> scc : sccs) {
            System.out.println(scc); // Print each SCC
        }
        sc.close(); // Close the scanner
    }
}
