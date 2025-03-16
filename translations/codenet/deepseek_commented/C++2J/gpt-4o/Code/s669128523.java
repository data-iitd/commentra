import java.util.Scanner;

public class DepthFirstSearch {
    static final int N = 100; // Define the maximum number of nodes
    static final int WHITE = 0; // Define WHITE color
    static final int GRAY = 1; // Define GRAY color
    static final int BLACK = 2; // Define BLACK color

    static int[][] M = new int[N][N]; // Declare the adjacency matrix
    static int n; // Number of nodes
    static int[] color = new int[N], d = new int[N], f = new int[N]; // Declare color, discovery time, finish time
    static int tt; // Time counter

    // Depth-first search visit function
    static void dfsVisit(int u) {
        color[u] = GRAY; // Set the color of node u to GRAY
        d[u] = ++tt; // Record the discovery time of u
        for (int v = 0; v < n; v++) {
            if (M[u][v] == 0)
                continue; // Skip if there is no edge from u to v
            if (color[v] == WHITE) { // If v is WHITE, recursively visit v
                dfsVisit(v);
            }
        }
        color[u] = BLACK; // Set the color of node u to BLACK
        f[u] = ++tt; // Record the finish time of u
    }

    // Depth-first search function
    static void dfs() {
        for (int i = 0; i < n; i++) {
            color[i] = WHITE; // Initialize all nodes to WHITE
        }
        tt = 0; // Reset the time counter

        for (int u = 0; u < n; u++) {
            if (color[u] == WHITE) // If u is WHITE, start a DFS from u
                dfsVisit(u);
        }

        for (int i = 0; i < n; i++)
            System.out.println((i + 1) + " " + d[i] + " " + f[i]); // Print the discovery and finish times for each node
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k, u, v;
        n = scanner.nextInt(); // Read the number of nodes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                M[i][j] = 0; // Initialize the adjacency matrix
        }
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt(); // Read the node
            k = scanner.nextInt(); // Read the number of its neighbors
            u--; // Convert to 0-based index
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt(); // Read the neighbor
                v--; // Convert to 0-based index
                M[u][v] = 1; // Set the edge in the adjacency matrix
            }
        }

        dfs(); // Perform the depth-first search and print the results
        scanner.close();
    }
}

// <END-OF-CODE>
