
import java.io.*;
import java.util.*;

public class atcoder_AGC004_D{
    static int dfs(List<List<Integer>> links, int n, int k, int v, int p) {
        // Initialize height from the leaf node and cut count
        int heightFromLeaf = 0;
        int cutCount = 0;

        // Iterate through all connected nodes (children) of the current node
        for (int u : links.get(v)) {
            // Skip if the child node is 0 (indicating no further connections)
            if (u == 0) {
                continue;
            }

            // Recursively perform DFS on the child node and get its height and cut count
            int hgt = dfs(links, n, k, u, v);
            int cut = hgt;

            // Update the maximum height from the leaf node
            heightFromLeaf = Math.max(heightFromLeaf, hgt);

            // Accumulate the cut count from the child nodes
            cutCount += cut;
        }

        // Increment the height from the leaf node as we return to the parent
        heightFromLeaf += 1;

        // Check if the current height matches k and we are not at the root node
        if (p!= 0 && heightFromLeaf == k) {
            // Reset height from leaf to 0 and increment cut count
            heightFromLeaf = 0;
            cutCount += 1;
        }

        // Return the height from the leaf and the total cut count
        return heightFromLeaf;
    }

    public static void main(String[] args) throws Exception {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
             PrintWriter out = new PrintWriter(System.out)) {
            // Read input values for n (number of nodes), k (target height), and the rest of the connections
            String[] split = in.readLine().split(" ");
            int n = Integer.parseInt(split[0]);
            int k = Integer.parseInt(split[1]);
            int[] aaa = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                aaa[i] = Integer.parseInt(split[i + 2]) - 1;  // Adjust for 0-based indexing
            }

            // Create a list of lists to represent the graph (tree) connections
            List<List<Integer>> links = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                links.add(new ArrayList<>());
            }

            // Populate the links based on the input connections
            for (int i = 0; i < n - 1; i++) {
                links.get(aaa[i]).add(i);
            }

            // Perform DFS starting from the root node (0) and get the total cuts
            int ans = dfs(links, n, k, 0, 0);

            // If the first node is not the root, increment the answer
            if (aaa[0]!= 0) {
                ans += 1;
            }

            // Print the final answer (total cuts)
            out.println(ans);
        }
    }
}

Translate the above Java code to C++ and end with comment "