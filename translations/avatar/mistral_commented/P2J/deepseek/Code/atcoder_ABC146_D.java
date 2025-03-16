import java.util.*;

public class Main {
    // Function to perform Breadth First Search (BFS)
    public static int bfs(int v, int N, List<List<Integer>> G, Map<String, Integer> E) {
        // Initialize visited array and queue
        boolean[] visited = new boolean[N];
        Queue<Integer> queue = new LinkedList<>();

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
                String edge = Math.min(q, nex) + "," + Math.max(q, nex);
                E.put(edge, color);

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
        int N = scanner.nextInt();

        // Initialize graph as a list of lists and empty dictionary for edges
        List<List<Integer>> G = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }
        Map<String, Integer> E = new HashMap<>();

        // Read edges from the input and add them to the graph
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            G.get(a).add(b);
            G.get(b).add(a);
            String edge = Math.min(a, b) + "," + Math.max(a, b);
            E.put(edge, 0);
        }

        // Call bfs function and print the result
        int K = bfs(0, N, G, E);
        System.out.println(K);

        // Print colors of all edges
        for (int value : E.values()) {
            System.out.println(value);
        }
    }
}
