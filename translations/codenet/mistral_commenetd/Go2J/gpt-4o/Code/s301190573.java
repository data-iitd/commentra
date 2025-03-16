import java.util.*;

public class Main {
    static final int SIZE = 1000000;
    static int[] par, rank;

    // Function to initialize arrays
    static void initialize(int n) {
        par = new int[n];
        rank = new int[n];
        // Set all elements as their own parent initially
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    // Function to find the root of a node
    static int root(int i) {
        // If the node is its own parent, return it
        if (par[i] == i) {
            return i;
        }
        // Recursively find the root of the parent
        par[i] = root(par[i]);
        // Return the new root
        return par[i];
    }

    // Function to check if two nodes have the same parent
    static boolean same(int i, int j) {
        // Find the root of both nodes
        return root(i) == root(j);
    }

    // Function to unite two nodes
    static void unite(int i, int j) {
        // Find the roots of both nodes
        i = root(i);
        j = root(j);
        // If they already have the same parent, return
        if (i == j) {
            return;
        }
        // Make the smaller rank node a child of the larger rank node
        if (rank[i] < rank[j]) {
            par[i] = j;
        } else {
            par[j] = i;
            // If they have the same rank, increase the rank of the node with the smaller index
            if (rank[i] == rank[j]) {
                rank[i]++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read number of nodes and edges
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        // Read array of edges
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt() - 1; // Decrease each index by 1
        }
        // Initialize arrays
        initialize(n);
        // Process each edge by uniting their parents
        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt() - 1; // Decrease index by 1
            int y = scanner.nextInt() - 1; // Decrease index by 1
            unite(x, y);
        }
        // Count the number of disconnected components
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (same(i, p[i])) {
                s++;
            }
        }
        // Print the result
        System.out.println(s);
        scanner.close();
    }
}

// <END-OF-CODE>
