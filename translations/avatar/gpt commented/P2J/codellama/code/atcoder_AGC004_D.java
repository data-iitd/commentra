
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = br.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        int[] aaa = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            aaa[i] = Integer.parseInt(br.readLine());
        }

        // Set the maximum recursion limit to handle deep recursions
        int maxRecursionLimit = 1000000;
        Thread.currentThread().setStackTrace(new StackTraceElement[maxRecursionLimit]);

        // Create a list of sets to represent the graph (tree) connections
        List<Set<Integer>> links = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            links.add(new HashSet<>());
        }

        // Populate the links based on the input connections
        for (int i = 0; i < n - 1; i++) {
            links.get(aaa[i] - 1).add(i);
        }

        // Perform DFS starting from the root node (0) and get the total cuts
        int ans = dfs(links, n, k, 0, 0);

        // If the first node is not the root, increment the answer
        if (aaa[0] != 1) {
            ans += 1;
        }

        // Print the final answer (total cuts)
        System.out.println(ans);
    }

    public static int dfs(List<Set<Integer>> links, int n, int k, int v, int p) {
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
            cutCount += hgt;

            // Update the maximum height from the leaf node
            heightFromLeaf = Math.max(heightFromLeaf, hgt);
        }

        // Increment the height from the leaf node as we return to the parent
        heightFromLeaf += 1;

        // Check if the current height matches k and we are not at the root node
        if (p != 0 && heightFromLeaf == k) {
            // Reset height from leaf to 0 and increment cut count
            heightFromLeaf = 0;
            cutCount += 1;
        }

        // Return the height from the leaf and the total cut count
        return heightFromLeaf;
    }
}

