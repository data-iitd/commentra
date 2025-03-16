/* Depth First Search (DFS) implementation
   This implementation does not use recursion stack.
*/

import java.util.Scanner;

// Define constants for maximum number of nodes and colors
static final int N = 100; // Maximum number of nodes
static final int WHITE = 0; // Color for unvisited nodes
static final int GRAY = 1; // Color for nodes being visited
static final int BLACK = 2; // Color for fully visited nodes

// Adjacency matrix to represent the graph, number of nodes, and arrays for DFS
int M[][] = new int[N][N]; // M is the adjacency matrix, n is the number of nodes
int n; // Number of nodes
int color[] = new int[N]; // Array to store colors
int d[] = new int[N]; // Array to store discovery times
int f[] = new int[N]; // Array to store finish times
int tt; // Time counter

// Function to visit nodes in DFS
void dfs_visit(int u) {
    int v;
    // Mark the current node as being visited
    color[u] = GRAY;
    // Set the discovery time for the current node
    d[u] = ++tt;

    // Explore all adjacent nodes
    for (v = 0; v < n; v++) {
        // Skip if there is no edge from u to v
        if (M[u][v] == 0)
            continue;
        // If the adjacent node is unvisited, recursively visit it
        if (color[v] == WHITE) {
            dfs_visit(v);
        }
    }
    // Mark the current node as fully visited
    color[u] = BLACK;
    // Set the finish time for the current node
    f[u] = ++tt;
}

// Function to perform DFS on the graph
void dfs() {
    int u;
    // Initialize all nodes as unvisited
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
    }
    tt = 0; // Reset the time counter

    // Perform DFS for each unvisited node
    for (u = 0; u < n; u++) {
        if (color[u] == WHITE)
            dfs_visit(u);
    }

    // Output the discovery and finish times for each node
    for (int i = 0; i < n; i++)
        System.out.println(i + 1 + " " + d[i] + " " + f[i]);
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k, u, v;
        // Read the number of nodes
        n = sc.nextInt();
        // Initialize the adjacency matrix to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
        }
        // Read the graph edges
        for (int i = 0; i < n; i++) {
            u = sc.nextInt(); // Read the node
            k = sc.nextInt(); // Read the number of edges
            for (int j = 0; j < k; j++) {
                v = sc.nextInt(); // Read each adjacent node
                M[u - 1][v - 1] = 1; // Mark the edge in the adjacency matrix
            }
        }

        // Perform DFS on the graph
        dfs();

        sc.close();
    }
}

