import java.util.*;

public class Main {
    // Use fast input method
    static Scanner input = new Scanner(System.in);

    public static int bfs(int v, int N, List<List<Integer>> G, Map<Pair<Integer, Integer>, Integer> E) {
        // Initialize visited list to keep track of visited nodes
        boolean[] visited = new boolean[N];
        // Initialize a queue for BFS
        Queue<Integer> queue = new LinkedList<>();
        int K = -1;  // Variable to track the maximum color used
        // Initialize a list to store the color assigned to each node
        int[] node2color = new int[N];
        Arrays.fill(node2color, -1);
        
        // Start BFS from the given vertex 'v'
        queue.add(v);
        visited[v] = true;  // Mark the starting node as visited
        
        while (!queue.isEmpty()) {
            // Dequeue the front node
            int q = queue.poll();
            int color = 0;  // Initialize color counter for the current node
            
            // Explore all adjacent nodes
            for (int nex : G.get(q)) {
                if (visited[nex]) {
                    continue;  // Skip if the node has already been visited
                }
                
                visited[nex] = true;  // Mark the adjacent node as visited
                color++;  // Increment the color counter
                
                // Ensure the color assigned to the next node is different from the current node's color
                if (color == node2color[q]) {
                    color++;
                }
                
                // Assign the color to the adjacent node
                node2color[nex] = color;
                
                // Store the color used for the edge between the current node and the adjacent node
                E.put(new Pair<>(Math.min(q, nex), Math.max(q, nex)), color);
                
                // Enqueue the adjacent node for further exploration
                queue.add(nex);
            }
            
            // Update the maximum color used
            K = Math.max(K, color);
        }
        
        return K;  // Return the maximum color used
    }

    public static void main(String[] args) {
        // Read the number of nodes
        int N = input.nextInt();
        // Initialize the graph as a list of lists
        List<List<Integer>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }
        // Initialize a map to store edge colors
        Map<Pair<Integer, Integer>, Integer> E = new HashMap<>();
        
        // Read edges and build the graph
        for (int i = 0; i < N - 1; i++) {
            int a = input.nextInt() - 1;
            int b = input.nextInt() - 1;
            G.get(a).add(b);  // Add edge from a to b
            G.get(b).add(a);  // Add edge from b to a
            E.put(new Pair<>(a, b), 0);  // Initialize edge color to 0
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
    
    // Pair class to store edges
    static class Pair<K, V> {
        K key;
        V value;

        Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(key, pair.key) && Objects.equals(value, pair.value);
        }

        @Override
        public int hashCode() {
            return Objects.hash(key, value);
        }
    }
}

// <END-OF-CODE>
