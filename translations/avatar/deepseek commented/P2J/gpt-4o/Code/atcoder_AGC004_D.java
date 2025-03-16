import java.util.*;

public class Main {
    static int recursionLimit = 1000000; // Step 1: Set the recursion limit to prevent overflow
    static int[] aaa;
    static Set<Integer>[] links;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        aaa = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            aaa[i] = scanner.nextInt();
        }
        
        links = new HashSet[n];
        for (int i = 0; i < n; i++) {
            links[i] = new HashSet<>();
        }
        
        for (int i = 0; i < n - 1; i++) { // Step 7: Build the tree
            int a = aaa[i] - 1;
            links[a].add(i + 1);
        }
        
        int[] result = dfs(links, n, k, 0, -1); // Step 8: Perform DFS starting from the root
        int ans = result[1];
        if (aaa[0] != 1) { // Step 9: Adjust the answer if necessary
            ans += 1;
        }
        System.out.println(ans); // Step 10: Output the final result
    }

    public static int[] dfs(Set<Integer>[] links, int n, int k, int v, int p) { // Step 2: Define the DFS function
        int heightFromLeaf = 0; // Initialize the height from the leaf node
        int cutCount = 0; // Initialize the count of cuts
        
        for (int u : links[v]) { // Step 3: Traverse the tree
            if (u == 0) { // Skip if the node is the root (0)
                continue;
            }
            int[] hgtCut = dfs(links, n, k, u, v); // Recursively call DFS
            heightFromLeaf = Math.max(heightFromLeaf, hgtCut[0]); // Update the height from the leaf
            cutCount += hgtCut[1]; // Count the number of cuts
        }
        
        heightFromLeaf += 1; // Increment the height from the leaf node
        
        if (p != -1 && heightFromLeaf == k) { // Step 4: Check if a cut is needed
            heightFromLeaf = 0; // Reset the height
            cutCount += 1; // Increment the cut count
        }
        
        return new int[]{heightFromLeaf, cutCount}; // Step 5: Return the height and cut count
    }
}
