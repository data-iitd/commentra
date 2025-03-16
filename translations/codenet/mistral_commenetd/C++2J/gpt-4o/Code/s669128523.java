import java.util.Scanner;

public class DepthFirstSearch {
    static final int N = 100; // maximum number of vertices in the graph
    static final int WHITE = 0; // unvisited vertex
    static final int GRAY = 1; // vertex is being explored
    static final int BLACK = 2; // vertex has been explored

    static int[][] M = new int[N][N]; // adjacency matrix
    static int n; // number of vertices
    static int[] color = new int[N], d = new int[N], f = new int[N]; // arrays for depth first search
    static int tt; // time counter

    // depth first search visit function
    static void dfsVisit(int u) {
        color[u] = GRAY; // mark the current vertex as being explored
        d[u] = ++tt; // record the discovery time
        for (int v = 0; v < n; v++) {
            if (M[u][v] == 0)
                continue; // if there is no edge between u and v, skip
            if (color[v] == WHITE) {
                dfsVisit(v); // recursively call dfsVisit for the neighbor v
            }
        }
        color[u] = BLACK; // mark the current vertex as explored
        f[u] = ++tt; // record the finishing time
    }

    // depth first search function
    static void dfs() {
        for (int i = 0; i < n; i++) {
            color[i] = WHITE; // initialize all vertices as unvisited
        }
        tt = 0;

        for (int u = 0; u < n; u++) {
            if (color[u] == WHITE) {
                dfsVisit(u); // call dfsVisit for the first unvisited vertex
            }
        }

        // print the results
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k, u, v;
        n = scanner.nextInt(); // read the number of vertices

        // initialize the adjacency matrix with zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] = 0;
            }
        }

        // read the edges and fill the adjacency matrix
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt();
            k = scanner.nextInt();
            u--;
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt();
                v--;
                M[u][v] = 1;
            }
        }

        // perform depth first search
        dfs();

        scanner.close();
    }
}

// <END-OF-CODE>
