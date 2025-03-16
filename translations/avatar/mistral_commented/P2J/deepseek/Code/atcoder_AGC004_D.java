import java.util.*;

public class Main {
    // Set the recursion limit for the function call stack to 1 million
    static {
        System.setProperty("java.lang.Integer.IntegerCache.high", "1000000");
    }

    // Define the depth-first search function 'dfs'
    public static int[] dfs(List<Set<Integer>> links, int n, int k, int v, int p) {
        // Initialize variables for height from leaf node and cut count
        int heightFromLeaf = 0;
        int cutCount = 0;

        // Iterate through neighbors of the current node 'v'
        for (int u : links.get(v)) {
            // Skip if the neighbor is not a valid node (0)
            if (u == 0) {
                continue;
            }

            // Recursively call the 'dfs' function for the neighbor 'u'
            int[] result = dfs(links, n, k, u, v);
            int hgt = result[0];
            int cut = result[1];

            // Update the height from leaf and cut count
            heightFromLeaf = Math.max(heightFromLeaf, hgt);
            cutCount += cut;
        }

        // Update the height from leaf and cut count for the current node 'v'
        heightFromLeaf += 1;

        // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
        // then this node is a cut vertex and we need to add 1 to the cut count
        if (p != 0 && heightFromLeaf == k) {
            heightFromLeaf = 0;
            cutCount += 1;
        }

        // Return the height from leaf and cut count for the current node 'v'
        return new int[]{heightFromLeaf, cutCount};
    }

    public static void main(String[] args) {
        // Read input from standard input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] aaa = new int[n];
        for (int i = 0; i < n; i++) {
            aaa[i] = scanner.nextInt();
        }

        // Initialize the 'links' list with sets for each node
        List<Set<Integer>> links = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            links.add(new HashSet<>());
        }

        // Process the input edges and add them to the 'links' list
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            a -= 1;
            links.get(a).add(i);
        }

        // Call the 'dfs' function with the initial parameters
        int[] result = dfs(links, n, k, 0, 0);
        int ans = result[1];

        // If the first node is not a root node, add 1 to the answer
        if (aaa[0] != 1) {
            ans += 1;
        }

        // Print the final answer
        System.out.println(ans);
    }
}
