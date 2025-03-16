import java.util.*;

public class AtCoder {
    // Define constants
    static final long MOD = 1000000007;
    static final int MAX_N = 100005;

    // Define variables
    static int N, M;
    static int[] H = new int[MAX_N]; // Array to hold heights
    static List<Integer>[] G = new ArrayList[MAX_N]; // Adjacency list for the graph

    // Function to read input
    static void readInput() {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();

        for (int i = 0; i < N; i++) {
            H[i] = scanner.nextInt();
            G[i] = new ArrayList<>(); // Initialize adjacency list
        }

        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt() - 1; // Convert to 0-based indexing
            int v = scanner.nextInt() - 1; // Convert to 0-based indexing
            G[u].add(v);
            G[v].add(u);
        }
        scanner.close();
    }

    // Main function
    public static void main(String[] args) {
        readInput();

        long ans = 0; // Variable to count the number of nodes that are taller than all their neighbors

        // Iterate through each node to check if it is taller than all its neighbors
        for (int u = 0; u < N; u++) {
            boolean flag = true; // Flag to check if the current node is taller
            for (int v : G[u]) {
                if (H[u] <= H[v]) {
                    flag = false; // If any neighbor is taller or equal, set flag to false
                    break; // No need to check further neighbors
                }
            }
            if (flag) ans++; // If the flag is still true, increment the answer
        }

        // Output the result
        System.out.println(ans);
    }
}

// <END-OF-CODE>
