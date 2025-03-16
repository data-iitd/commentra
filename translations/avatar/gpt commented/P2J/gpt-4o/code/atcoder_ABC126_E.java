import java.util.*;

public class Main {
    // Define a constant for infinity
    static final long INF = (long) 1e18;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes (N) and edges (M)
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        // Initialize an adjacency list to represent the graph
        List<List<Integer>> edge = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edge.add(new ArrayList<>());
        }
        
        // Read each edge and populate the adjacency list
        for (int i = 0; i < M; i++) {
            int X = scanner.nextInt() - 1;
            int Y = scanner.nextInt() - 1;
            // Z is not used in the original code, so we ignore it
            scanner.nextInt(); 
            edge.get(X).add(Y);
            edge.get(Y).add(X);
        }
        
        // Array to track visited nodes
        boolean[] used = new boolean[N];
        
        // Variable to count the number of connected components
        int ans = 0;
        
        // Iterate through each node to find connected components
        for (int i = 0; i < N; i++) {
            if (!used[i]) {  // If the node has not been visited
                ans++;  // Increment the count of connected components
                Queue<Integer> queue = new LinkedList<>();  // Initialize a queue for BFS
                queue.add(i);  // Start BFS from the current node
                
                // Perform BFS to mark all reachable nodes from the current node
                while (!queue.isEmpty()) {
                    int node = queue.poll();  // Dequeue a node
                    used[node] = true;  // Mark the node as visited
                    
                    // Explore all adjacent nodes
                    for (int nextnode : edge.get(node)) {
                        if (!used[nextnode]) {  // If the adjacent node has not been visited
                            queue.add(nextnode);  // Enqueue the adjacent node
                        }
                    }
                }
            }
        }
        
        // Output the number of connected components found
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
