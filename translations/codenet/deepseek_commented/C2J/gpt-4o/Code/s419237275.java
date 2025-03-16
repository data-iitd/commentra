import java.util.Scanner;

public class GraphDFS {
    static final int N = 200;  // Maximum number of nodes in the graph
    static final int SHIRO = 0;  // Color representing unvisited nodes
    static final int HAI = 1;  // Color representing nodes currently in the recursion stack
    static final int KURO = 2;  // Color representing nodes fully processed

    static int n;  // Number of nodes
    static int[][] A = new int[N][N];  // Adjacency matrix
    static int[] color = new int[N], d = new int[N], f = new int[N];  // color, discovery time, finish time
    static int TT;  // Time counter

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int u, k, v;  // u: current node, k: number of edges from u, v: adjacent node

        // Read the number of nodes
        n = scanner.nextInt();

        // Initialize the adjacency matrix to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }

        // Read the edges for each node and update the adjacency matrix
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt() - 1;  // Adjust for 0-based indexing
            k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt() - 1;  // Adjust for 0-based indexing
                A[u][v] = 1;
            }
        }

        // Perform DFS and print the results
        aaaaa();

        scanner.close();
    }

    // Depth-First Search (DFS) function
    static void aaaaa() {
        // Initialize all nodes to "SHIRO" (unvisited)
        for (int i = 0; i < n; i++) {
            color[i] = SHIRO;
        }

        // Set the time counter to zero
        TT = 0;

        // Iterate over all nodes and perform DFS if the node is "SHIRO"
        for (int u = 0; u < n; u++) {
            if (color[u] == SHIRO) {
                bbbbb(u);
            }
        }

        // Print the discovery and finish times for each node
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
        }
    }

    // Recursive DFS function
    static void bbbbb(int k) {
        // Set the current node's color to "HAI" (currently in the recursion stack)
        color[k] = HAI;
        // Increment the time counter and record the discovery time
        TT++;
        d[k] = TT;

        // Iterate over all nodes and perform DFS recursively if an adjacent node is "SHIRO"
        for (int v = 0; v < n; v++) {
            if (A[k][v] == 0) continue;  // Skip if no edge between k and v
            if (color[v] == SHIRO) {
                bbbbb(v);
            }
        }

        // Set the current node's color to "KURO" (fully processed)
        color[k] = KURO;
        // Record the finish time
        f[k] = ++TT;
    }
}
// <END-OF-CODE>
