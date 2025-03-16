import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of n (number of nodes) and m (number of edges) from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Create a list of nodes from 1 to n
        List<Integer> p = new ArrayList<>();
        for (int x = 1; x <= n; x++) {
            p.add(x);
        }
        
        // Read the health points for each node from input
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
        }
        
        // Create a map to store health points for each node
        Map<Integer, Integer> hp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            hp.put(p.get(i), h[i]);
        }
        
        // Initialize a map to represent the graph as an adjacency list
        Map<Integer, List<Integer>> path = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            path.put(i, new ArrayList<>());
        }
        
        // Read m edges from input and populate the adjacency list
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            path.get(a).add(b);  // Add edge from a to b
            path.get(b).add(a);  // Add edge from b to a (undirected graph)
        }
        
        // Initialize a counter for nodes that have no neighbors with equal or higher health points
        int c = 0;
        
        // Iterate through each node and its connected nodes
        for (Map.Entry<Integer, List<Integer>> entry : path.entrySet()) {
            int i = entry.getKey();
            List<Integer> v = entry.getValue();
            boolean hasHigherOrEqual = false;  // Flag to check if any neighbor has equal or higher health points
            
            for (int j : v) {
                // Check if the current node's health is less than or equal to any of its neighbors
                if (hp.get(i) <= hp.get(j)) {
                    hasHigherOrEqual = true;  // Set flag if a neighbor with equal or higher health is found
                    break;  // No need to check further neighbors
                }
            }
            // If no neighbors have equal or higher health points, increment the counter
            if (!hasHigherOrEqual) {
                c++;
            }
        }
        
        // Print the count of nodes that have no neighbors with equal or higher health points
        System.out.println(c);
        
        scanner.close();
    }
}
// <END-OF-CODE>
