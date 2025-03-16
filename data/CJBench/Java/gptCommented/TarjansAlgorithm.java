import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    // Variable to keep track of the time during DFS
    private int time;
    // List to store the strongly connected components
    private final List<List<Integer>> sccList = new ArrayList<>();

    // Method to find strongly connected components using Tarjan's algorithm
    public List<List<Integer>> stronglyConnectedComponents(int v, List<List<Integer>> graph) {
        // Arrays to store the low time and insertion time of each vertex
        int[] lowTime = new int[v];
        int[] insertionTime = new int[v];
        // Boolean array to check if a vertex is in the stack
        boolean[] isInStack = new boolean[v];
        // Stack to hold the vertices during DFS
        Stack<Integer> stack = new Stack<>();

        // Initialize insertion and low times for all vertices
        for (int i = 0; i < v; i++) {
            insertionTime[i] = -1;
            lowTime[i] = -1;
        }

        // Perform DFS for each vertex that has not been visited
        for (int i = 0; i < v; i++) {
            if (insertionTime[i] == -1) {
                dfs(i, lowTime, insertionTime, isInStack, stack, graph);
            }
        }
        // Return the list of strongly connected components
        return sccList;
    }

    // Depth-First Search method to explore the graph and find SCCs
    private void dfs(int u, int[] lowTime, int[] insertionTime, boolean[] isInStack, Stack<Integer> stack, List<List<Integer>> graph) {
        // Set the insertion and low time for the current vertex
        insertionTime[u] = time;
        lowTime[u] = time;
        time++;
        // Push the current vertex onto the stack
        stack.push(u);
        isInStack[u] = true;

        // Explore all adjacent vertices
        for (Integer v : graph.get(u)) {
            // If the vertex has not been visited, perform DFS on it
            if (insertionTime[v] == -1) {
                dfs(v, lowTime, insertionTime, isInStack, stack, graph);
                // Update the low time of the current vertex
                lowTime[u] = Math.min(lowTime[u], lowTime[v]);
            } 
            // If the vertex is in the stack, update the low time
            else if (isInStack[v]) {
                lowTime[u] = Math.min(lowTime[u], insertionTime[v]);
            }
        }

        // If the current vertex is a root node, pop the stack and form an SCC
        if (lowTime[u] == insertionTime[u]) {
            List<Integer> scc = new ArrayList<>();
            int w;
            do {
                // Pop from the stack and add to the current SCC
                w = stack.pop();
                scc.add(w);
                isInStack[w] = false; // Mark the vertex as not in the stack
            } while (w != u);
            // Add the found SCC to the list of SCCs
            sccList.add(scc);
        }
    }

    // Main method to read input and execute the algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of vertices and edges
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        // Initialize the graph as an adjacency list
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }
        // Read the edges and populate the graph
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(from).add(to);
        }
        scanner.close(); // Close the scanner

        // Create an instance of the Main class and find SCCs
        Main tarjans = new Main();
        List<List<Integer>> sccs = tarjans.stronglyConnectedComponents(vertices, graph);
        
        // Print the strongly connected components
        for (List<Integer> scc : sccs) {
            System.out.println(scc);
        }
    }
}
