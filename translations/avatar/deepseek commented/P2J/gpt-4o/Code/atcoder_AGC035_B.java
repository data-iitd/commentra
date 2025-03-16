import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Input Reading and Initialization
        // Read the number of nodes N and the number of edges M
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        // Initialize adjacency lists for each node
        List<Set<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edges.add(new HashSet<>());
        }
        
        // Initialize degrees for each node
        int[] degs = new int[N];
        
        // Initialize parity for each node
        int[] parity = new int[N];
        
        // Initialize flag to mark visited nodes
        boolean[] flag = new boolean[N];
        
        // Step 2: Edge and Degree Calculation
        // Read each edge and update adjacency lists and degree lists
        for (int i = 0; i < M; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            edges.get(a).add(b);
            edges.get(b).add(a);
            degs[a]++;
            degs[b]++;
        }
        
        // If the number of edges M is odd, print -1 and exit
        if (M % 2 != 0) {
            System.out.println(-1);
            return;
        }
        
        // Step 3: Heap Initialization
        // Initialize a priority queue (min-heap) with nodes based on their degrees
        PriorityQueue<int[]> Q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < N; i++) {
            Q.offer(new int[]{degs[i], i});
        }
        
        // Step 4: Main Loop
        // Process nodes from the heap
        while (!Q.isEmpty()) {
            int[] current = Q.poll();
            int u = current[1];
            
            // If the node has already been processed, skip to the next iteration
            if (flag[u]) {
                continue;
            }
            
            // Mark the node as processed
            flag[u] = true;
            
            // For each neighbor of the node, update the adjacency list and degree list
            for (int v : edges.get(u)) {
                edges.get(v).remove(u);
                
                // Print the edge in the required format, alternating the direction based on the parity
                if (parity[u] != 0) {
                    System.out.println((u + 1) + " " + (v + 1));
                    parity[u] = 1 - parity[u];
                } else {
                    System.out.println((v + 1) + " " + (u + 1));
                    parity[v] = 1 - parity[v];
                }
                
                // Update the degree and push the updated node back into the heap
                degs[v]--;
                Q.offer(new int[]{degs[v], v});
            }
        }
        
        // Step 5: Output
        // The code prints the edges in the required format, alternating the direction based on the parity
    }
}
// <END-OF-CODE>
