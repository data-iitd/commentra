import java.util.*;

class Edge {
    long s, g, c; // start vertex, end vertex, and cost of the edge

    Edge(long s, long g, long c) {
        this.s = s;
        this.g = g;
        this.c = c;
    }
}

class Graph {
    int vcnt, ecnt; // number of vertices and edges
    Edge[] e; // array to hold edges
    int[] id; // array to hold index of edges for each vertex

    Graph(int maxVertices, int maxEdges) {
        e = new Edge[maxEdges];
        id = new int[maxVertices];
    }
}

public class TreeDiameter {
    static Graph g; // Global graph variable
    static int[] tyokkeitemp; // Temporary array to store distances during DFS

    // Function to read the graph from input
    static void readGraph() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong(); // Read the number of vertices
        g = new Graph((int) n, (int) (2 * n - 2)); // Initialize graph

        for (int i = 0; i < n - 1; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            long c = scanner.nextLong();
            // Add edge from x to y
            g.e[2 * i] = new Edge(x, y, c);
            // Add edge from y to x (undirected graph)
            g.e[2 * i + 1] = new Edge(y, x, c);
        }
        g.vcnt = (int) n; // Set vertex count
        g.ecnt = 2 * (int) n - 2; // Set edge count (undirected edges)

        // Sort edges based on start and end vertices
        Arrays.sort(g.e, Comparator.comparingLong(e -> e.s).thenComparingLong(e -> e.g));

        int p = 0;
        // Create an index for edges for each vertex
        for (int i = 0; i < g.vcnt; i++) {
            while (p < g.ecnt && g.e[p].s < i) p++;
            g.id[i] = p; // Store the index of the first edge for vertex i
        }
        g.id[g.vcnt] = g.ecnt; // Sentinel value for the last vertex
    }

    // Recursive DFS function to explore the tree
    static void tyokkeiDFS(long s) {
        for (int i = g.id[(int) s]; i < g.id[(int) s + 1]; i++) {
            // If the vertex has not been visited
            if (tyokkeitemp[(int) g.e[i].g] == 0) {
                // Update the distance and continue DFS
                tyokkeitemp[(int) g.e[i].g] = tyokkeitemp[(int) s] + (int) g.e[i].c;
                tyokkeiDFS(g.e[i].g);
            }
        }
    }

    // Function to calculate the diameter of the tree
    static int tyokkei() {
        // Allocate memory for distance array
        tyokkeitemp = new int[g.vcnt + 10];
        tyokkeitemp[0] = 1; // Start DFS from vertex 0
        tyokkeiDFS(0); // First DFS to find the farthest vertex

        int M = 0, Mi = 0; // Variables to track maximum distance and corresponding vertex
        for (int i = 0; i < g.vcnt; i++) {
            // Find the vertex with the maximum distance
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }

        // Reset distances for the second DFS
        Arrays.fill(tyokkeitemp, 0);
        tyokkeitemp[Mi] = 1; // Start DFS from the farthest vertex found
        tyokkeiDFS(Mi); // Second DFS to find the diameter

        // Find the maximum distance from the second DFS
        for (int i = 0; i < g.vcnt; i++) {
            M = Math.max(M, tyokkeitemp[i]);
        }
        return M - 1; // Return the diameter (subtract 1 for edge count)
    }

    public static void main(String[] args) {
        readGraph(); // Read the graph input
        System.out.println(tyokkei()); // Calculate and print the diameter of the tree
    }
}

// <END-OF-CODE>
