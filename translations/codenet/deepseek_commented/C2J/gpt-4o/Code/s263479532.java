import java.util.Scanner;

public class PrimAlgorithm {
    static final int MAX = 100;
    static final int INF = 999999;
    static final int NIL = -1;
    static final int WHITE = 0;
    static final int BLACK = 2;

    static int n;
    static int[][] G = new int[MAX][MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        // Read the number of vertices from the input.

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                G[i][j] = scanner.nextInt();
            }
        }
        // Read the adjacency matrix representing the graph from the input.

        System.out.println(prim());
        // Call the prim function and print the result.

        scanner.close();
    }

    static int prim() {
        int u, mincost, sum = 0;
        int[] d = new int[n];
        int[] pi = new int[n];
        int[] color = new int[n];

        // Initialize all distances to infinity, predecessors to nil, and colors to white.
        for (u = 0; u < n; u++) {
            d[u] = INF;
            pi[u] = NIL;
            color[u] = WHITE;
        }

        d[0] = 0; // Set the distance of the first vertex to 0.

        while (true) {
            mincost = INF;

            // Find the vertex with the smallest distance that is not yet black.
            for (int i = 0; i < n; i++) {
                if (color[i] != BLACK && d[i] < mincost) {
                    mincost = d[i];
                    u = i;
                }
            }

            if (mincost == INF) break; // If no more vertices can be reached, break the loop.

            color[u] = BLACK; // Mark the current vertex as black.

            // Update the distances and predecessors for the neighboring vertices that are not black and have a valid edge weight.
            for (int v = 0; v < n; v++) {
                if (color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1) {
                    pi[v] = u;
                    d[v] = G[u][v];
                }
            }
        }

        // Calculate the total cost of the Minimum Spanning Tree by summing up the distances of all vertices.
        for (int i = 0; i < n; i++) {
            if (d[i] != INF) sum += d[i];
        }

        return sum;
    }
}
// <END-OF-CODE>
