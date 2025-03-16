import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    // Declare instance variables
    private int time;
    private final List<List<Integer>> sccList = new ArrayList<>();

    // Method to find strongly connected components
    public List<List<Integer>> stronglyConnectedComponents(int v, List<List<Integer>> graph) {
        // Initialize arrays and stack
        int[] lowTime = new int[v];
        int[] insertionTime = new int[v];
        boolean[] isInStack = new boolean[v];
        Stack<Integer> stack = new Stack<>();

        // Initialize arrays with default values
        for (int i = 0; i < v; i++) {
            insertionTime[i] = -1;
            lowTime[i] = -1;
        }

        // Iterate through each vertex that hasn't been processed yet
        for (int i = 0; i < v; i++) {
            if (insertionTime[i] == -1) {
                // Call depth-first search recursively
                dfs(i, lowTime, insertionTime, isInStack, stack, graph);
            }
        }

        // Return the list of strongly connected components
        return sccList;
    }

    // Depth-first search method
    private void dfs(int u, int[] lowTime, int[] insertionTime, boolean[] isInStack, Stack<Integer> stack, List<List<Integer>> graph) {
        // Set the insertion time and low time for the current vertex
        insertionTime[u] = time;
        lowTime[u] = time;
        time++;

        // Push the current vertex onto the stack
        stack.push(u);

        // Set the vertex as in the stack
        isInStack[u] = true;

        // Iterate through the neighbors of the current vertex
        for (Integer v : graph.get(u)) {
            // If the neighbor hasn't been processed yet
            if (insertionTime[v] == -1) {
                // Call depth-first search recursively for the neighbor
                dfs(v, lowTime, insertionTime, isInStack, stack, graph);

                // Update the low time for the current vertex
                lowTime[u] = Math.min(lowTime[u], lowTime[v]);
            } else if (isInStack[v]) {
                // Update the low time for the current vertex if it's in the stack
                lowTime[u] = Math.min(lowTime[u], insertionTime[v]);
            }
        }

        // If the low time equals the insertion time, a strongly connected component has been found
        if (lowTime[u] == insertionTime[u]) {
            // Create a new list for the strongly connected component
            List<Integer> scc = new ArrayList<>();

            // Pop vertices from the stack until the current vertex is reached
            int w;
            do {
                w = stack.pop();
                scc.add(w);
            } while (w != u);

            // Add the strongly connected component to the list
            sccList.add(scc);
        }
    }

    // Main method to read input and call the strongly connected components method
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices and edges from the console
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        // Create an empty list to store the graph
        List<List<Integer>> graph = new ArrayList<>();

        // Initialize the graph with the given number of vertices
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }

        // Read edges from the console and add them to the graph
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(from).add(to);
        }

        // Close the Scanner object
        scanner.close();

        // Create an instance of the Main class and call the strongly connected components method
        Main tarjans = new Main();
        List<List<Integer>> sccs = tarjans.stronglyConnectedComponents(vertices, graph);

        // Print the strongly connected components
        for (List<Integer> scc : sccs) {
            System.out.println(scc);
        }
    }
}
