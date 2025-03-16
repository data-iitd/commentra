
import java.util.*;

public class atcoder_ABC166_C{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();  // Number of nodes
        int m = sc.nextInt();  // Number of edges

        // Create a list of nodes from 1 to n
        List<Integer> p = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            p.add(i);
        }

        // Read the health points for each node from input
        Map<Integer, Integer> hp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int h = sc.nextInt();
            hp.put(p.get(i), h);
        }

        // Create a dictionary to represent the graph as an adjacency list
        // Each node will map to a list of its connected nodes (edges)
        Map<Integer, List<Integer>> path = new HashMap<>();
        for (int i = 0; i < n; i++) {
            path.put(p.get(i), new ArrayList<>());
        }

        // Read m edges from input and populate the adjacency list
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            path.get(a).add(b);  // Add edge from a to b
            path.get(b).add(a);  // Add edge from b to a (undirected graph)
        }

        // Initialize a counter for nodes that have no neighbors with equal or higher health points
        int c = 0;

        // Iterate through each node and its connected nodes
        for (int i : path.keySet()) {
            boolean f = false;  // Flag to check if any neighbor has equal or higher health points
            for (int j : path.get(i)) {
                // Check if the current node's health is less than or equal to any of its neighbors
                if (hp.get(i) <= hp.get(j)) {
                    f = true;  // Set flag if a neighbor with equal or higher health is found
                    break;  // No need to check further neighbors
                }
            }
            // If no neighbors have equal or higher health points, increment the counter
            if (!f) {
                c++;
            }
        }

        // Print the count of nodes that have no neighbors with equal or higher health points
        System.out.println(c);
    }
}
