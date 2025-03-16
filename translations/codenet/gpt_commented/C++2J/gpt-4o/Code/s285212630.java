import java.util.*;

public class Main {
    // Define constants for maximum levels and infinity
    static final long INF = 1145141919;
    static final int MAX_L = 22;

    // Global variables
    static int N; // Number of nodes in the tree
    static List<Pair>[] G; // Adjacency list representation of the tree
    static int[][] U; // U for storing ancestors
    static int[] R; // R for depth
    static long[] L; // L for storing the distance from the root

    // Pair class to store node and weight
    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    // Depth-first search to initialize ancestor and depth information
    static void dfs(int x, int p, int r, long l) {
        U[0][x] = p; // Set the parent of the current node
        R[x] = r; // Set the depth of the current node
        L[x] = l; // Set the distance from the root to the current node
        for (Pair pp : G[x]) { // Iterate through all adjacent nodes
            int t = pp.first; // Get the adjacent node
            if (t == p) continue; // Skip the parent node to avoid cycles
            dfs(t, x, r + 1, l + pp.second); // Recursive DFS call for the child node
        }
    }

    // Function to find the lowest common ancestor (LCA) of two nodes
    static int lca(int a, int b) {
        if (R[a] > R[b]) {
            int temp = a;
            a = b;
            b = temp; // Ensure a is the deeper node
        }
        for (int k = 0; k < MAX_L; k++) { // Adjust b to the same depth as a
            if ((R[a] - R[b] >> k & 1) == 1) {
                b = U[k][b];
            }
        }
        if (a == b) return a; // If both nodes are the same, return a
        for (int k = MAX_L - 1; k >= 0; k--) { // Find the LCA using binary lifting
            if (U[k][a] != U[k][b]) {
                a = U[k][a];
                b = U[k][b];
            }
        }
        return U[0][a]; // Return the parent of a, which is the LCA
    }

    // Function to calculate the distance between two nodes
    static long dist(int x, int y) {
        int g = lca(x, y); // Find the LCA of x and y
        return L[x] + L[y] - 2 * L[g]; // Calculate the distance using LCA
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt(); // Read the number of nodes
        G = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayList<>();
        }
        U = new int[MAX_L][N]; // Initialize the ancestor table
        R = new int[N]; // Initialize depth array
        L = new long[N]; // Initialize distance array

        for (int i = 0; i < N - 1; i++) { // Read the edges of the tree
            int a = scanner.nextInt() - 1; // Read nodes and weight
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            G[a].add(new Pair(b, c)); // Add edge to the adjacency list
            G[b].add(new Pair(a, c)); // Add the reverse edge
        }

        // Initialize the ancestor table with -1
        for (int i = 0; i < MAX_L; i++) {
            Arrays.fill(U[i], -1);
        }

        // Perform DFS from the root to fill ancestor and depth information
        dfs(0, -1, 0, 0);

        // Precompute ancestors for binary lifting
        for (int i = 0; i < MAX_L - 1; i++) {
            for (int v = 0; v < N; v++) {
                if (U[i][v] == -1) U[i + 1][v] = -1; // If no ancestor, set to -1
                else U[i + 1][v] = U[i][U[i][v]]; // Set the 2^(i+1) ancestor
            }
        }

        int Q = scanner.nextInt(); // Number of queries
        int K = scanner.nextInt() - 1; // Read node K and convert to 0-based indexing

        // Process each query
        for (int i = 0; i < Q; i++) {
            int x = scanner.nextInt() - 1; // Read the nodes
            int y = scanner.nextInt() - 1; // Convert to 0-based indexing
            // Output the total distance from x to K and K to y
            System.out.println(dist(x, K) + dist(K, y));
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
