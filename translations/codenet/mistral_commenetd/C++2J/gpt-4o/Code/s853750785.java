import java.util.*;

public class AtCoder {
    static final long MOD = 1000000007; // Modulus constant for modular arithmetic
    static int N, M;
    static int[] H;
    static List<Integer>[] G;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt(); // Read the number of nodes
        M = scanner.nextInt(); // Read the number of edges
        H = new int[N];
        G = new ArrayList[N];

        for (int i = 0; i < N; i++) {
            H[i] = scanner.nextInt(); // Read the heights of the nodes
            G[i] = new ArrayList<>(); // Initialize adjacency list
        }

        for (int i = 0; i < M; i++) { // Iterate through each edge
            int u = scanner.nextInt() - 1; // Read the endpoint of the edge (0-indexed)
            int v = scanner.nextInt() - 1; // Read the endpoint of the edge (0-indexed)
            G[u].add(v); // Add an edge from node u to node v
            G[v].add(u); // Add a reciprocal edge from node v to node u
        }

        long ans = 0; // Initialize answer variable
        for (int u = 0; u < N; u++) { // Iterate through each node
            boolean flag = true; // Assume that the node has a higher height than its neighbors
            for (int v : G[u]) {
                if (H[u] <= H[v]) flag = false; // If not, update the flag
            }
            if (flag) ans++; // If the node has a higher height than its neighbors, increment the answer
        }
        System.out.println(ans); // Print the answer
    }
}
// <END-OF-CODE>
