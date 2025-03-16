import java.util.Scanner;

class Graph {
    private int n;
    private int[][] A;
    private int[] color;
    private int[] d;
    private int[] f;
    private int TT;

    public Graph(int n) {
        this.n = n;
        A = new int[n][n];
        color = new int[n];
        d = new int[n];
        f = new int[n];
    }

    public void readAdjacencyMatrix() {
        Scanner scanner = new Scanner(System.in);
        int k, v;

        // Initialize the 2D array A with zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }

        // Read the adjacency matrix from the user
        for (int i = 0; i < n; i++) {
            System.out.print("Enter the number of neighbors for node " + (i + 1) + ": ");
            k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                System.out.print("Enter the neighbor index: ");
                v = scanner.nextInt();
                A[i][v - 1] = 1; // Store the edge weight (assumed to be 1) in the adjacency matrix
            }
        }
    }

    public void dfs() {
        // Initialize all nodes with color SHIRO (white)
        for (int i = 0; i < n; i++) {
            color[i] = 0; // SHIRO
        }

        TT = 0; // Initialize the time variable TT to 0

        // Perform Depth First Search (DFS) from each unvisited node
        for (int u = 0; u < n; u++) {
            if (color[u] == 0) {
                dfsVisit(u);
            }
        }

        // Print the results
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
            System.out.println("Node " + (i + 1) + " is visited at time " + d[i] + " and its finishing time is " + f[i] + ".");
        }
    }

    private void dfsVisit(int k) {
        color[k] = 1; // HAI (gray)
        TT++; // Increment the time variable TT
        d[k] = TT; // Set the discovery time for the current node

        // Explore all neighbors of the current node
        for (int v = 0; v < n; v++) {
            if (A[k][v] == 1 && color[v] == 0) { // If the neighbor is unvisited
                dfsVisit(v); // Recursively call the function dfsVisit() for the neighbor
            }
        }

        // Mark the current node as finished (KURO)
        color[k] = 2;
        f[k] = ++TT; // Set the finishing time for the current node
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = scanner.nextInt();

        Graph graph = new Graph(n);
        graph.readAdjacencyMatrix();
        graph.dfs();
    }
}
