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

        // Read the number of vertices in the graph
        n = scanner.nextInt();

        // Read the adjacency matrix representation of the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                G[i][j] = scanner.nextInt();
            }
        }

        // Call Prim's algorithm and print the total weight of the minimum spanning tree
        System.out.println(prim());
        scanner.close();
    }

    static int prim() {
        int u, i, v, mincost, sum = 0;
        int[] d = new int[n];
        int[] pi = new int[n];
        int[] color = new int[n];

        // Initialize arrays for distance, parent, and color of each vertex
        for (u = 0; u < n; u++) {
            d[u] = INF;      // Set initial distances to infinity
            pi[u] = NIL;     // Set initial parents to NIL
            color[u] = WHITE; // Set initial colors to WHITE (unvisited)
        }

        // Start with the first vertex
        d[0] = 0;

        // Main loop to find the minimum spanning tree
        while (true) {
            mincost = INF;

            // Find the vertex with the minimum cost edge that is not yet included in the MST
            for (i = 0; i < n; i++) {
                if (color[i] != BLACK && d[i] < mincost) {
                    mincost = d[i];
                    u = i; // Update the vertex to be included in the MST
                }
            }

            // If no vertex is found, break the loop
            if (mincost == INF) break;

            // Mark the selected vertex as BLACK (included in the MST)
            color[u] = BLACK;

            // Update the distances and parents for the adjacent vertices
            for (v = 0; v < n; v++) {
                // If the vertex is not yet included in the MST and the edge weight is less than the current known distance
                if (color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1) {
                    pi[v] = u;    // Update the parent of vertex v
                    d[v] = G[u][v]; // Update the distance to vertex v
                }
            }
        }

        // Calculate the total weight of the minimum spanning tree
        for (i = 0; i < n; i++) {
            if (d[i] != INF) sum += d[i]; // Sum up the distances of included vertices
        }

        // Return the total weight of the minimum spanning tree
        return sum;
    }
}

// <END-OF-CODE>
