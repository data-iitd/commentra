import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes (N) and edges (M) from input
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        // Initialize adjacency list for edges, degree count, parity, and visited flag
        List<Set<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new HashSet<>());
        }
        
        int[] degs = new int[N];
        int[] parity = new int[N];
        boolean[] flag = new boolean[N];
        
        // Read edges and populate the adjacency list and degree counts
        for (int i = 0; i < M; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            edges.get(a).add(b);  // Add edge from a to b
            edges.get(b).add(a);  // Add edge from b to a
            degs[a]++;             // Increment degree of node a
            degs[b]++;             // Increment degree of node b
        }
        
        // If the number of edges is odd, it's impossible to pair them
        if (M % 2 != 0) {
            System.out.println(-1);
            return;
        }
        
        // Initialize a priority queue with degrees of nodes
        PriorityQueue<int[]> Q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < N; i++) {
            Q.add(new int[]{degs[i], i});  // Append degree and node index to the queue
        }
        
        // Process the nodes in the priority queue
        while (!Q.isEmpty()) {
            int[] current = Q.poll();  // Get the node with the smallest degree
            int u = current[1];         // Node index
            
            // If the node has already been processed, skip it
            if (flag[u]) {
                continue;
            }
            
            flag[u] = true;  // Mark the node as processed
            
            // Iterate through the neighbors of the current node
            int i = 0;
            for (int v : edges.get(u)) {
                edges.get(v).remove(u);  // Remove the edge from v to u
                // Check the parity to determine the output format
                if (parity[u] != 0 && i == 0) {
                    System.out.println((u + 1) + " " + (v + 1));  // Print the edge in one format
                    parity[u] = 1 - parity[u];  // Toggle parity for u
                } else {
                    System.out.println((v + 1) + " " + (u + 1));  // Print the edge in the alternate format
                    parity[v] = 1 - parity[v];  // Toggle parity for v
                }
                
                degs[v]--;  // Decrement the degree of neighbor v
                Q.add(new int[]{degs[v], v});  // Push updated degree back to the queue
                i++;
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
