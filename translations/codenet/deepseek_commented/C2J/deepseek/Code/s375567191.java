import java.util.Scanner;

public class DepthFirstSearch {
    static final int MAX = 101;
    static final int WHITE = 0;
    static final int BLACK = 2;
    static final int GRAY = 1;

    static int time, n;
    static int[][] g = new int[MAX][MAX];
    static int[] d = new int[MAX];
    static int[] f = new int[MAX];
    static int[] color = new int[MAX];

    // The visit function performs a depth-first search on the graph.
    static void visit(int u) {
        color[u] = GRAY;  // Set the color of the current node to gray.
        d[u] = ++time;    // Record the discovery time.

        for (int i = 0; i < n; i++) {
            if (g[u][i] == 0)
                continue;  // Skip if there is no edge between u and i.
            if (color[i] == WHITE)
                visit(i);  // Recursively visit adjacent white nodes.
        }

        color[u] = BLACK;  // Set the color of the current node to black.
        f[u] = ++time;     // Record the finishing time.
    }

    // The dfs function initializes the time and iterates through all nodes.
    static void dfs() {
        time = 0;  // Initialize the time.

        for (int i = 0; i < n; i++)
            if (color[i] == WHITE)
                visit(i);  // Call visit for any white node.

        for (int i = 0; i < n; i++)
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);  // Print the discovery and finishing times of each node.
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();  // Read the number of nodes.

        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            for (int j = 0; j < y; j++) {
                int z = scanner.nextInt();
                g[x - 1][z - 1] = 1;  // Populate the adjacency matrix.
            }
        }

        dfs();  // Call the dfs function to compute and print the discovery and finishing times.
        scanner.close();
    }
}
