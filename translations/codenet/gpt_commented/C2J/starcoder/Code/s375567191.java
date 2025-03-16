import java.util.*;

public class Main {
    public static void main(String[] args) {
        int time, n, g[][] = new int[MAX][MAX] = {0}; // Global variables: time counter, number of vertices, and adjacency matrix
        int d[] = new int[MAX], f[] = new int[MAX], color[] = new int[MAX] = {WHITE}; // Arrays for discovery time, finish time, and color of nodes

        // Function to perform DFS visit on a node
        void visit(int u) {
            int i;

            color[u] = GRAY; // Mark the node as being explored
            d[u] = ++time;   // Set the discovery time for the node

            // Explore all adjacent nodes
            for(i = 0; i < n; i++) {
                if(g[u][i] == 0) // If there is no edge to node i, skip
                    continue;
                if(color[i] == WHITE) // If the adjacent node is unvisited
                    visit(i); // Recursively visit the adjacent node
            }

            color[u] = BLACK; // Mark the node as fully explored
            f[u] = ++time;    // Set the finish time for the node
        }

        // Function to perform Depth-First Search on the graph
        void dfs(void) {
            int i;
            time = 0; // Initialize time counter

            // Visit all nodes in the graph
            for(i = 0; i < n; i++)
                if(color[i] == WHITE) // If the node is unvisited
                    visit(i); // Start a DFS visit

            // Print the discovery and finish times for each node
            for(i = 0; i < n; i++)
                System.out.printf("%d %d %d\n", i + 1, d[i], f[i]); // Output: node index, discovery time, finish time
        }

        Scanner in = new Scanner(System.in);
        int i, j, x, y, z;

        // Read the number of vertices
        n = in.nextInt();

        // Read the graph edges
        for(i = 0; i < n; i++) {
            x = in.nextInt(); // Read the node and the number of edges
            y = in.nextInt();
            for(j = 0; j < y; j++) {
                z = in.nextInt(); // Read each adjacent node
                g[x - 1][z - 1] = 1; // Update the adjacency matrix
            }
        }

        // Perform DFS on the graph
        dfs();
    }
}
