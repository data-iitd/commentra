import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input values for n (number of nodes), k (target height), and the rest of the connections
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] aaa = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            aaa[i] = sc.nextInt() - 1;
        }
        
        // Create a list of sets to represent the graph (tree) connections
        List<Set<Integer>> links = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            links.add(new HashSet<>());
        }
        
        // Populate the links based on the input connections
        for (int i = 0; i < n - 1; i++) {
            links.get(aaa[i]).add(i);
        }
        
        // Perform DFS starting from the root node (0) and get the total cuts
        int ans = dfs(links, n, k, 0, 0);
        
        // If the first node is not the root, increment the answer
        if (aaa[0]!= 0) {
            ans++;
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
            int hgt, cut = dfs(links, n, k, u, v);
            
            // Update the maximum height from the leaf node
            heightFromLeaf = Math.max(heightFromLeaf, hgt);
            
            // Accumulate the cut count from the child nodes
            cutCount += cut;
        }
        
        // Increment the height from the leaf node as we return to the parent
        heightFromLeaf++;
        
        // Check if the current height matches k and we are not at the root node
        if (p!= 0 && heightFromLeaf == k) {
            // Reset height from leaf to 0 and increment cut count
            heightFromLeaf = 0;
            cutCount++;
        }
        
        // Return the height from the leaf and the total cut count
        return heightFromLeaf;
    }
}

