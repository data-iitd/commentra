import java.util.*;

public class Main {
    static int n, k;
    static List<List<Integer>> links;
    static int[] aaa;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        aaa = new int[n];
        for (int i = 0; i < n; i++) {
            aaa[i] = scanner.nextInt();
        }

        // Create a list of lists to represent the graph (tree) connections
        links = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            links.add(new ArrayList<>());
        }

        // Populate the links based on the input connections
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a != 0) {
                links.get(a - 1).add(i);
            }
        }

        // Perform DFS starting from the root node (0) and get the total cuts
        int[] result = dfs(0, -1);
        int ans = result[1];

        // If the first node is not the root, increment the answer
        if (aaa[0] != 1) {
            ans++;
        }

        // Print the final answer (total cuts)
        System.out.println(ans);
    }

    static int[] dfs(int v, int p) {
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
            int[] result = dfs(u, v);
            int hgt = result[0];
            int cut = result[1];

            // Update the maximum height from the leaf node
            heightFromLeaf = Math.max(heightFromLeaf, hgt);

            // Accumulate the cut count from the child nodes
            cutCount += cut;
        }

        // Increment the height from the leaf node as we return to the parent
        heightFromLeaf++;

        // Check if the current height matches k and we are not at the root node
        if (p != -1 && heightFromLeaf == k) {
            // Reset height from leaf to 0 and increment cut count
            heightFromLeaf = 0;
            cutCount++;
        }

        // Return the height from the leaf and the total cut count
        return new int[]{heightFromLeaf, cutCount};
    }
}
