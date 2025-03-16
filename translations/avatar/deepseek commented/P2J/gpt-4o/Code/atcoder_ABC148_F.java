import java.util.*;

public class Main {
    static List<List<Integer>> g;
    static int[] ta_dist, ao_dist;

    // Function to read an integer from standard input
    static int inp(Scanner scanner) {
        return scanner.nextInt();
    }

    // Function to read a list of integers from standard input
    static List<Integer> inpl(Scanner scanner) {
        List<Integer> list = new ArrayList<>();
        while (scanner.hasNextInt()) {
            list.add(scanner.nextInt());
        }
        return list;
    }

    // Depth-First Search (DFS) function to compute distances from Ta
    static void ta_dfs(int node) {
        for (int v : g.get(node)) {
            if (ta_dist[v] != -1) { // If already visited, skip
                continue;
            }
            ta_dist[v] = ta_dist[node] + 1; // Update distance
            ta_dfs(v); // Recursively visit neighbors
        }
    }

    // Depth-First Search (DFS) function to compute distances from Ao
    static void ao_dfs(int node) {
        for (int v : g.get(node)) {
            if (ao_dist[v] != -1) { // If already visited, skip
                continue;
            }
            ao_dist[v] = ao_dist[node] + 1; // Update distance
            ao_dfs(v); // Recursively visit neighbors
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes, starting node for Ta, and starting node for Ao
        int n = inp(scanner);
        int ta = inp(scanner) - 1; // Adjust to zero-based index
        int ao = inp(scanner) - 1; // Adjust to zero-based index

        // Initialize the graph as a list of lists, each representing adjacency list of a node
        g = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        // Read edges to construct the graph
        for (int i = 0; i < n - 1; i++) {
            int a = inp(scanner) - 1; // Adjust to zero-based index
            int b = inp(scanner) - 1; // Adjust to zero-based index
            g.get(a).add(b); // Append the zero-based index of the neighbor
            g.get(b).add(a); // Append the zero-based index of the neighbor
        }

        // Initialize distance arrays to -1, will be populated during DFS
        ta_dist = new int[n];
        Arrays.fill(ta_dist, -1);
        ta_dist[ta] = 0; // Distance from Ta to Ta is 0

        ao_dist = new int[n];
        Arrays.fill(ao_dist, -1);
        ao_dist[ao] = 0; // Distance from Ao to Ao is 0

        // Start DFS from Ao to compute distances
        ao_dfs(ao);

        // Start DFS from Ta to compute distances
        ta_dfs(ta);

        // Initialize result variable
        int res = 0;

        // Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] > ao_dist[i]) { // Skip if Ta's distance is greater
                continue;
            }
            res = Math.max(res, ao_dist[i]); // Update result with the maximum distance
        }

        // Print the result, which is the maximum distance minus one
        System.out.println(res - 1);
    }
}
// <END-OF-CODE>
