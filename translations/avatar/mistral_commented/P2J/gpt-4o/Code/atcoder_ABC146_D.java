import java.util.*;

public class Main {
    // Function to perform Breadth First Search (BFS)
    public static int bfs(int v, int N, List<Deque<Integer>> G, Map<Pair<Integer, Integer>, Integer> E) {
        // Initialize visited array and queue
        boolean[] visited = new boolean[N];
        Deque<Integer> queue = new ArrayDeque<>();

        // Initialize variables for coloring nodes
        int K = -1;
        int[] node2color = new int[N];
        Arrays.fill(node2color, -1);

        // Add starting node to the queue and mark it as visited
        queue.add(v);
        visited[v] = true;

        // BFS algorithm
        while (!queue.isEmpty()) {
            // Dequeue the next node from the queue
            int q = queue.poll();

            // Initialize color for the current node
            int color = 0;

            // Traverse through all neighbors of the current node
            for (int nex : G.get(q)) {
                // Skip if the neighbor is already visited
                if (visited[nex]) {
                    continue;
                }

                // Mark the neighbor as visited and assign it a color
                visited[nex] = true;
                color++;

                // If the color of the current node is same as its neighbor, assign a new color to the neighbor
                if (color == node2color[q]) {
                    color++;
                }

                // Update node2color and E dictionary with the new color
                node2color[nex] = color;
                E.put(new Pair<>(Math.min(q, nex), Math.max(q, nex)), color);

                // Add the neighbor to the queue
                queue.add(nex);
            }

            // Update the maximum color found so far
            K = Math.max(K, color);
        }

        // Return the maximum color
        return K;
    }

    // Main function to read input and call bfs function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read number of nodes from the input
        int N = Integer.parseInt(scanner.nextLine());

        // Initialize graph as a list of deques and empty dictionary for edges
        List<Deque<Integer>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayDeque<>());
        }
        Map<Pair<Integer, Integer>, Integer> E = new HashMap<>();

        // Read edges from the input and add them to the graph
        for (int i = 0; i < N - 1; i++) {
            String[] input = scanner.nextLine().split(" ");
            int a = Integer.parseInt(input[0]) - 1;
            int b = Integer.parseInt(input[1]) - 1;
            G.get(a).add(b);
            G.get(b).add(a);
            E.put(new Pair<>(a, b), 0);
        }

        // Call bfs function and print the result
        int K = bfs(0, N, G, E);
        System.out.println(K);

        // Print colors of all edges
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
