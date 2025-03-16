import java.util.*;

public class Main {
    // Structure to hold edge information
    static class Edge {
        int s, g, c; // start vertex, end vertex, and cost of the edge
    }

    // Structure to represent the graph
    static class Graph {
        int vcnt, ecnt; // number of vertices and edges
        Edge e[];    // array to hold edges
        int id[]; // array to hold index of edges for each vertex
    }

    static Graph g; // Global graph variable

    // Function to read the graph from input
    static void readgraph() {
        int n;
        // Read the number of vertices
        n = Integer.parseInt(System.console().readLine());
        // Read edges and construct the graph
        g = new Graph();
        g.e = new Edge[2 * n - 2];
        g.id = new int[n + 1];
        rep(i, 0, 2 * n - 2) {
            g.e[i] = new Edge();
            // Read edge information
            g.e[i].s = Integer.parseInt(System.console().readLine());
            g.e[i].g = Integer.parseInt(System.console().readLine());
            g.e[i].c = Integer.parseInt(System.console().readLine());
        }
        g.vcnt = n; // Set vertex count
        g.ecnt = 2 * n - 2; // Set edge count (undirected edges)
        // Sort edges based on start and end vertices
        Arrays.sort(g.e, new Comparator<Edge>() {
            public int compare(Edge a, Edge b) {
                if (a.s < b.s) return -1;
                if (a.s > b.s) return 1;
                if (a.g < b.g) return -1;
                return 1;
            }
        });

        int p = 0;
        // Create an index for edges for each vertex
        rep(i, 0, g.vcnt) {
            while (p < g.ecnt && g.e[p].s < i) p++;
            g.id[i] = p; // Store the index of the first edge for vertex i
        }
        g.id[g.vcnt] = g.ecnt; // Sentinel value for the last vertex
    }

    // Function to perform DFS and find the diameter of the tree
    static int[] tyokkeitemp; // Temporary array to store distances during DFS

    // Recursive DFS function to explore the tree
    static void tyokkeidfs(int s) {
        for (int i = g.id[s]; i < g.id[s + 1]; i++) {
            // If the vertex has not been visited
            if (tyokkeitemp[g.e[i].g] == 0) {
                // Update the distance and continue DFS
                tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
                tyokkeidfs(g.e[i].g);
            }
        }
    }

    // Function to calculate the diameter of the tree
    static int tyokkei() {
        // Allocate memory for distance array
        tyokkeitemp = new int[g.vcnt + 10];
        tyokkeitemp[0] = 1; // Start DFS from vertex 0
        tyokkeidfs(0); // First DFS to find the farthest vertex

        int M = 0, Mi; // Variables to track maximum distance and corresponding vertex
        rep(i, 0, g.vcnt) {
            // Find the vertex with the maximum distance
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }
        
        // Reset distances for the second DFS
        rep(i, 0, g.vcnt) tyokkeitemp[i] = 0;
        tyokkeitemp[Mi] = 1; // Start DFS from the farthest vertex found
        tyokkeidfs(Mi); // Second DFS to find the diameter

        // Find the maximum distance from the second DFS
        rep(i, 0, g.vcnt) M = Math.max(M, tyokkeitemp[i]);
        return M - 1; // Return the diameter (subtract 1 for edge count)
    }

    public static void main(String[] args) {
        readgraph(); // Read the graph input
        System.out.println(tyokkei()); // Calculate and print the diameter of the tree
    }
}

