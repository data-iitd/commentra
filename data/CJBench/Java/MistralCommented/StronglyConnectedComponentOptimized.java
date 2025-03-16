
import java.util.*;

public class Main {
    // Method to perform Depth First Search (DFS) and find strongly connected components
    public void btrack(Map<Integer, List<Integer>> adjList, int[] visited, Stack<Integer> dfsCallsNodes, int currentNode) {
        // Mark the current node as visited
        visited[currentNode] = 1;

        // Get the list of neighbors for the current node
        List<Integer> neighbors = adjList.get(currentNode);

        // If the current node has neighbors, iterate through them and call recursively
        if (neighbors != null) {
            for (int neighbor : neighbors) {
                // If the neighbor is not visited, call btrack recursively
                if (visited[neighbor] == -1) {
                    btrack(adjList, visited, dfsCallsNodes, neighbor);
                }
            }
        }

        // Add the current node to the stack of DFS call nodes
        dfsCallsNodes.add(currentNode);
    }

    // Method to find strongly connected components using Depth First Search (DFS) and recursion
    public void btrack2(Map<Integer, List<Integer>> adjRevList, int[] visited, int currentNode, List<Integer> newScc) {
        // Mark the current node as visited
        visited[currentNode] = 1;

        // Add the current node to the list of nodes in the current strongly connected component
        newScc.add(currentNode);

        // Get the list of neighbors for the current node
        List<Integer> neighbors = adjRevList.get(currentNode);

        // If the current node has neighbors, iterate through them and call recursively
        if (neighbors != null) {
            for (int neighbor : neighbors) {
                // If the neighbor is not visited, call btrack2 recursively
                if (visited[neighbor] == -1) {
                    btrack2(adjRevList, visited, neighbor, newScc);
                }
            }
        }
    }

    // Method to find the number of strongly connected components in the given graph
    public int getOutput(Map<Integer, List<Integer>> adjList, int n) {
        // Initialize the visited array and fill it with -1
        int[] visited = new int[n];
        Arrays.fill(visited, -1);

        // Initialize the stack for DFS call nodes
        Stack<Integer> dfsCallsNodes = new Stack<>();

        // Iterate through all nodes in the graph and call btrack for each unvisited node
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                btrack(adjList, visited, dfsCallsNodes, i);
            }
        }

        // Initialize an empty HashMap for the reversed adjacency list
        Map<Integer, List<Integer>> adjRevList = new HashMap<>();

        // Initialize the visited array and fill it with -1
        Arrays.fill(visited, -1);

        // Initialize an empty list to store the nodes in each strongly connected component
        List<Integer> newScc = new ArrayList<>();

        // Initialize the counter for the number of strongly connected components
        int stronglyConnectedComponents = 0;

        // While there are still nodes in the stack of DFS call nodes
        while (!dfsCallsNodes.isEmpty()) {
            // Get the next node from the stack
            int node = dfsCallsNodes.pop();

            // If the node is not visited, call btrack2 recursively and increment the counter
            if (visited[node] == -1) {
                btrack2(adjRevList, visited, node, newScc);
                stronglyConnectedComponents++;
            }
        }

        // Return the number of strongly connected components
        return stronglyConnectedComponents;
    }

    // Main method to read input and call getOutput method
    public static void main(String[] args) {
        // Initialize the Scanner to read input from the console
        Scanner scanner = new Scanner(System.in);

        try {
            // Read the number of nodes and edges from the input
            int n = scanner.nextInt();
            int e = scanner.nextInt();

            // Initialize the adjacency list for the graph
            Map<Integer, List<Integer>> adjList = new HashMap<>();

            // Read the edges and add them to the adjacency list
            for (int i = 0; i < e; i++) {
                int src = scanner.nextInt();
                int dest = scanner.nextInt();
                adjList.putIfAbsent(src, new ArrayList<>());
                adjList.get(src).add(dest);
            }

            // Create an instance of the Main class and call the getOutput method
            Main sccFinder = new Main();
            int result = sccFinder.getOutput(adjList, n);

            // Print the result to the console
            System.out.println("Number of strongly connected components: " + result);
        } catch (InputMismatchException e) {
            // Print an error message if the input is invalid
            System.out.println("Invalid input. Please provide integers as input.");
        } finally {
            // Close the Scanner
            scanner.close();
        }
    }
}