import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    // Variable to count the number of nodes in the current DFS traversal
    int count;
    // Array to track which nodes have been visited
    boolean[] seen;
    // Constants to represent the state of the traversal
    int path = 0, cycle = 1;
    // Adjacency list representation of the graph
    LinkedList<LinkedList<Integer>> graph;

    // Depth-First Search (DFS) method to explore the graph
    public int dfs(int child, int par) {
        // If the current node has already been seen, return cycle indicator
        if (seen[child] == true) return cycle;
        // Mark the current node as seen
        seen[child] = true;
        
        // Iterate through all adjacent nodes of the current node
        for (Integer i : graph.get(child)) {
            // Avoid going back to the parent node
            if (i != par) {
                this.count++; // Increment the count of nodes visited
                // Recursively call DFS on the adjacent node
                if (dfs(i, child) == cycle) return cycle; // Check for cycles
            }
        }
        // Return path indicator if no cycle is found
        return path;
    }

    public static void main(String[] args) {
        // Create a scanner object for input
        Scanner sc = new Scanner(System.in);
        
        // Read the number of nodes (m) and edges (n)
        int m = sc.nextInt();
        int n = sc.nextInt();
        
        // Create an instance of Main to access graph and related variables
        Main ft = new Main();
        ft.graph = new LinkedList<>();
        
        // Initialize the graph with empty linked lists for each node
        for (int i = 0; i <= m; i++) {
            ft.graph.add(new LinkedList<Integer>());
        }
        
        // Initialize the seen array to track visited nodes
        ft.seen = new boolean[m + 1];
        
        // Read the edges and populate the graph
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            // Add the edge in both directions (undirected graph)
            ft.graph.get(x).add(y);
            ft.graph.get(y).add(x);
        }
        
        // Variable to count the number of nodes to remove
        int toremove = 0;
        
        // Iterate through all nodes to check for unvisited nodes
        for (int i = 1; i <= m; i++) {
            // If the node has not been seen, perform DFS
            if (!ft.seen[i]) {
                ft.count = 0; // Reset count for the new component
                // Check if the DFS from this node finds a cycle
                if (ft.dfs(i, 0) == ft.cycle) {
                    // If a cycle is found and the count of nodes is odd, increment toremove
                    if (ft.count % 2 == 1) toremove++;
                }
            }
        }
        
        // Adjust the number of nodes to remove if the remaining nodes are odd
        if ((m - toremove) % 2 == 1) toremove++;
        
        // Output the result: number of nodes to remove
        System.out.println(toremove);
    }
}
