import java.util.*;
import java.util.HashMap;

public class Main {
    // Depth-first search (DFS) to explore the graph and track the order of nodes
    public void btrack(Map<Integer, List<Integer>> adjList, int[] visited, Stack<Integer> dfsCallsNodes, int currentNode) {
        // Mark the current node as visited
        visited[currentNode] = 1;
        // Get the neighbors of the current node
        List<Integer> neighbors = adjList.get(currentNode);
        // Explore each neighbor that has not been visited
        if (neighbors != null) {
            for (int neighbor : neighbors) {
                if (visited[neighbor] == -1) {
                    btrack(adjList, visited, dfsCallsNodes, neighbor);
                }
            }
        }
        // Add the current node to the stack after exploring all its neighbors
        dfsCallsNodes.add(currentNode);
    }

    // DFS for the reverse graph to find strongly connected components (SCCs)
    public void btrack2(Map<Integer, List<Integer>> adjRevList, int[] visited, int currentNode, List<Integer> newScc) {
        // Mark the current node as visited
        visited[currentNode] = 1;
        // Add the current node to the current strongly connected component
        newScc.add(currentNode);
        // Get the neighbors of the current node in the reverse graph
        List<Integer> neighbors = adjRevList.get(currentNode);
        // Explore each neighbor that has not been visited
        if (neighbors != null) {
            for (int neighbor : neighbors) {
                if (visited[neighbor] == -1) {
                    btrack2(adjRevList, visited, neighbor, newScc);
                }
            }
        }
    }

    // Main function to compute the number of strongly connected components
    public int getOutput(Map<Integer, List<Integer>> adjList, int n) {
        // Initialize visited array and stack for DFS
        int[] visited = new int[n];
        Arrays.fill(visited, -1);
        Stack<Integer> dfsCallsNodes = new Stack<>();
        
        // Perform DFS on each node to fill the stack with the finishing order
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                btrack(adjList, visited, dfsCallsNodes, i);
            }
        }

        // Create the reverse graph
        Map<Integer, List<Integer>> adjRevList = new HashMap<>();
        for (int i = 0; i < n; i++) {
            adjRevList.put(i, new ArrayList<>());
        }
        // Populate the reverse graph
        for (int i = 0; i < n; i++) {
            List<Integer> neighbors = adjList.get(i);
            if (neighbors != null) {
                for (int neighbor : neighbors) {
                    adjRevList.get(neighbor).add(i);
                }
            }
        }

        // Reset visited array for the second DFS
        Arrays.fill(visited, -1);
        int stronglyConnectedComponents = 0;

        // Process nodes in the order defined by the first DFS
        while (!dfsCallsNodes.isEmpty()) {
            int node = dfsCallsNodes.pop();
            // If the node has not been visited, it starts a new SCC
            if (visited[node] == -1) {
                List<Integer> newScc = new ArrayList<>();
                btrack2(adjRevList, visited, node, newScc);
                stronglyConnectedComponents++;
            }
        }
        // Return the total number of strongly connected components found
        return stronglyConnectedComponents;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            // Read number of nodes and edges from input
            int n = scanner.nextInt();
            int e = scanner.nextInt();
            Map<Integer, List<Integer>> adjList = new HashMap<>();
            // Build the adjacency list from input edges
            for (int i = 0; i < e; i++) {
                int src = scanner.nextInt();
                int dest = scanner.nextInt();
                adjList.putIfAbsent(src, new ArrayList<>());
                adjList.get(src).add(dest);
            }
            // Create an instance of the SCC finder and get the result
            Main sccFinder = new Main();
            int result = sccFinder.getOutput(adjList, n);
            // Output the number of strongly connected components
            System.out.println("Number of strongly connected components: " + result);
        } catch (InputMismatchException e) {
            // Handle invalid input
            System.out.println("Invalid input. Please provide integers as input.");
        } finally {
            // Close the scanner to prevent resource leaks
            scanner.close();
        }
    }
}
