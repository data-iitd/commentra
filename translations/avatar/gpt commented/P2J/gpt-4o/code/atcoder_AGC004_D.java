import java.util.*;

public class Main {
    static int maxRecursionLimit = 1000000;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for n (number of nodes), k (target height), and the rest of the connections
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        List<Integer> aaa = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            aaa.add(scanner.nextInt() - 1); // Adjust for 0-based indexing
        }
        
        // Create a list of sets to represent the graph (tree) connections
        List<Set<Integer>> links = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            links.add(new HashSet<>());
        }
        
        // Populate the links based on the input connections
        for (int i = 0; i < aaa.size(); i++) {
            links.get(aaa.get(i)).add(i + 1); // i + 1 because children are 1-based
        }
        
        // Perform DFS starting from the root node (0) and get the total cuts
        int[] result = dfs(links, n, k, 0, -1);
        int ans = result[1];
        
        // If the first node is not the root, increment the answer
        if (aaa.get(0) != 0) {
            ans += 1;
        }
        
        // Print the final answer (total cuts)
        System.out.println(ans);
    }
    
    private static int[] dfs(List<Set<Integer>> links, int n, int k, int v, int p) {
        // Initialize height from the leaf node and cut count
        int heightFromLeaf = 0;
        int cutCount = 0;
        
        // Iterate through all connected nodes (children) of the current node
        for (int u : links.get(v)) {
            // Recursively perform DFS on the child node and get its height and cut count
            int[] childResult = dfs(links, n, k, u, v);
            int hgt = childResult[0];
            int cut = childResult[1];
            
            // Update the maximum height from the leaf node
            heightFromLeaf = Math.max(heightFromLeaf, hgt);
            
            // Accumulate the cut count from the child nodes
            cutCount += cut;
        }
        
        // Increment the height from the leaf node as we return to the parent
        heightFromLeaf += 1;
        
        // Check if the current height matches k and we are not at the root node
        if (p != -1 && heightFromLeaf == k) {
            // Reset height from leaf to 0 and increment cut count
            heightFromLeaf = 0;
            cutCount += 1;
        }
        
        // Return the height from the leaf and the total cut count
        return new int[]{heightFromLeaf, cutCount};
    }
}

// <END-OF-CODE>
