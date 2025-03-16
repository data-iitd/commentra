import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Step 2: Define global variables
    // G is a list of lists representing the graph.
    static List<Integer>[] G = new ArrayList[100000];
    // used is a boolean array to keep track of visited nodes.
    static boolean[] used = new boolean[100000];
    // grundy is an array to store the Grundy number of each node.
    static int[] grundy = new int[100000];

    // Step 3: Define the dfs function
    // The function dfs is used to perform a depth-first search on the graph.
    static void dfs(int v) {
        // It marks the current node as visited.
        used[v] = true;
        // It initializes the Grundy number of the current node to 0.
        grundy[v] = 0;
        // It iterates through all the neighbors of the current node.
        for (int i = 0; i < G[v].size(); i++) {
            // If a neighbor has not been visited, it recursively calls dfs on that neighbor.
            if (!used[G[v].get(i)]) {
                dfs(G[v].get(i));
                // It updates the Grundy number of the current node by performing the XOR operation with (grundy[G[v][i]] + 1).
                grundy[v] ^= (grundy[G[v].get(i)] + 1);
            }
        }
    }

    // Step 4: Main function
    public static void main(String[] args) {
        // Initialize the adjacency list
        for (int i = 0; i < 100000; i++) {
            G[i] = new ArrayList<>();
        }

        // It reads the number of nodes N.
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        // It reads the edges of the graph and constructs the adjacency list.
        for (int i = 0; i < N - 1; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;
            G[x].add(y);
            G[y].add(x);
        }
        // It calls the dfs function starting from node 0.
        dfs(0);
        // It checks the Grundy number of the root node (node 0).
        if (grundy[0] != 0) {
            // It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
            System.out.println("Alice");
        } else {
            System.out.println("Bob");
        }
        scanner.close();
    }
}
// <END-OF-CODE>
