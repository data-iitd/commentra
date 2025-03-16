import java.util.*;

public class Main {
    static int n, ta, ao;
    static List<List<Integer>> g = new ArrayList<>();
    static int[] taDist;
    static int[] aoDist;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        ta = scanner.nextInt();
        ao = scanner.nextInt();
        ta -= 1;  // Adjusting to zero-based index
        ao -= 1;  // Adjusting to zero-based index

        // Initialize the graph as an adjacency list
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        // Read the edges of the graph and populate the adjacency list
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt() - 1;  // Adjusting to zero-based index
            int b = scanner.nextInt() - 1;  // Adjusting to zero-based index
            g.get(a).add(b);
            g.get(b).add(a);
        }

        // Initialize distance arrays for ta and ao
        taDist = new int[n];
        Arrays.fill(taDist, -1);
        taDist[ta] = 0;  // Distance to itself is 0
        aoDist = new int[n];
        Arrays.fill(aoDist, -1);
        aoDist[ao] = 0;  // Distance to itself is 0

        // Depth-first search (DFS) function to calculate distances from ta
        taDFS(ta);

        // Depth-first search (DFS) function to calculate distances from ao
        aoDFS(ao);

        // Initialize result variable to track the maximum distance
        int res = 0;

        // Calculate the maximum distance where ta's distance is less than or equal to ao's distance
        for (int i = 0; i < n; i++) {
            if (taDist[i] > aoDist[i]) {
                continue;  // Skip if ta is further away than ao
            }
            res = Math.max(res, aoDist[i]);  // Update result with the maximum distance
        }

        // Print the result, subtracting 1 to adjust for zero-based indexing
        System.out.println(res - 1);
    }

    // Depth-first search (DFS) function to calculate distances from ta
    private static void taDFS(int node) {
        for (int v : g.get(node)) {
            if (taDist[v] != -1) {
                continue;  // Skip if already visited
            }
            taDist[v] = taDist[node] + 1;  // Update distance
            taDFS(v);  // Recursive DFS call
        }
    }

    // Depth-first search (DFS) function to calculate distances from ao
    private static void aoDFS(int node) {
        for (int v : g.get(node)) {
            if (aoDist[v] != -1) {
                continue;  // Skip if already visited
            }
            aoDist[v] = aoDist[node] + 1;  // Update distance
            aoDFS(v);  // Recursive DFS call
        }
    }
}
