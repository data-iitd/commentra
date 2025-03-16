
import java.util.*;
import java.io.*;

public class atcoder_ABC148_F{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int ta = Integer.parseInt(input[1]) - 1;  // Adjusting to zero-based index
        int ao = Integer.parseInt(input[2]) - 1;  // Adjusting to zero-based index

        // Initialize the graph as an adjacency list
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        // Read the edges of the graph and populate the adjacency list
        for (int i = 0; i < n - 1; i++) {
            input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]) - 1;  // Adjusting to zero-based index
            int b = Integer.parseInt(input[1]) - 1;  // Adjusting to zero-based index
            g.get(a).add(b);
            g.get(b).add(a);
        }

        // Initialize distance arrays for ta and ao
        int[] ta_dist = new int[n];
        Arrays.fill(ta_dist, -1);  // Initialize all distances to -1
        ta_dist[ta] = 0;  // Distance to itself is 0

        int[] ao_dist = new int[n];
        Arrays.fill(ao_dist, -1);  // Initialize all distances to -1
        ao_dist[ao] = 0;  // Distance to itself is 0

        // Depth-first search (DFS) function to calculate distances from ta
        void dfs1(int node) {
            for (int v : g.get(node)) {
                if (ta_dist[v]!= -1) {
                    continue;  // Skip if already visited
                }
                ta_dist[v] = ta_dist[node] + 1;  // Update distance
                dfs1(v);  // Recursive DFS call
            }
        }

        // Depth-first search (DFS) function to calculate distances from ao
        void dfs2(int node) {
            for (int v : g.get(node)) {
                if (ao_dist[v]!= -1) {
                    continue;  // Skip if already visited
                }
                ao_dist[v] = ao_dist[node] + 1;  // Update distance
                dfs2(v);  // Recursive DFS call
            }
        }

        // Perform DFS from ao to calculate distances
        dfs2(ao);

        // Perform DFS from ta to calculate distances
        dfs1(ta);

        // Initialize result variable to track the maximum distance
        int res = 0;

        // Calculate the maximum distance where ta's distance is less than or equal to ao's distance
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] > ao_dist[i]) {
                continue;  // Skip if ta is further away than ao
            }
            res = Math.max(res, ao_dist[i]);  // Update result with the maximum distance
        }

        // Print the result, subtracting 1 to adjust for zero-based indexing
        System.out.println(res - 1);
    }
}

Translate the above Java code to C++ and end with comment "