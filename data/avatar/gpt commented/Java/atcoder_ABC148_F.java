import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        // Initialize the scanner to read input
        try (Scanner sc = new Scanner(System.in)) {
            // Read the number of nodes (N) and the two specific nodes (u and v)
            int N = sc.nextInt();
            int u = sc.nextInt() - 1; // Convert to zero-based index
            int v = sc.nextInt() - 1; // Convert to zero-based index
            
            // Create an adjacency list to represent the edges of the graph
            List<Integer>[] edges = new List[N];
            for (int i = 0; i < N; i++) {
                edges[i] = new ArrayList<>();
            }
            
            // Read the edges and populate the adjacency list
            for (int i = 0; i < N - 1; i++) {
                int a = sc.nextInt() - 1; // Convert to zero-based index
                int b = sc.nextInt() - 1; // Convert to zero-based index
                edges[a].add(b); // Add edge from a to b
                edges[b].add(a); // Add edge from b to a (undirected graph)
            }
            
            // Initialize distance array for the first node (u)
            int[] d = new int[N];
            for (int i = 0; i < N; i++) {
                d[i] = Integer.MAX_VALUE; // Set initial distances to infinity
            }
            d[u] = 0; // Distance to itself is 0
            
            // Perform DFS from node u to calculate distances
            dfs(u, d, edges);
            
            // Initialize distance array for the second node (v)
            int[] e = new int[N];
            for (int i = 0; i < N; i++) {
                e[i] = Integer.MAX_VALUE; // Set initial distances to infinity
            }
            e[v] = 0; // Distance to itself is 0
            
            // Perform DFS from node v to calculate distances
            dfs(v, e, edges);
            
            // Find the maximum distance from node u to any node that is closer to v
            int q = -1;
            for (int i = 0; i < N; i++) {
                if (d[i] < e[i]) { // Check if node i is closer to u than to v
                    if (e[i] > q) { // Update q if the distance to v is greater
                        q = e[i];
                    }
                }
            }
            
            // Output the result based on the maximum distance found
            if (q <= 0) {
                System.out.println(0); // If no valid distance found, print 0
            } else {
                System.out.println(q - 1); // Print the maximum distance minus 1
            }
        }
    }

    // Depth-first search (DFS) to calculate distances from a given node
    static void dfs(int u, int[] d, List<Integer>[] edges) {
        for (Integer nu : edges[u]) {
            if (d[nu] == Integer.MAX_VALUE) { // If the node has not been visited
                d[nu] = d[u] + 1; // Update the distance
                dfs(nu, d, edges); // Recursively visit the next node
            }
        }
    }
}
