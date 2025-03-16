import java.util.*;
import java.util.HashMap;
public class Main {
    // First Depth-First Search (DFS) Traversal to populate the stack with nodes in finishing times order
    public void btrack(Map<Integer, List<Integer>> adjList, int[] visited, Stack<Integer> dfsCallsNodes, int currentNode) {
        visited[currentNode] = 1; // Mark the current node as visited
        List<Integer> neighbors = adjList.get(currentNode);
        if (neighbors != null) {
            for (int neighbor : neighbors) {
                if (visited[neighbor] == -1) { // If the neighbor is not visited, recursively call btrack
                    btrack(adjList, visited, dfsCallsNodes, neighbor);
                }
            }
        }
        dfsCallsNodes.add(currentNode); // Push the current node onto the stack after exploring all neighbors
    }

    // Second DFS Traversal to find Strongly Connected Components (SCCs) in the reversed graph
    public void btrack2(Map<Integer, List<Integer>> adjRevList, int[] visited, int currentNode, List<Integer> newScc) {
        visited[currentNode] = 1; // Mark the current node as visited
        newScc.add(currentNode); // Add the current node to the current SCC
        List<Integer> neighbors = adjRevList.get(currentNode);
        if (neighbors != null) {
            for (int neighbor : neighbors) {
                if (visited[neighbor] == -1) { // If the neighbor is not visited, recursively call btrack2
                    btrack2(adjRevList, visited, neighbor, newScc);
                }
            }
        }
    }

    // Method to get the number of strongly connected components in the graph
    public int getOutput(Map<Integer, List<Integer>> adjList, int n) {
        int[] visited = new int[n];
        Arrays.fill(visited, -1); // Initialize visited array with -1 (unvisited)
        Stack<Integer> dfsCallsNodes = new Stack<>();
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) { // If the node is not visited, start DFS from it
                btrack(adjList, visited, dfsCallsNodes, i);
            }
        }
        Map<Integer, List<Integer>> adjRevList = new HashMap<>();
        for (int i = 0; i < n; i++) {
            adjRevList.put(i, new ArrayList<>()); // Initialize the reversed adjacency list
        }
        for (int i = 0; i < n; i++) {
            List<Integer> neighbors = adjList.get(i);
            if (neighbors != null) {
                for (int neighbor : neighbors) {
                    adjRevList.get(neighbor).add(i); // Reverse the edges to create the reversed adjacency list
                }
            }
        }
        Arrays.fill(visited, -1); // Reset the visited array for the second DFS traversal
        int stronglyConnectedComponents = 0;
        while (!dfsCallsNodes.isEmpty()) {
            int node = dfsCallsNodes.pop();
            if (visited[node] == -1) { // If the node is not visited, start a new SCC search from it
                List<Integer> newScc = new ArrayList<>();
                btrack2(adjRevList, visited, node, newScc);
                stronglyConnectedComponents++; // Increment the count of SCCs
            }
        }
        return stronglyConnectedComponents; // Return the total number of SCCs
    }

    // Main method to read input, construct the graph, and find the number of SCCs
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            int n = scanner.nextInt(); // Read the number of nodes
            int e = scanner.nextInt(); // Read the number of edges
            Map<Integer, List<Integer>> adjList = new HashMap<>();
            for (int i = 0; i < e; i++) {
                int src = scanner.nextInt(); // Read the source node
                int dest = scanner.nextInt(); // Read the destination node
                adjList.putIfAbsent(src, new ArrayList<>());
                adjList.get(src).add(dest); // Construct the adjacency list
            }
            Main sccFinder = new Main();
            int result = sccFinder.getOutput(adjList, n);
            System.out.println("Number of strongly connected components: " + result); // Print the result
        } catch (InputMismatchException e) {
            System.out.println("Invalid input. Please provide integers as input."); // Handle invalid input
        } finally {
            scanner.close(); // Close the scanner
        }
    }
}
