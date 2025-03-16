import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    private int time; // Variable to keep track of the time steps during DFS
    private final List<List<Integer>> sccList = new ArrayList<>(); // List to store the list of strongly connected components

    // Method to find strongly connected components using Tarjan's algorithm
    public List<List<Integer>> stronglyConnectedComponents(int v, List<List<Integer>> graph) {
        int[] lowTime = new int[v]; // Array to store the lowest insertion time of any node reachable from the current node
        int[] insertionTime = new int[v]; // Array to store the insertion time of each node
        boolean[] isInStack = new boolean[v]; // Array to keep track of nodes currently in the stack
        Stack<Integer> stack = new Stack<>(); // Stack to keep track of nodes in the current SCC

        // Initialize insertionTime and lowTime for all vertices to -1
        for (int i = 0; i < v; i++) {
            insertionTime[i] = -1;
            lowTime[i] = -1;
        }

        // Perform DFS for each unvisited node
        for (int i = 0; i < v; i++) {
            if (insertionTime[i] == -1) {
                dfs(i, lowTime, insertionTime, isInStack, stack, graph);
            }
        }

        return sccList;
    }

    // Depth-first search method to find SCCs
    private void dfs(int u, int[] lowTime, int[] insertionTime, boolean[] isInStack, Stack<Integer> stack, List<List<Integer>> graph) {
        insertionTime[u] = time; // Set the insertion time of the current node
        lowTime[u] = time; // Set the low time of the current node
        time++; // Increment the time step
        stack.push(u); // Push the current node onto the stack
        isInStack[u] = true; // Mark the current node as being in the stack

        // Visit all adjacent nodes
        for (Integer v : graph.get(u)) {
            if (insertionTime[v] == -1) { // If the adjacent node is not visited
                dfs(v, lowTime, insertionTime, isInStack, stack, graph);
                lowTime[u] = Math.min(lowTime[u], lowTime[v]); // Update the low time of the current node
            } else if (isInStack[v]) { // If the adjacent node is in the stack
                lowTime[u] = Math.min(lowTime[u], insertionTime[v]); // Update the low time of the current node
            }
        }

        // If the current node is the root of an SCC
        if (lowTime[u] == insertionTime[u]) {
            List<Integer> scc = new ArrayList<>(); // List to store the current SCC
            int w;
            do {
                w = stack.pop(); // Pop nodes from the stack until the current node is reached
                scc.add(w); // Add the node to the SCC list
                isInStack[w] = false; // Mark the node as not being in the stack
            } while (w != u); // Continue until the current node is reached
            sccList.add(scc); // Add the SCC to the list of SCCs
        }
    }

    // Main method to read input, construct the graph, and find and print SCCs
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt(); // Read the number of vertices
        int edges = scanner.nextInt(); // Read the number of edges
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(from).add(to); // Add an edge to the graph
        }
        scanner.close();

        Main tarjans = new Main();
        List<List<Integer>> sccs = tarjans.stronglyConnectedComponents(vertices, graph);
        for (List<Integer> scc : sccs) {
            System.out.println(scc); // Print each SCC
        }
    }
}
