import java.util.*;

public class Main {
    static int mod = 1000000007;
    static int INF = Integer.MAX_VALUE;
    static List<List<Integer>> g;
    static int[] ta_dist, ao_dist;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes and the starting points for ta and ao
        int n = scanner.nextInt();
        int ta = scanner.nextInt() - 1; // Adjusting to zero-based index
        int ao = scanner.nextInt() - 1; // Adjusting to zero-based index

        // Initialize the graph as an adjacency list
        g = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        // Read the edges of the graph and populate the adjacency list
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt() - 1; // Adjusting to zero-based index
            int b = scanner.nextInt() - 1; // Adjusting to zero-based index
            g.get(a).add(b);
            g.get(b).add(a);
        }

        // Initialize distance arrays for ta and ao
        ta_dist = new int[n];
        Arrays.fill(ta_dist, -1); // Use -1 to indicate unvisited
        ta_dist[ta] = 0; // Distance to itself is 0

        ao_dist = new int[n];
        Arrays.fill(ao_dist, -1); // Use -1 to indicate unvisited
        ao_dist[ao] = 0; // Distance to itself is 0

        // Perform DFS from ao to calculate distances
        ao_dfs(ao);
        // Perform DFS from ta to calculate distances
        ta_dfs(ta);

        // Initialize result variable to track the maximum distance
        int res = 0;

        // Calculate the maximum distance where ta's distance is less than or equal to ao's distance
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] > ao_dist[i]) {
                continue; // Skip if ta is further away than ao
            }
            res = Math.max(res, ao_dist[i]); // Update result with the maximum distance
        }

        // Print the result, subtracting 1 to adjust for zero-based indexing
        System.out.println(res - 1);
    }

    // Depth-first search (DFS) function to calculate distances from ta
    static void ta_dfs(int node) {
        for (int v : g.get(node)) {
            if (ta_dist[v] != -1) {
                continue; // Skip if already visited
            }
            ta_dist[v] = ta_dist[node] + 1; // Update distance
            ta_dfs(v); // Recursive DFS call
        }
    }

    // Depth-first search (DFS) function to calculate distances from ao
    static void ao_dfs(int node) {
        for (int v : g.get(node)) {
            if (ao_dist[v] != -1) {
                continue; // Skip if already visited
            }
            ao_dist[v] = ao_dist[node] + 1; // Update distance
            ao_dfs(v); // Recursive DFS call
        }
    }
}
// <END-OF-CODE>
