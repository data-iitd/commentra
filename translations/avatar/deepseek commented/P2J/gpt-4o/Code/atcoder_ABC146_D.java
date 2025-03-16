import java.util.*;

public class GraphColoring {
    // Function to perform Breadth-First Search (BFS) to color the graph
    public static int bfs(int v, int N, List<List<Integer>> G, Map<Pair<Integer, Integer>, Integer> E) {
        // Initialize visited list to keep track of visited nodes
        boolean[] visited = new boolean[N];
        // Initialize a queue for BFS using LinkedList
        Queue<Integer> queue = new LinkedList<>();
        // Initialize the maximum color index K
        int K = -1;
        // List to store the color of each node, initialized to -1 (no color)
        int[] node2color = new int[N];
        Arrays.fill(node2color, -1);
        // Start BFS from vertex v
        queue.add(v);
        visited[v] = true;
        while (!queue.isEmpty()) {
            // Dequeue the front node
            int q = queue.poll();
            // Initialize color for the current node
            int color = 0;
            // Iterate over all adjacent nodes
            for (int nex : G.get(q)) {
                if (visited[nex]) {
                    continue;
                }
                visited[nex] = true;
                color++;
                // Ensure the color is different from the parent node's color
                if (color == node2color[q]) {
                    color++;
                }
                // Assign the color to the node and record the edge color
                node2color[nex] = color;
                E.put(new Pair<>(Math.min(q, nex), Math.max(q, nex)), color);
                // Enqueue the adjacent node for further exploration
                queue.add(nex);
            }
            // Update the maximum color used
            K = Math.max(K, color);
        }
        return K;
    }

    // Main function to read input, construct the graph, and execute the BFS
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of nodes N
        int N = scanner.nextInt();
        // Initialize a list of lists to represent the graph
        List<List<Integer>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }
        // Initialize an empty map to store edge colors
        Map<Pair<Integer, Integer>, Integer> E = new HashMap<>();
        // Read edges to populate the graph and edge dictionary
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            G.get(a).add(b);
            G.get(b).add(a);
            E.put(new Pair<>(a, b), 0);
        }
        // Perform BFS to determine the maximum color and edge colors
        int K = bfs(0, N, G, E);
        // Print the maximum color used
        System.out.println(K);
        // Print the colors of all edges
        for (int value : E.values()) {
            System.out.println(value);
        }
        scanner.close();
    }

    // Pair class to represent edges
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
