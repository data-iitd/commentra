import java.util.Scanner;

public class PrimAlgorithm {
    static final int MAX = 100;
    static final int INF = 999999;
    static final int NIL = -1;
    static final int WHITE = 0;
    static final int BLACK = 2;

    static int n; // Number of vertices
    static int[][] G = new int[MAX][MAX]; // Adjacency matrix

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt(); // Read the number of vertices from the user
        for (int i = 0; i < n; i++) { // Initialize the 2D array G with input values
            for (int j = 0; j < n; j++) {
                G[i][j] = scanner.nextInt();
            }
        }

        System.out.println(prim()); // Call the prim function and print the result
        scanner.close();
    }

    static int prim() { // Function to implement Prim's Algorithm
        int u, mincost, sum = 0;
        int[] d = new int[n];
        int[] pi = new int[n];
        int[] color = new int[n];

        for (u = 0; u < n; u++) { // Initialize the arrays d, pi, and color with initial values
            d[u] = INF;
            pi[u] = NIL;
            color[u] = WHITE;
        }

        d[0] = 0; // Set the initial distance of the first vertex to 0

        while (true) { // The main loop of Prim's Algorithm
            mincost = INF; // Initialize mincost to the maximum possible value
            for (int i = 0; i < n; i++) { // Find the unvisited vertex with the minimum distance
                if (color[i] != BLACK && d[i] < mincost) {
                    mincost = d[i];
                    u = i;
                }
            }

            if (mincost == INF) break; // If all vertices have been visited, break the loop

            color[u] = BLACK; // Mark the current vertex as visited

            for (int v = 0; v < n; v++) { // Update the distances of adjacent vertices
                if (color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1) {
                    pi[v] = u;
                    d[v] = G[u][v];
                }
            }
        }

        for (int i = 0; i < n; i++) { // Calculate and print the total weight of the MST
            if (d[i] != INF) sum += d[i];
        }

        return sum;
    }
}

// <END-OF-CODE>
