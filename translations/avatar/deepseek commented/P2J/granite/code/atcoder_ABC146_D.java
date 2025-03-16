
import java.util.*;

// Function to perform Breadth-First Search (BFS) to color the graph
public class atcoder_ABC146_D{
    public static int bfs(int v, int N, List<List<Integer>> G, Map<String, Integer> E) {
        // Initialize visited list to keep track of visited nodes
        boolean[] visited = new boolean[N];
        // Initialize a queue for BFS using LinkedList
        Queue<Integer> queue = new LinkedList<>();
        // Initialize the maximum color index K
        int K = -1;
        // List to store the color of each node, initialized to -1 (no color)
        int[] node2color = new int[N];
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
                color += 1;
                // Ensure the color is different from the parent node's color
                if (color == node2color[q]) {
                    color += 1;
                }
                // Assign the color to the node and record the edge color
                node2color[nex] = color;
                E.put(String.format("%d %d", Math.min(q, nex), Math.max(q, nex)), color);
                // Enqueue the adjacent node for further exploration
                queue.add(nex);
            }
            // Update the maximum color used
            K = Math.max(K, color);
        }
        return K;
    }

    // atcoder_ABC146_D function to read input, construct the graph, and execute the BFS
    public static void main(String[] args) {
        // Read the number of nodes N
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        // Initialize a list of list objects to represent the graph
        List<List<Integer>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }
        // Initialize an empty map to store edge colors
        Map<String, Integer> E = new HashMap<>();
        // Read edges to populate the graph and edge map
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            G.get(a).add(b);
            G.get(b).add(a);
            E.put(String.format("%d %d", Math.min(a, b), Math.max(a, b)), 0);
        }
        // Perform BFS to determine the maximum color and edge colors
        int K = bfs(0, N, G, E);
        // Print the maximum color used
        System.out.println(K);
        // Print the colors of all edges
        for (Map.Entry<String, Integer> entry : E.entrySet()) {
            System.out.println(entry.getValue());
        }
    }
}

Translate the above Java code to C++ and end with comment "