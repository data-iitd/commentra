import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Declare a graph represented as an adjacency list
    static List<Integer>[] G = new ArrayList[100000];
    // Array to track visited nodes during DFS
    static boolean[] used = new boolean[100000];
    // Array to store the Grundy values for each node
    static int[] grundy = new int[100000];

    // Depth-First Search (DFS) function to compute Grundy values
    static void dfs(int v) {
        // Mark the current node as visited
        used[v] = true;
        // Initialize the Grundy value for the current node
        grundy[v] = 0;

        // Iterate through all adjacent nodes
        for (int i = 0; i < G[v].size(); i++) {
            // If the adjacent node has not been visited
            if (!used[G[v].get(i)]) {
                // Recursively perform DFS on the adjacent node
                dfs(G[v].get(i));
                // Update the Grundy value using the Grundy value of the child node
                grundy[v] ^= (grundy[G[v].get(i)] + 1);
            }
        }
    }

    public static void main(String[] args) {
        // Initialize the adjacency list
        for (int i = 0; i < 100000; i++) {
            G[i] = new ArrayList<>();
        }

        // Read the number of nodes in the graph
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Read the edges of the graph
        for (int i = 0; i < N - 1; i++) {
            int x = scanner.nextInt() - 1; // Convert to zero-based indexing
            int y = scanner.nextInt() - 1; // Convert to zero-based indexing
            // Add the edge to the adjacency list
            G[x].add(y);
            G[y].add(x);
        }

        // Start DFS from the root node (node 0)
        dfs(0);

        // Determine the winner based on the Grundy value of the root node
        if (grundy[0] != 0) {
            System.out.println("Alice"); // Alice wins if Grundy value is non-zero
        } else {
            System.out.println("Bob");   // Bob wins if Grundy value is zero
        }

        scanner.close();
    }
}
// <END-OF-CODE>
