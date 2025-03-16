import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of nodes
        int N = Integer.parseInt(System.console().readLine());
        // Initialize the graph as a list of deques
        Deque<Integer>[] G = new Deque[N];
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayDeque<Integer>();
        }
        // Initialize a dictionary to store edge colors
        Map<Integer, Integer> E = new HashMap<Integer, Integer>();
        
        // Read edges and build the graph
        for (int i = 0; i < N - 1; i++) {
            String[] line = System.console().readLine().split(" ");
            int a = Integer.parseInt(line[0]) - 1;
            int b = Integer.parseInt(line[1]) - 1;
            G[a].add(b);  // Add edge from a to b
            G[b].add(a);  // Add edge from b to a
            E.put(a * N + b, 0);  // Initialize edge color to 0
            E.put(b * N + a, 0);  // Initialize edge color to 0
        }
        
        // Perform BFS starting from node 0
        int K = bfs(0, N, G, E);
        
        // Print the maximum color used
        System.out.println(K);
        // Print the colors assigned to each edge
        for (int value : E.values()) {
            System.out.println(value);
        }
    }
    
    public static int bfs(int v, int N, Deque<Integer>[] G, Map<Integer, Integer> E) {
        // Initialize visited list to keep track of visited nodes
        boolean[] visited = new boolean[N];
        // Initialize a queue for BFS
        Deque<Integer> queue = new ArrayDeque<Integer>();
        int K = -1;  // Variable to track the maximum color used
        // Initialize a list to store the color assigned to each node
        int[] node2color = new int[N];
        
        // Start BFS from the given vertex 'v'
        queue.add(v);
        visited[v] = true;  // Mark the starting node as visited
        
        while (!queue.isEmpty()) {
            // Dequeue the front node
            int q = queue.removeFirst();
            int color = 0;  // Initialize color counter for the current node
            
            // Explore all adjacent nodes
            for (int nex : G[q]) {
                if (visited[nex]) {
                    continue;  // Skip if the node has already been visited
                }
                
                visited[nex] = true;  // Mark the adjacent node as visited
                color += 1;  // Increment the color counter
                
                // Ensure the color assigned to the next node is different from the current node's color
                if (color == node2color[q]) {
                    color += 1;
                }
                
                // Assign the color to the adjacent node
                node2color[nex] = color;
                
                // Store the color used for the edge between the current node and the adjacent node
                E.put(Math.min(q, nex) * N + Math.max(q, nex), color);
                
                // Enqueue the adjacent node for further exploration
                queue.add(nex);
            }
            
            // Update the maximum color used
            K = Math.max(K, color);
        }
        
        return K;  // Return the maximum color used
    }
}

